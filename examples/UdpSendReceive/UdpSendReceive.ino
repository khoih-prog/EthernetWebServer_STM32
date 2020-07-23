/****************************************************************************************************************************
    UDPSendReceive.ino - Simple Arduino web server sample for ESP8266/ESP32 AT-command shield
    For STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 Ethernet
    
    EthernetWebServer_STM32 is a library for the STM32 run built-in Ethernet WebServer

    Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
    Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
    Licensed under MIT license
    
    Original author:
    @file       Esp8266WebServer.h
    @author     Ivan Grokhotkov
    
    Version: 1.0.4
    
    Version Modified By   Date      Comments
    ------- -----------  ---------- -----------
    1.0.0   K Hoang      26/02/2020 Initial coding for STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) and ENC28J60
    1.0.1   K Hoang      28/02/2020 Add W5x00 Ethernet shields using Ethernet library
    1.0.2   K Hoang      05/03/2020 Remove dependency on functional-vlpp
    1.0.3   K Hoang      22/07/2020 Fix bug not closing client and releasing socket. Add features.
    1.0.4   K Hoang      23/07/2020 Add support to all STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash.
 *****************************************************************************************************************************/

#include "defines.h"

unsigned int localPort = 1883;    //10002;  // local port to listen on

char packetBuffer[255];          // buffer to hold incoming packet
char ReplyBuffer[] = "ACK";      // a string to send back

// A UDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.println("\nStart UDPSendReceive on " + String(BOARD_NAME) + " board, running " + String(ETHERNET_NAME));

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

  Serial.println(F("\nStarting connection to server..."));
  // if you get a connection, report back via serial:
  Udp.begin(localPort);

  Serial.print(F("Listening on port "));
  Serial.println(localPort);
}

void loop()
{
  // if there's data available, read a packet
  int packetSize = Udp.parsePacket();

  if (packetSize)
  {
    Serial.print(F("Received packet of size "));
    Serial.println(packetSize);
    Serial.print(F("From "));
    IPAddress remoteIp = Udp.remoteIP();
    Serial.print(remoteIp);
    Serial.print(F(", port "));
    Serial.println(Udp.remotePort());

    // read the packet into packetBufffer
    int len = Udp.read(packetBuffer, 255);
    if (len > 0)
    {
      packetBuffer[len] = 0;
    }

    Serial.println(F("Contents:"));
    Serial.println(packetBuffer);

    // send a reply, to the IP address and port that sent us the packet we received
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(ReplyBuffer);
    Udp.endPacket();
  }
}
