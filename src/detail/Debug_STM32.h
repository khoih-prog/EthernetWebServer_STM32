/****************************************************************************************************************************
   Debug.h - Dead simple Ethernet web-server.
   For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

   EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

   Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
   Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
   Licensed under MIT license
   
   Original author:
   @file       Esp8266WebServer.h
   @author     Ivan Grokhotkov
   
   Version: 1.2.1

   Version Modified By   Date      Comments
   ------- -----------  ---------- -----------
    1.0.0   K Hoang      26/02/2020 Initial coding for STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) and ENC28J60
    1.0.1   K Hoang      28/02/2020 Add W5x00 Ethernet shields using Ethernet library
    1.0.2   K Hoang      05/03/2020 Remove dependency on functional-vlpp
    1.0.3   K Hoang      22/07/2020 Fix bug not closing client and releasing socket. Add features.
    1.0.4   K Hoang      23/07/2020 Add support to all STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash.
    1.0.5   K Hoang      16/09/2020 Add support to Ethernet2, Ethernet3, Ethernet Large for W5x00
                                    Add support to new EthernetENC library for ENC28J60. Add debug feature.
    1.0.6   K Hoang      24/09/2020 Add support to PROGMEM-related commands, such as sendContent_P() and send_P()
    1.1.0   K Hoang      17/11/2020 Add basic HTTP and WebSockets Client by merging ArduinoHttpClient
    1.1.1   K Hoang      26/12/2020 Suppress all possible compiler warnings. Add Version String
    1.2.0   K Hoang      11/04/2021 Add support to LAN8720 using STM32F4 or STM32F7
    1.2.1   K Hoang      04/10/2021 Change option for PIO `lib_compat_mode` from default `soft` to `strict`. Update Packages Patches
 *************************************************************************************************************************************/

#pragma once

#include <stdio.h>

#ifdef DEBUG_ETHERNET_WEBSERVER_PORT
#define ET_DEBUG_OUTPUT DEBUG_ETHERNET_WEBSERVER_PORT
#else
#define ET_DEBUG_OUTPUT Serial
#endif

// Change _ETHERNET_WEBSERVER_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug

#ifndef _ETHERNET_WEBSERVER_LOGLEVEL_
#define _ETHERNET_WEBSERVER_LOGLEVEL_       1
#endif

///////////////////////////////////////

#define ET_LOGERROR(x)         if(_ETHERNET_WEBSERVER_LOGLEVEL_>0) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.println(x); }
#define ET_LOGERROR0(x)        if(_ETHERNET_WEBSERVER_LOGLEVEL_>0) { ET_DEBUG_OUTPUT.print(x); }
#define ET_LOGERROR1(x,y)      if(_ETHERNET_WEBSERVER_LOGLEVEL_>0) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.print(x); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.println(y); }
#define ET_LOGERROR2(x,y,z)    if(_ETHERNET_WEBSERVER_LOGLEVEL_>0) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.print(x); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.print(y); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.println(z); }
#define ET_LOGERROR3(x,y,z,w)  if(_ETHERNET_WEBSERVER_LOGLEVEL_>0) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.print(x); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.print(y); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.print(z); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.println(w); }

///////////////////////////////////////

#define ET_LOGWARN(x)          if(_ETHERNET_WEBSERVER_LOGLEVEL_>1) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.println(x); }
#define ET_LOGWARN0(x)         if(_ETHERNET_WEBSERVER_LOGLEVEL_>1) { ET_DEBUG_OUTPUT.print(x); }
#define ET_LOGWARN1(x,y)       if(_ETHERNET_WEBSERVER_LOGLEVEL_>1) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.print(x); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.println(y); }
#define ET_LOGWARN2(x,y,z)     if(_ETHERNET_WEBSERVER_LOGLEVEL_>1) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.print(x); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.print(y); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.println(z); }
#define ET_LOGWARN3(x,y,z,w)   if(_ETHERNET_WEBSERVER_LOGLEVEL_>1) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.print(x); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.print(y); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.print(z); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.println(w); }

///////////////////////////////////////

#define ET_LOGINFO(x)          if(_ETHERNET_WEBSERVER_LOGLEVEL_>2) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.println(x); }
#define ET_LOGINFO0(x)         if(_ETHERNET_WEBSERVER_LOGLEVEL_>2) { ET_DEBUG_OUTPUT.print(x); }
#define ET_LOGINFO1(x,y)       if(_ETHERNET_WEBSERVER_LOGLEVEL_>2) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.print(x); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.println(y); }
#define ET_LOGINFO2(x,y,z)     if(_ETHERNET_WEBSERVER_LOGLEVEL_>2) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.print(x); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.print(y); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.println(z); }
#define ET_LOGINFO3(x,y,z,w)   if(_ETHERNET_WEBSERVER_LOGLEVEL_>2) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.print(x); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.print(y); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.print(z); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.println(w); }

///////////////////////////////////////

#define ET_LOGDEBUG(x)         if(_ETHERNET_WEBSERVER_LOGLEVEL_>3) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.println(x); }
#define ET_LOGDEBUG0(x)        if(_ETHERNET_WEBSERVER_LOGLEVEL_>3) { ET_DEBUG_OUTPUT.print(x); }
#define ET_LOGDEBUG1(x,y)      if(_ETHERNET_WEBSERVER_LOGLEVEL_>3) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.print(x); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.println(y); }
#define ET_LOGDEBUG2(x,y,z)    if(_ETHERNET_WEBSERVER_LOGLEVEL_>3) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.print(x); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.print(y); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.println(z); }
#define ET_LOGDEBUG3(x,y,z,w)  if(_ETHERNET_WEBSERVER_LOGLEVEL_>3) { ET_DEBUG_OUTPUT.print("[ETHERNET_WEBSERVER] "); ET_DEBUG_OUTPUT.print(x); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.print(y); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.print(z); ET_DEBUG_OUTPUT.print(" "); ET_DEBUG_OUTPUT.println(w); }

