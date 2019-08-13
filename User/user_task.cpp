#include "FreeRTOS.h"
#include "task.h"
#include "portable.h"
#include "cpp4stm32.hpp"
#include "user_global_var.hpp"
/*__attribute__((section("ARM.__at_0x10000000")))*/

using namespace UPRE;


#define DEFINE_AN_TASK(NAME,HEAPSIZE,PRIO,ARG)			static xTaskHandle	task##NAME_Handle;					\
														static void			task##NAME(void* pvParameters)		\
														

static xTaskHandle 	taskTest_Handle;
static void 		taskTest(void* pvParameters);

static xTaskHandle	taskHandlerRun_Handle;
static void			taskHandlerRun(void* pvParameters);

void startTask(void *pvParameters)
{
	taskENTER_CRITICAL();
	
	xTaskCreate((TaskFunction_t)taskTest,
				(const char*)   "taskTest",
				(unsigned short)512,
				(void*)			NULL,
				(UBaseType_t)	2,
				(xTaskHandle*) 	&taskTest_Handle);
				
	
	
//	handle.setHandler(0x01,[](s32cr _k)->void{
//		
//	});			
				
	extern xTaskHandle startTask_Handler;
	vTaskDelete(startTask_Handler);
				
	taskEXIT_CRITICAL();
	
}


static void taskTest(void *pvParameters)
{
	while(true)
	{
		
		robot.move(handle.rocker_x,handle.rocker_y,handle.rocker_a);
//		cds1.pos(0,500);
//		cds2.pos(800,500);    	//抬开
		
		cds1.pos(710,500);
		cds2.pos(110,500);		//抓住
		vTaskDelay(50);
	}
}

static void taskHandlerRun(void* pvParameters)
{
	while(true)
	{
		handle.handlerRun();
		vTaskDelay(10);
	}
}
