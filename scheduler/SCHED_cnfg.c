/************************************************************
Author :Mohamed Ibrahem
Version:v01
Date:13 March 2020
 *************************************************************/
#include "bit_math.h"
#include "std_types.h"
#include"SCHED_interfac.h"
#include"SCHED_cnfg.h"



extern void Switch(void);
extern void LED(void);

Task_t task1={Switch,1000,0};
Task_t task2={LED,5000,1};


SystemTask_arch_t System_Task_arch[MAX_NUM_TASKS]=
{
		{&task1,0},
		{&task2,1}
};

