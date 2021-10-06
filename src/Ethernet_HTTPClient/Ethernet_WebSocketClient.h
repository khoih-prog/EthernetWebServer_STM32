/****************************************************************************************************************************
   Ethernet_WebSocketClient.h - Dead simple HTTP WebSockets Client.
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
 
// (c) Copyright Arduino. 2016
// Released under Apache License, version 2.0

#pragma once

#include <Arduino.h>

#include "detail/Debug_STM32.h"

#include "Ethernet_HTTPClient/Ethernet_HttpClient.h"

static const int TYPE_CONTINUATION     = 0x0;
static const int TYPE_TEXT             = 0x1;
static const int TYPE_BINARY           = 0x2;
static const int TYPE_CONNECTION_CLOSE = 0x8;
static const int TYPE_PING             = 0x9;
static const int TYPE_PONG             = 0xa;

class EthernetWebSocketClient : public EthernetHttpClient
{
  public:
    EthernetWebSocketClient(Client& aClient, const char* aServerName, uint16_t aServerPort = EthernetHttpClient::kHttpPort);
    EthernetWebSocketClient(Client& aClient, const String& aServerName, uint16_t aServerPort = EthernetHttpClient::kHttpPort);
    EthernetWebSocketClient(Client& aClient, const IPAddress& aServerAddress, uint16_t aServerPort = EthernetHttpClient::kHttpPort);

    /** Start the Web Socket connection to the specified path
      @param aURLPath     Path to use in request (optional, "/" is used by default)
      @return 0 if successful, else error
    */
    int begin(const char* aPath = "/");
    int begin(const String& aPath);

    /** Begin to send a message of type (TYPE_TEXT or TYPE_BINARY)
        Use the write or Stream API's to set message content, followed by endMessage
        to complete the message.
      @param aURLPath     Path to use in request
      @return 0 if successful, else error
    */
    int beginMessage(int aType);

    /** Completes sending of a message started by beginMessage
      @return 0 if successful, else error
    */
    int endMessage();

    /** Try to parse an incoming messages
      @return 0 if no message available, else size of parsed message
    */
    int parseMessage();

    /** Returns type of current parsed message
      @return type of current parsedMessage (TYPE_TEXT or TYPE_BINARY)
    */
    int messageType();

    /** Returns if the current message is the final chunk of a split
        message
      @return true for final message, false otherwise
    */
    bool isFinal();

    /** Read the current messages as a string
      @return current message as a string
    */
    String readString();

    /** Send a ping
      @return 0 if successful, else error
    */
    int ping();

    // Inherited from Print
    virtual size_t write(uint8_t aByte);
    virtual size_t write(const uint8_t *aBuffer, size_t aSize);
    
    // Inherited from Stream
    virtual int   available();
    /** Read the next byte from the server.
      @return Byte read or -1 if there are no bytes available.
    */
    virtual int read();
    virtual int read(uint8_t *buf, size_t size);
    virtual int peek();

  private:
    void flushRx();

  private:
    bool      iTxStarted;
    uint8_t   iTxMessageType;
    uint8_t   iTxBuffer[128];
    uint64_t  iTxSize;

    uint8_t   iRxOpCode;
    uint64_t  iRxSize;
    bool      iRxMasked;
    int       iRxMaskIndex;
    uint8_t   iRxMaskKey[4];
};

