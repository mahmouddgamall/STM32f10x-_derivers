#include "bit_math.h"
#include "std_types.h"
#include "rcc_interface.h"
#include "STK_interfac.h"
#include "HRCC.h"
#include "SCHED_interfac.h"
#include "SCHED_cnfg.h"
extern SystemTask_arch_t System_Task_arch[];
u8 OS_flag=0;
static void OS_setFlag(void)
{
	OS_flag=1;
}

typedef struct{
	Task_t *AppTask;
	u32 RemainTime;
	u32 PriodicTicks;
	u8 State;
}SystemTask_t;

SystemTask_t systemtask[MAX_NUM_TASKS];

void SCHED_init(void)
{
	u32 Speed;
	for(u8 Counter=0;Counter<MAX_NUM_TASKS;Counter++)
	{
		systemtask[Counter].AppTask=System_Task_arch[Counter].AppTask;
		systemtask[Counter].RemainTime=System_Task_arch[Counter].firstDelayTicks;
		systemtask[Counter].PriodicTicks=(System_Task_arch[Counter].AppTask->periodic_time/TICK_TIME);
		systemtask[Counter].State=TASK_RUNNING;
	}
	SYSTICK_voidInit();
	SYSTICK_errSetCallBack(OS_setFlag);
	Speed=HRCC_u32GetAHBClockSpeed();
	SYSTICK_errSetTimerusec(TICK_TIME,Speed);
	SYSTICK_voidStart();
}



void SCHED_start_scheduler(void)
{
	while(1)
	{
		if(OS_flag==1)
		{
			OS_flag = 0;
			SCHED_errSchedular();
		}
	}
}

u8 SCHED_errSchedular(void)
{
	u8 Err_status;
	Err_status = OK;
	static u32 Counter=0;
	for(Counter=0;Counter<MAX_NUM_TASKS;Counter++)
	{
		if(systemtask[Counter].RemainTime==0 && systemtask[Counter].State==TASK_RUNNING)
		{
			if(systemtask[Counter].AppTask->ptr_F_runnable)
			{
				systemtask[Counter].AppTask->ptr_F_runnable();
				systemtask[Counter].RemainTime=systemtask[Counter].PriodicTicks;
			}
			else
			{
				Err_status = NOK;
			}
		}
		systemtask[Counter].RemainTime--;
	}
	return Err_status;
}


void SCHED_Suspend(SystemTask_t systask)
{
	systask.State= TASK_SUSPENDED;
}



