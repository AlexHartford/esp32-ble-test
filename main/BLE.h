#ifndef BLE_H
#define BLE_H
#include "sdkconfig.h"
#include <string>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_NIMBLE_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

void BLEsetup();

#endif