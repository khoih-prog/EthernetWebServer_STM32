/****************************************************************************************************************************
  WebServer_LAN8720.ino - Simple Arduino web server sample for ESP8266 AT-command shield
  For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

  EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
  Licensed under MIT license
 *****************************************************************************************************************************/
/*
   Currently support
   1) STM32 boards with built-in LAN8742A Ethernet (to use USE_BUILTIN_ETHERNET = true) such as :
      - Nucleo-144 (F429ZI, F767ZI)
      - Discovery (STM32F746G-DISCOVERY)
      - STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash, with Built-in Ethernet, 
      - See How To Use Built-in Ethernet at (https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
   2) STM32 boards with LAN8720 Ethernet (to use USE_BUILTIN_ETHERNET and USING_LAN8720 = true) such as :
      - BLACK_F407XX (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE-mini), NUCLEO_F429ZI, DISCO_F746NG,
        NUCLEO_F7x6ZG
   3) STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running ENC28J60 shields (to use USE_BUILTIN_ETHERNET = false)
   4) STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running W5x00 shields
*/

#include "defines.h"

int reqCount = 0;                // number of requests received

EthernetServer server(80);

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  
  delay(2000);

  Serial.println("\nStart WebServer_LAN8720 on " + String(BOARD_NAME) + ", using " + String(SHIELD_TYPE));
  Serial.println(ETHERNET_WEBSERVER_STM32_VERSION);

  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  // you're connected now, so print out the data
  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(Ethernet.localIP());

  // start the web server on port 80
  server.begin();
}


void loop()
{
  // listen for incoming clients
  EthernetClient client = server.available();

  if (client)
  {
    Serial.println(F("New client"));
    // an http request ends with a blank line
    bool currentLineIsBlank = true;

    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank)
        {
          Serial.println(F("Sending response"));

          // send a standard http response header
          // use \r\n instead of many println statements to speedup data send
          client.print(
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Connection: close\r\n"  // the connection will be closed after completion of the response
            "Refresh: 20\r\n"        // refresh the page automatically every 20 sec
            "\r\n");
          client.print("<!DOCTYPE HTML>\r\n");
          client.print("<html>\r\n");
          client.print(String("<h1>Hello World from ") + BOARD_NAME + " and LAN8720!</h1>\r\n");
          client.print("<h1>Hello World from ");
          client.print(BOARD_NAME);
          client.print(" and LAN8720!</h1>\r\n");
          client.print("Requests received: ");
          client.print(++reqCount);
          client.print("<br>\r\n");
          client.print("Analog input A0: ");
          client.print(analogRead(0));
          client.print("<br>\r\n");
          client.print("</html>\r\n");
          break;
        }

        if (c == '\n')
        {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r')
        {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(10);

    // close the connection:
    client.stop();
    Serial.println(F("Client disconnected"));
  }
}
