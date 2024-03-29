/****************************************************************************************************************************
  HTTPBasicAuth_LAN8720.h - Dead simple web-server for Ethernet shields
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

const char* www_username = "admin";
const char* www_password = "ethernet";

void setup()
{
  Serial.begin(115200);
  delay(2000);

  Serial.println("\nStart HTTPBasicAuth_LAN8720 on " + String(BOARD_NAME) + ", using " + String(SHIELD_TYPE));
  Serial.println(ETHERNET_WEBSERVER_STM32_VERSION);

  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  Serial.print(F("Connected! IP address: "));
  Serial.println(Ethernet.localIP());

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

  Serial.print(F("Login using username = "));
  Serial.print(www_username);
  Serial.print(F(" and password = "));
  Serial.println(www_password);
}

void loop()
{
  server.handleClient();
}
