#include "LedDriver.h"
#include "RuntimeError.h"
#include <stdbool.h>

static uint16_t convertLedNumberToBit(int ledNumber);
static void updateHardware(void);
static bool IsLedOutOfBounds(int ledNumber);

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};

static uint16_t* ledsAddress;
static uint16_t ledsImage;

void LedDriver_Create(uint16_t * address)
{
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

void LedDriver_TurnOn(int ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
    {
        RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
        return;
    }
    ledsImage |= convertLedNumberToBit(ledNumber);
    updateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
        return;
    ledsImage &= ~(convertLedNumberToBit(ledNumber));
    updateHardware();
}

void LedDriver_TurnAllOn()
{
    ledsImage = ALL_LEDS_ON;
    updateHardware();
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

static void updateHardware(void)
{
    *ledsAddress = ledsImage;
}
enum {FIRST_LED = 1, LAST_LED = 16};

static bool IsLedOutOfBounds(int ledNumber)
{
    return (ledNumber < FIRST_LED || ledNumber > LAST_LED);
}

void LedDriver_Destroy(void)
{

}
