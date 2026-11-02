#include "../include/OS/SCH.h"            
#include  "../MCAL/Timer/TIMER_interface.h"
#include "../lib/BIT_MATH.h"            
#include "../lib/GINT.h"            
static uint16_t Tick_count=0;
static Timer_t s_mytimercnfg ={.n=timer_0,
        .mode=timer_NormalMode,
        .nonPWM_COmode=timer_OCdisconnected,
        .PWM_COmode=timer_OCdisconnect,
        .ClockSource_t0=timer0_1024Prescale,
        .interrptEnable=timer_OverflowOnly
    };
//timer ISR
void SCH_Update()
{
    Tick_count++;
    // System_time++;
    //255-156==set timer to 99;

    MTimer_voidSetCounter(&s_mytimercnfg,100u);
}
void SCH_intit()
{
    
    MTimer_voidTimerInit(&s_mytimercnfg);
    MTimer_voidSetCallback(&s_mytimercnfg,SCH_Update,timer_InterruptOVF);


}

void SCH_Dispatch_Tasks()
{
    uint16_t index;
    uint16_t update_required =0;
   Disable_Global_Interrupt;
    if(Tick_count > 0)
    {
        Tick_count--;
        update_required=1;
    }
    Enable_Global_Interrupt;
    while(update_required)
    {
        for(index=0;index<SCH_MAX_TASK;index++)
        {
            if(SCH_tasks[index].pTask)
            {
                if(--SCH_tasks[index].delay == 0)
                {
                    (*SCH_tasks[index].pTask)();
                    if(SCH_tasks[index].period != 0)
                    {
                        SCH_tasks[index].delay = SCH_tasks[index].period ;
                    }
                    else
                    {
                        SCH_tasks[index].pTask=0;
                    }
                }
            }
        }
    }
}

uint16_t SCH_Add_Task(void(*pFunction)(void),const uint16_t delay,const uint16_t period)
{
    uint16_t index=0;
    while ((SCH_tasks[index].pTask!=0) && (index<SCH_MAX_TASK) )
    {
        index++;
    }
    if(index==SCH_MAX_TASK)
    {
        return SCH_MAX_TASK;
    }
    SCH_tasks[index].pTask=pFunction;
    SCH_tasks[index].delay=delay+1;
    SCH_tasks[index].period=period;
    return index;
}
