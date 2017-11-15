#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include <stdint.h>
#include <stdbool.h>

void LedDriver_Create(uint16_t * address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn();
bool LedDriver_IsOn(int ledNumber);

#endif // LED_DRIVER_H_
