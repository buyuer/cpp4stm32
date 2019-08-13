#include "Robot.hpp"

#include "cmath"

#include "FreeRTOS.h"
#include "task.h"


/*----------------------------------------------------------------------------------------------------------------*/
#define _DELAY_MS(T)		vTaskDelay(T)

#define _PERIOD				100.0f

_S_IN_ void _set_motor_speed_(f32 a,f32 b,f32 c,f32 d)
{
	if(a >= 0.0f){
		if(GET_TIM_CCR(3,2) > 0u)
		{
			GET_TIM_CCR(3,2) = 0u;
			//_DELAY_MS(100);
		}
		GET_TIM_CCR(3,1) = (u32)(a * _PERIOD);
	}
	else {
		if(GET_TIM_CCR(3,1) > 0u)
		{
			GET_TIM_CCR(3,1) = 0u;
			//_DELAY_MS(100);
		}
		GET_TIM_CCR(3,2) = (u32)((-a) * _PERIOD);
	}
	
	if(b >= 0.0f){
		if(GET_TIM_CCR(3,4) > 0u)
		{
			GET_TIM_CCR(3,4) = 0u;
			//_DELAY_MS(100);
		}
		GET_TIM_CCR(3,3) = (u32)(b * _PERIOD);
	}
	else {
		if(GET_TIM_CCR(3,3) > 0u)
		{
			GET_TIM_CCR(3,3) = 0u;
			//_DELAY_MS(100);
		}
		GET_TIM_CCR(3,4) = (u32)((-b) * _PERIOD);
	}
	
	if(c >= 0.0f){
		if(GET_TIM_CCR(2,3) > 0u)
		{
			GET_TIM_CCR(2,3) = 0u;
			//_DELAY_MS(100);
		}
		GET_TIM_CCR(2,4) = (u32)(c * _PERIOD);
	}
	else {
		if(GET_TIM_CCR(2,4) > 0u)
		{
			GET_TIM_CCR(2,4) = 0u;
			//_DELAY_MS(100);
		}
		GET_TIM_CCR(2,3) = (u32)((-c) * _PERIOD);
	}
	
	if(d >= 0.0f){
		if(GET_TIM_CCR(4,2) > 0u)
		{
			GET_TIM_CCR(4,2) = 0u;
			//_DELAY_MS(100);
		}
		GET_TIM_CCR(4,1) = (u32)(d * _PERIOD);
	}
	else {
		if(GET_TIM_CCR(4,1) > 0u)
		{
			GET_TIM_CCR(4,1) = 0u;
			//_DELAY_MS(100);
		}
		GET_TIM_CCR(4,2) = (u32)((-d) * _PERIOD);
	}
}







/*----------------Robot----------------*/
UPRE::Robot::Robot(f32cr _x,f32cr _y,f32cr _a):x(_x),y(_y),a(_a)
{
	
}

void UPRE::Robot::move(f32cr _vx,f32cr _vy,f32cr& _rotate)const
{
	
}

void UPRE::Robot::update(f32cr _x,f32cr _y,f32cr _a)
{
	x = _x;
	y = _y;
	a = _a;
}





/*----------------Robot_A1----------------*/
UPRE::Robot_A1::Robot_A1(f32cr _x,f32cr _y,f32cr _a):Robot(_x,_y,_a)
{
	
}


void UPRE::Robot_A1::move(f32cr _vx,f32cr _vy,f32cr _rotate)const
{
	f32 _c = cosf(a), _s = sinf(a);
	f32 _vx_ = _vy * _c - _vx * _s;
	f32 _vy_ = _vx * _c + _vy * _s;
	_set_motor_speed_(	_vx_ + _rotate,
						_vy_ + _rotate,
						-_vx_ + _rotate,
						-_vy_ + _rotate);
}