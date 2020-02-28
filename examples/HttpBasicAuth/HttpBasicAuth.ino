/****************************************************************************************************************************
 * HTTPBasicAuth.h - Dead simple web-server for Ethernet shields
 *
 * For STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc)
 *
 * EthernetWebServer_STM32 is a library for the STM32 run built-in Ethernet WebServer
 *
 * Forked and modified from ESP8266 https://github.com/esp8266/Arduino/releases
 * Built by Khoi Hoang https://github.com/khoih-prog/ESP8266_AT_WebServer
 * Licensed under MIT license
  * Version: 1.0.1
 *
 * Original author:
 * @file       Esp8266WebServer.h
 * @author     Ivan Grokhotkov
 *
 * Version Modified By   Date      Comments
 * ------- -----------  ---------- -----------
 *  1.0.0   K Hoang      26/02/2020 Initial coding for STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) and ENC28J60
 *  1.0.1   K Hoang      28/02/2020 Add W5x00 Ethernet shields using Ethernet library
 *****************************************************************************************************************************/
/*
 * Currently support 
 * 1) STM32 boards with built-in Ethernet (to use USE_BUILTIN_ETHERNET = true) such as :
 *    - Nucleo-144 (F429ZI, F767ZI)
 *    - Discovery (STM32F746G-DISCOVERY)
 *    - All STM32 Boards with Built-in Ethernet, See How To Use Built-in Ethernet at (https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
 * 2) STM32 boards (with 64+K Flash) running EMC28J60 shields (to use USE_BUILTIN_ETHERNET = false)
 * 3) STM32 boards (with 32+K Flash) running W5x00 Ethernet shields
 * 
 */

#define USE_BUILTIN_ETHERNET    false    //true
//  If don't use USE_BUILTIN_ETHERNET, and USE_UIP_ETHERNET => use W5x00 with Ethernet library
#define USE_UIP_ETHERNET        false 

#include <EthernetWebServer_STM32.h>

// Enter a MAC address and IP address for your controller below.

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

// Select the IP address according to your local network
IPAddress ip(192, 168, 2, 200);

EthernetWebServer server(80);

const char* www_username = "admin";
const char* www_password = "ethernet";

void setup() 
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nStarting HTTPBasicAuth");

  // start the ethernet connection and the server:
  Ethernet.begin(mac, ip);

  server.on("/", []() 
  {
    if (!server.authenticate(www_username, www_password)) 
    {
      return server.requestAuthentication();
    }
    server.send(200, "text/plain", "Login OK");
  });
  
  server.begin();

  Serial.print(F("HTTP EthernetWebServer started @ IP : "));
  Serial.println(Ethernet.localIP());

  Serial.print(F("Open http://"));
  Serial.print(Ethernet.localIP());
  Serial.println(F("/ in your browser to see it working"));
}

void loop() 
{
   server.handleClient();
}
