/****************************************************************************************************************************
  EthernetWebServer_STM32.h - Dead simple web-server.
  For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

  EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
  Licensed under MIT license

  Original author:
  @file       Esp8266WebServer.h
  @author     Ivan Grokhotkov

  Version: 1.5.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      26/02/2020 Initial coding for STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) and ENC28J60
  ...
  1.3.0   K Hoang      20/12/2021 Reduce usage of Arduino String with std::string. Use reference passing instead of value-passing
  1.3.1   K Hoang      25/12/2021 Fix bug
  1.3.2   K Hoang      28/12/2021 Fix wrong http status header bug and authenticate issue caused by libb64
  1.3.3   K Hoang      11/01/2022 Fix libb64 fallthrough compile warning
  1.3.4   K Hoang      02/03/2022 Fix decoding error bug
  1.4.0   K Hoang      04/04/2022 Use Ethernet_Generic library as default for W5x00 Ethernet
  1.4.1   K Hoang      27/04/2022 Change from `arduino.cc` to `arduino.tips` in examples
  1.5.0   K Hoang      04/04/2022 Add support to custom SPI, such as SPI2, SPI3, SPI_New, etc.
 *************************************************************************************************************************************/

#pragma once

#ifndef ETHERNET_WEBSERVER_STM32_H
#define ETHERNET_WEBSERVER_STM32_H

#if ( USE_BUILTIN_ETHERNET && USING_LAN8720 )

  #if !( defined(ARDUINO_BLACK_F407VE)     || defined(ARDUINO_BLACK_F407VG)     || defined(ARDUINO_BLACK_F407ZE)     || defined(ARDUINO_BLACK_F407ZG)       || \
         defined(ARDUINO_BLUE_F407VE_Mini) || defined(ARDUINO_DIYMORE_F407VGT)  || defined(ARDUINO_FK407M1)          || defined(ARDUINO_VCCGND_F407ZG_MINI) || \
         defined(ARDUINO_GENERIC_F407VETX) || defined(ARDUINO_GENERIC_F407VGTX) || defined(ARDUINO_GENERIC_F407ZETX) || defined(ARDUINO_GENERIC_F407ZGTX)   || \
         defined(ARDUINO_GENERIC_F417VETX) || defined(ARDUINO_GENERIC_F417VGTX) || defined(ARDUINO_GENERIC_F417ZETX) || defined(ARDUINO_GENERIC_F417ZGTX)   || \
         defined(ARDUINO_GENERIC_F427ZGTX) || defined(ARDUINO_GENERIC_F427ZITX) || defined(ARDUINO_GENERIC_F429ZETX) || defined(ARDUINO_GENERIC_F429ZGTX)   || \
         defined(ARDUINO_GENERIC_F429ZGYX) || defined(ARDUINO_GENERIC_F429ZITX) || defined(ARDUINO_GENERIC_F429ZIYX) || defined(ARDUINO_GENERIC_F437ZGTX)   || \
         defined(ARDUINO_GENERIC_F437ZITX) || defined(ARDUINO_GENERIC_F439ZGTX) || defined(ARDUINO_GENERIC_F439ZITX) || defined(ARDUINO_GENERIC_F439ZGYX)   || \
         defined(ARDUINO_GENERIC_F439ZIYX) || defined(ARDUINO_DISCO_F746NG)     || defined(ARDUINO_NUCLEO_F746ZG)    || defined(ARDUINO_NUCLEO_F756ZG)      || \
         defined(ARDUINO_NUCLEO_H743ZI) )
    #error This code is designed to run on some STM32F4X7XX, STM32F4X9XX NUCLEO-F429ZI, STM32F74X, STM32F756, STM32F76X and STM32F77X platforms! Please check your Tools->Board setting.
  #endif

#elif ( USE_BUILTIN_ETHERNET )

  #if !( defined(STM32F0) || defined(STM32F1)  || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
         defined(STM32L0) || defined(STM32L1)  || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
         defined(STM32WB) || defined(STM32MP1) || defined(STM32L5) )
   #error This code is designed to run on STM32F/L/H/G/WB/MP1 platform! Please check your Tools->Board setting.
  #endif
  
#endif

/////////////////////////////////////////////////////////////////////////

#define ETHERNET_WEBSERVER_STM32_VERSION            "EthernetWebServer_STM32 v1.5.0"

#define ETHERNET_WEBSERVER_STM32_VERSION_MAJOR      1
#define ETHERNET_WEBSERVER_STM32_VERSION_MINOR      5
#define ETHERNET_WEBSERVER_STM32_VERSION_PATCH      0

#define ETHERNET_WEBSERVER_STM32_VERSION_INT        1005000

/////////////////////////////////////////////////////////////////////////

#if USE_BUILTIN_ETHERNET
  #if USING_LAN8720
    #warning Using built-in LAN8720 Ethernet with STM32Ethernet library from EthernetWebServer_STM32
  #else
    #warning Using built-in LAN8742A Ethernet with STM32Ethernet library from EthernetWebServer_STM32
  #endif
#elif USE_UIP_ETHERNET
  #warning Using ENC28J60 Ethernet shield with UIPEthernet library from EthernetWebServer_STM32
#elif USE_CUSTOM_ETHERNET
	#warning Using Custom Ethernet library from EthernetWebServer_STM32. You must include a library or error
#elif !( USE_ETHERNET_GENERIC || USE_ETHERNET_ESP8266 || USE_ETHERNET_ENC )  
  #include <Ethernet_Generic.h>
  #warning Using Ethernet_Generic library from EthernetWebServer_STM32
#endif

#include "EthernetWebServer_STM32.hpp"
#include "EthernetWebServer_STM32-impl.h"
#include "Parsing_STM32-impl.h"

/////////////////////////////////////////////////////////////////////////

#endif		// ETHERNET_WEBSERVER_STM32_H
