/****************************************************************************************************************************
    UdpNTPClient.ino - Simple Arduino web server sample for ESP8266 AT-command shield
    For STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc)

    EthernetWebServer_STM32 is a library for the STM32 run built-in Ethernet WebServer

    Forked and modified from ESP8266 https://github.com/esp8266/Arduino/releases
    Built by Khoi Hoang https://github.com/khoih-prog/ESP8266_AT_WebServer
    Licensed under MIT license
    Version: 1.0.3

    Copyright (c) 2015, Majenko Technologies
    All rights reserved.

    Redistribution and use in source and binary forms, with or without modification,
    are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

    Redistributions in binary form must reproduce the above copyright notice, this
    list of conditions and the following disclaimer in the documentation and/or
    other materials provided with the distribution.

    Neither the name of Majenko Technologies nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
    ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

   Original author:
   @file       Esp8266WebServer.h
   @author     Ivan Grokhotkov

   Version Modified By   Date      Comments
   ------- -----------  ---------- -----------
    1.0.0   K Hoang      26/02/2020 Initial coding for STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) and ENC28J60
    1.0.1   K Hoang      28/02/2020 Add W5x00 Ethernet shields using Ethernet library
    1.0.2   K Hoang      05/03/2020 Remove dependency on functional-vlpp
    1.0.3   K Hoang      22/07/2020 Fix bug not closing client & releasing socket. Add features & dependency on functional-vlpp
 *****************************************************************************************************************************/

#include "defines.h"

char timeServer[]         = "time.nist.gov";  // NTP server
unsigned int localPort    = 2390;             // local port to listen for UDP packets

const int NTP_PACKET_SIZE = 48;       // NTP timestamp is in the first 48 bytes of the message
const int UDP_TIMEOUT     = 2000;     // timeout in miliseconds to wait for an UDP packet to arrive

byte packetBuffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

// send an NTP request to the time server at the given address
void sendNTPpacket(char *ntpSrv)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)

  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(ntpSrv, 123); //NTP requests are to port 123

  Udp.write(packetBuffer, NTP_PACKET_SIZE);

  Udp.endPacket();
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.println("\nStart UdpNTPClient on " + String(BOARD_NAME) + " board, running " + String(ETHERNET_NAME));

  // start the ethernet connection and the server
  // Use random mac
  srand(1);
  uint16_t index = rand() % NUMBER_OF_MAC;
  //uint16_t index = random(NUMBER_OF_MAC);

  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  // Use DHCP dynamic IP and random mac
  Ethernet.begin(mac[index]);

  // you're connected now, so print out the data
  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(Ethernet.localIP());

  Udp.begin(localPort);
}

void loop()
{
  sendNTPpacket(timeServer); // send an NTP packet to a time server

  // wait for a reply for UDP_TIMEOUT miliseconds
  unsigned long startMs = millis();
  while (!Udp.available() && (millis() - startMs) < UDP_TIMEOUT) {}

  // if there's data available, read a packet
  int packetSize = Udp.parsePacket();

  if (packetSize)
  {
    Serial.print(F("UDP Packet received, size "));
    Serial.println(packetSize);
    Serial.print(F("From "));
    IPAddress remoteIp = Udp.remoteIP();
    Serial.print(remoteIp);
    Serial.print(F(", port "));
    Serial.println(Udp.remotePort());
    
    // We've received a packet, read the data from it into the buffer
    Udp.read(packetBuffer, NTP_PACKET_SIZE);

    // the timestamp starts at byte 40 of the received packet and is four bytes,
    // or two words, long. First, esxtract the two words:

    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);

    // combine the four bytes (two words) into a long integer
    // this is NTP time (seconds since Jan 1 1900):
    unsigned long secsSince1900 = highWord << 16 | lowWord;
    Serial.print(F("Seconds since Jan 1 1900 = "));
    Serial.println(secsSince1900);

    // now convert NTP time into )everyday time:
    Serial.print(F("Unix time = "));
    // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
    const unsigned long seventyYears = 2208988800UL;
    // subtract seventy years:
    unsigned long epoch = secsSince1900 - seventyYears;
    // print Unix time:
    Serial.println(epoch);

    // print the hour, minute and second:
    Serial.print(F("The UTC time is "));       // UTC is the time at Greenwich Meridian (GMT)
    Serial.print((epoch  % 86400L) / 3600); // print the hour (86400 equals secs per day)
    Serial.print(F(":"));
    if (((epoch % 3600) / 60) < 10) {
      // In the first 10 minutes of each hour, we'll want a leading '0'
      Serial.print(F("0"));
    }
    Serial.print((epoch  % 3600) / 60); // print the minute (3600 equals secs per minute)
    Serial.print(F(":"));
    if ((epoch % 60) < 10) {
      // In the first 10 seconds of each minute, we'll want a leading '0'
      Serial.print(F("0"));
    }
    Serial.println(epoch % 60); // print the second
  }
  // wait ten seconds before asking for the time again
  delay(10000);
}