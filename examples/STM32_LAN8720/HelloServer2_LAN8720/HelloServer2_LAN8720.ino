/****************************************************************************************************************************
  HelloServer2_LAN8720.h - Dead simple web-server for Ethernet shields
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

EthernetWebServer server(80);

void handleRoot()
{
  server.send(200, "text/plain", String("Hello from EthernetWebServer on ") + BOARD_NAME);
}

void handleNotFound()
{
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++)
  {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
}

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);

  delay(2000);

  Serial.println("\nStart HelloServer2_LAN8720 on " + String(BOARD_NAME) + ", using " + String(SHIELD_TYPE));
  Serial.println(ETHERNET_WEBSERVER_STM32_VERSION);

  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  Serial.print(F("Connected! IP address: "));
  Serial.println(Ethernet.localIP());

  server.on("/", handleRoot);

  server.on("/inline", []()
  {
    server.send(200, "text/plain", "This works as well");
  });

  server.on("/gif", []()
  {
    static const uint8_t gif[] =
    {
      0x47, 0x49, 0x46, 0x38, 0x37, 0x61, 0x10, 0x00, 0x10, 0x00, 0x80, 0x01,
      0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x2c, 0x00, 0x00, 0x00, 0x00,
      0x10, 0x00, 0x10, 0x00, 0x00, 0x02, 0x19, 0x8c, 0x8f, 0xa9, 0xcb, 0x9d,
      0x00, 0x5f, 0x74, 0xb4, 0x56, 0xb0, 0xb0, 0xd2, 0xf2, 0x35, 0x1e, 0x4c,
      0x0c, 0x24, 0x5a, 0xe6, 0x89, 0xa6, 0x4d, 0x01, 0x00, 0x3b
    };
    char gif_colored[sizeof(gif)];

    memcpy(gif_colored, gif, sizeof(gif));

    // Set the background to a random set of colors
    gif_colored[16] = millis() % 256;
    gif_colored[17] = millis() % 256;
    gif_colored[18] = millis() % 256;

    server.send(200, (char *) "image/gif", gif_colored, sizeof(gif_colored));
  });

  server.onNotFound(handleNotFound);

  server.begin();

  Serial.print("HTTP EthernetWebServer started @ IP : ");
  Serial.println(Ethernet.localIP());
}

void loop()
{
  server.handleClient();
}
