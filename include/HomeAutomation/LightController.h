#ifndef D_LightController_H
#define D_LightController_H

typedef enum
{
    LIGHT_ID_UNKNOWN = -1, LIGHT_STATE_UNKNOWN = -1,
    LIGHT_OFF = 0, LIGHT_ON = 1
} LIGHT_CONTROLLER_EVENT;

void LightController_Create(void);
void LightController_Destroy(void);
void LightController_On(int id);
void LightController_Off(int id);

#endif  /* D_LightController_H */
