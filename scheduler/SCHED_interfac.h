/************************************************************
Author :Mohamed Ibrahem
Version:v01
Date:13 March 2020
*************************************************************/
#ifndef SCHED_INTERFACE_H
#define SCHED_INTERFACE_H

#define TASK_RUNNING          (u8)0
#define TASK_SUSPENDED        (u8)1


typedef void(*taskRunnable_t)(void);

typedef struct{
  taskRunnable_t ptr_F_runnable;
  u32 periodic_time;
  u32 priority;
}Task_t;


void SCHED_init(void);
static u8 SCHED_errSchedular(void);
void SCHED_Suspend(SystemTask_t);
void SCHED_start_scheduler(void);


#endif
