/****************************************************************************************************************************
    HelloServer2.h - Dead simple web-server for Ethernet shields
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
/*
   Currently support
   1) STM32 boards with built-in Ethernet (to use USE_BUILTIN_ETHERNET = true) such as :
      - Nucleo-144 (F429ZI, F767ZI)
      - Discovery (STM32F746G-DISCOVERY)
      - STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash, with Built-in Ethernet, 
      - See How To Use Built-in Ethernet at (https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
   2) STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running ENC28J60 shields (to use USE_BUILTIN_ETHERNET = false)
   3) STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running W5x00 shields
*/

#if !( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
       defined(STM32L0) || defined(STM32L1) || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
       defined(STM32WB) || defined(STM32MP1) )
#error This code is designed to run on STM32F/L/H/G/WB/MP1 platform! Please check your Tools->Board setting.
#endif

#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       1

#define USE_BUILTIN_ETHERNET    false
//  If don't use USE_BUILTIN_ETHERNET, and USE_UIP_ETHERNET => use W5x00 with Ethernet library
#define USE_UIP_ETHERNET        false  //false 

#if (USE_BUILTIN_ETHERNET)
#define ETHERNET_NAME     "Built-in LAN8742A Ethernet"
#elif (USE_UIP_ETHERNET)
#define ETHERNET_NAME     "ENC28J60 Ethernet Shield"
#else
#define ETHERNET_NAME     "W5x00 Ethernet Shield"
#endif

#if defined(STM32F0)
#warning STM32F0 board selected
#define BOARD_TYPE  "STM32F0"
#elif defined(STM32F1)
#warning STM32F1 board selected
#define BOARD_TYPE  "STM32F1"
#elif defined(STM32F2)
#warning STM32F2 board selected
#define BOARD_TYPE  "STM32F2"
#elif defined(STM32F3)
#warning STM32F3 board selected
#define BOARD_TYPE  "STM32F3"
#elif defined(STM32F4)
#warning STM32F4 board selected
#define BOARD_TYPE  "STM32F4"
#elif defined(STM32F7)
#warning STM32F7 board selected
#define BOARD_TYPE  "STM32F7"
#elif defined(STM32L0)
#warning STM32L0 board selected
#define BOARD_TYPE  "STM32L0"
#elif defined(STM32L1)
#warning STM32L1 board selected
#define BOARD_TYPE  "STM32L1"
#elif defined(STM32L4)
#warning STM32L4 board selected
#define BOARD_TYPE  "STM32L4"
#elif defined(STM32H7)
#warning STM32H7 board selected
#define BOARD_TYPE  "STM32H7"
#elif defined(STM32G0)
#warning STM32G0 board selected
#define BOARD_TYPE  "STM32G0"
#elif defined(STM32G4)
#warning STM32G4 board selected
#define BOARD_TYPE  "STM32G4"
#elif defined(STM32WB)
#warning STM32WB board selected
#define BOARD_TYPE  "STM32WB"
#elif defined(STM32MP1)
#warning STM32MP1 board selected
#define BOARD_TYPE  "STM32MP1"
#else
#warning STM32 unknown board selected
#define BOARD_TYPE  "STM32 Unknown"
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif


#include <EthernetWebServer_STM32.h>

// Enter a MAC address and IP address for your controller below.
#define NUMBER_OF_MAC      20

byte mac[][NUMBER_OF_MAC] =
{
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x01 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x02 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x03 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x04 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x05 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x06 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x07 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x08 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x09 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0A },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0B },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0C },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0D },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0E },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0F },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x10 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x11 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x12 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x13 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x14 },
};
// Select the IP address according to your local network
IPAddress ip(192, 168, 2, 232);

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
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void)
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);

  delay(1000);
  Serial.println("\nStart HelloServer2 on " + String(BOARD_NAME) + " board, running " + String(ETHERNET_NAME));

  // start the ethernet connection and the server
  // Use random mac
  srand(1);
  uint16_t index = rand() % NUMBER_OF_MAC;
  //uint16_t index = random(NUMBER_OF_MAC);

  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  // Use DHCP dynamic IP and random mac
  Ethernet.begin(mac[index]);

  server.on("/", handleRoot);

  server.on("/inline", []() {
    server.send(200, "text/plain", "This works as well");
  });

  server.on("/gif", []() {
    static const uint8_t gif[] = {
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

void loop(void)
{
  server.handleClient();
}
