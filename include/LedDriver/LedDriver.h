#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include <stdint.h>
void LedDriver_Create(uint16_t * address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn();

#endif // LED_DRIVER_H_
