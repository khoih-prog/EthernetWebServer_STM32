/****************************************************************************************************************************
  defines.h

  For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

  EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
  Licensed under MIT license
 ***************************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if !( defined(ARDUINO_BLACK_F407VE) || defined(ARDUINO_BLACK_F407VG) || defined(ARDUINO_BLACK_F407ZE) || defined(ARDUINO_BLACK_F407ZG)  || \
       defined(ARDUINO_BLUE_F407VE_Mini) || defined(ARDUINO_DIYMORE_F407VGT) || defined(ARDUINO_FK407M1) || defined(ARDUINO_NUCLEO_F429ZI) || \
       defined(ARDUINO_DISCO_F746NG) || defined(ARDUINO_NUCLEO_F746ZG) || defined(ARDUINO_NUCLEO_F756ZG) || defined(ARDUINO_NUCLEO_H743ZI) )
  #error This code is designed to run on some STM32F407XX NUCLEO-F429ZI, STM32F746 and STM32F756 platform! Please check your Tools->Board setting.
#endif

#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       2

#define USING_LAN8720           true

// If USE_BUILTIN_ETHERNET == false and USE_UIP_ETHERNET == false => 
// either use W5x00 with EthernetXYZ library
// or ENC28J60 with EthernetENC library
#define USE_BUILTIN_ETHERNET    true
//#define USE_BUILTIN_ETHERNET    false

//#define USE_UIP_ETHERNET        true
#define USE_UIP_ETHERNET        false

// To override the default CS/SS pin. Don't use unless you know exactly which pin to use
// You can define here or customize for each board at same place with BOARD_TYPE
//#define USE_THIS_SS_PIN   22  //21  //5 //4 //2 //15
// Default pin 10 to SS/CS. To change according to your board, if necessary
#define USE_THIS_SS_PIN       10

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  // Only one if the following to be true
  #define USE_ETHERNET_GENERIC  true
  #define USE_ETHERNET_ESP8266  false 
  #define USE_ETHERNET_ENC      false
  #define USE_CUSTOM_ETHERNET   false
#endif

#if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ESP8266 || USE_ETHERNET_ENC )
  #ifdef USE_CUSTOM_ETHERNET
    #undef USE_CUSTOM_ETHERNET
  #endif
  #define USE_CUSTOM_ETHERNET   false //true
#endif

#if (USE_BUILTIN_ETHERNET)
  #if USING_LAN8720
    #warning Using LAN8720A Ethernet & STM32Ethernet lib
    #define SHIELD_TYPE           "LAN8720 Ethernet & STM32Ethernet Library"
  #else
    #warning Using LAN8742A Ethernet & STM32Ethernet lib
    #define SHIELD_TYPE           "LAN8742A Ethernet & STM32Ethernet Library"
  #endif
#elif (USE_UIP_ETHERNET)
  #warning Using ENC28J60 & UIPEthernet lib
  #define SHIELD_TYPE           "ENC28J60 & UIPEthernet Library"
#elif USE_ETHERNET_GENERIC
  #include "Ethernet_Generic.h"

  #define ETHERNET_LARGE_BUFFERS

  #define _ETG_LOGLEVEL_                      1
      
  #warning Using W5x00 & Ethernet_Generic lib
  #define SHIELD_TYPE           "W5x00 using Ethernet_Generic Library"  
#elif USE_ETHERNET_ESP8266
  #include "Ethernet_ESP8266.h"
  #warning Using W5x00 & Ethernet_ESP8266 lib 
  #define SHIELD_TYPE           "W5x00 & Ethernet_ESP8266 Library" 
#elif USE_ETHERNET_ENC
  #include "EthernetENC.h"
  #warning Using ENC28J60 & EthernetENC lib
  #define SHIELD_TYPE           "ENC28J60 & EthernetENC Library"
#elif USE_CUSTOM_ETHERNET
  //#include "Ethernet_XYZ.h"
  #include "EthernetENC.h"
  #warning Using Custom Ethernet library. You must include a library and initialize.
  #define SHIELD_TYPE           "Custom Ethernet & Ethernet_XYZ Library"
#else
   #define USE_ETHERNET_GENERIC   true
  #include "Ethernet_Generic.h"
  #warning Using default Ethernet_Generic lib
  #define SHIELD_TYPE           "W5x00 using default Ethernet_Generic Library"
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
IPAddress ip(192, 168, 2, 220);

#endif    //defines_h
