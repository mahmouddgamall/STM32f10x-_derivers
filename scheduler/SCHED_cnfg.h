/************************************************************
Author :Mahmoud Gamal
Version:v01
Date:13 March 2020
*************************************************************/
#ifndef SCHED_CONFIG_H
#define SCHED_CONFIG_H

#include"SCHED_interfac.h"


#define MAX_NUM_TASKS      (u8 )2
#define TICK_TIME          (u32)1000

typedef struct {

  const Task_t * const AppTask;
  u32 firstDelayTicks;
}SystemTask_arch_t;




#endif
