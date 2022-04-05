/****************************************************************************************************************************
  multiFileProject.h
  For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

  EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
  Licensed under MIT license
*****************************************************************************************************************************/

// To demo how to include files in multi-file Projects

#pragma once

#define _ETHERNET_WEBSERVER_LOGLEVEL_       1

// Can be included as many times as necessary, without `Multiple Definitions` Linker Error
#include <EthernetWebServer_STM32.hpp>      // https://github.com/khoih-prog/EthernetWebServer_STM32

#include <EthernetHttpClient_STM32.h>       // https://github.com/khoih-prog/EthernetWebServer_STM32
