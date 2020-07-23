/****************************************************************************************************************************
    WebClient.ino - Simple Arduino web server sample for ESP8266 AT-command shield
    For STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc)

    EthernetWebServer_STM32 is a library for the STM32 run built-in Ethernet WebServer

    Forked and modified from ESP8266 https://github.com/esp8266/Arduino/releases
    Built by Khoi Hoang https://github.com/khoih-prog/ESP8266_AT_WebServer
    Licensed under MIT license
    Version: 1.0.3

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

char server[] = "arduino.cc";

// Initialize the Web client object
EthernetClient client;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial);

  Serial.println("\nStart WebClient on " + String(BOARD_NAME) + " board, running " + String(ETHERNET_NAME));

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

  Serial.println();
  Serial.println(F("Starting connection to server..."));

  // if you get a connection, report back via serial
  if (client.connect(server, 80))
  {
    Serial.println(F("Connected to server"));
    // Make a HTTP request
    client.println(F("GET /asciilogo.txt HTTP/1.1"));
    client.println(F("Host: arduino.cc"));
    client.println(F("Connection: close"));
    client.println();
  }
}

void printoutData(void)
{
  // if there are incoming bytes available
  // from the server, read them and print them
  while (client.available())
  {
    char c = client.read();
    Serial.write(c);
  }
}

void loop()
{
  printoutData();

  // if the server's disconnected, stop the client
  if (!client.connected())
  {
    Serial.println();
    Serial.println(F("Disconnecting from server..."));
    client.stop();

    // do nothing forevermore
    while (true);
  }
}
