#define HAL_ETH_MODULE_ENABLED

#if LAN8742A_PHY_ADDRESS
  #undef LAN8742A_PHY_ADDRESS
  #define LAN8742A_PHY_ADDRESS 0x01U
#endif
