#ifndef D_TIME_SERVICE_H
#define D_TIME_SERVICE_H

typedef struct TIME
{
    int minuteOfDay;
    int dayOfWeek;
} Time;

typedef enum 
{
    NONE=-1, EVERYDAY=10, WEEKDAY, WEEKEND,
    SUNDAY=1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
} Day;

#endif // D_TIME_SERVICE_H
