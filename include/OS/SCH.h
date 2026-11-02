#ifndef SCH_H
#define SCH_H
#include <stdint.h>
#define SCH_MAX_TASK 10
typedef struct 
{
    void (*pTask)(void);
    uint16_t period;
    uint16_t delay;
    
}sTask_t;

sTask_t SCH_tasks[SCH_MAX_TASK];

void SCH_intit();

void SCH_Dispatch_Tasks();

uint16_t SCH_Add_Task(void(*pFunction)(void),const uint16_t delay,const uint16_t period);

#endif