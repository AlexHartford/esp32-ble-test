#include "a_config.h"
#include "globals.h"
#include "debug.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_NIMBLE_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif



Units convertUnitsEnum(const char* v);
std::string unitsToString(Units u); 

void BLEsetup();
void updateBTWeight(std::string w);
bool isBtConnected();
void BLEstop();