#include "FreeRTOS.h"
#include "task.h"
#include "stm32f4xx_hal.h"
#include "user_global_var.hpp"
xTaskHandle startTask_Handler;
void startTask(void* pvParameters);

extern "C"{

extern UART_HandleTypeDef huart2;
	
u8 u2d;
	
void start()
{
	xTaskCreate((TaskFunction_t)startTask,
				(const char*)   "startTask",
				(unsigned short)128,
				(void*)			NULL,
				(UBaseType_t)	1,
				(xTaskHandle*) 	&startTask_Handler);
				
	HAL_UART_Receive_IT(&huart2,&u2d,1);
				
	vTaskStartScheduler();
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART2)
	{
		handle.set(u2d,0.5f);
		HAL_UART_Receive_IT(&huart2,&u2d,1);
	}
}
}