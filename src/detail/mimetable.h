/****************************************************************************************************************************
  mimetable.h - Dead simple web-server.
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

#ifndef __MIMETABLE_H__
#define __MIMETABLE_H__

namespace mime
{

  enum type
  {
    html,
    htm,
    css,
    txt,
    js,
    json,
    png,
    gif,
    jpg,
    ico,
    svg,
    ttf,
    otf,
    woff,
    woff2,
    eot,
    sfnt,
    xml,
    pdf,
    zip,
    gz,
    appcache,
    none,
    maxType
  };

  struct Entry
  {
    const char endsWith[16]; 
    const char mimeType[32];
  };

  // Table of extension->MIME strings stored in PROGMEM, needs to be global due to GCC section typing rules
  const Entry mimeTable[maxType] = 
  {
      { ".html",      "text/html" },
      { ".htm",       "text/html" },
      { ".css",       "text/css" },
      { ".txt",       "text/plain" },
      { ".js",        "application/javascript" },
      { ".json",      "application/json" },
      { ".png",       "image/png" },
      { ".gif",       "image/gif" },
      { ".jpg",       "image/jpeg" },
      { ".ico",       "image/x-icon" },
      { ".svg",       "image/svg+xml" },
      { ".ttf",       "application/x-font-ttf" },
      { ".otf",       "application/x-font-opentype" },
      { ".woff",      "application/font-woff" },
      { ".woff2",     "application/font-woff2" },
      { ".eot",       "application/vnd.ms-fontobject" },
      { ".sfnt",      "application/font-sfnt" },
      { ".xml",       "text/xml" },
      { ".pdf",       "application/pdf" },
      { ".zip",       "application/zip" },
      { ".gz",        "application/x-gzip" },
      { ".appcache",  "text/cache-manifest" },
      { "",           "application/octet-stream" } 
  };
  //extern const Entry mimeTable[maxType];
} // namespace mime

#endif    // #ifndef __MIMETABLE_H__

