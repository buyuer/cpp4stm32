#include "Handle.hpp"
#include "cmath"
UPRE::Handle::Handle():key(0.0f),rocker_x(0.0f),rocker_y(0.0f),rocker_a(0.0f)
{
	handler = new Handler[63];
	__isRun = false;
}

void UPRE::Handle::set(u8cr _v,f32cr k)
{
	if(_v > 0x3Cu)
	{
		if(_v <= 0x7Du)
		{
			rocker_a = ((_v - 0x5D) / 32.0f) * k;
		}
		else if(_v > 0x7Du && _v <= 0xBEu)
		{
			rocker_x = ((_v - 0x9E) / 32.0f) * k;
			
			if(rocker_x > 0.0f)
			{
				if(rocker_x < 0.1f)rocker_x = 0.1f;
			}
			else if(rocker_x < 0.0f)
			{
				if(rocker_x > -0.1f)rocker_x = -0.1f;
			}
			else 
			{
				rocker_x = 0.0f;
			}
		}
		else if(_v > 0xBEu)
		{
			rocker_y = ((_v - 0xDF) / 32.0f) * k;
			
			if(rocker_y > 0.0f)
			{
				if(rocker_y < 0.1f)rocker_y = 0.1f;
			}
			else if(rocker_y < 0.0f)
			{
				if(rocker_y > -0.1f)rocker_y = -0.1f;
			}
			else
			{
				rocker_y = 0.0f;
			}
		}
	}
	else
	{
		key = _v;
		__isRun = true;
	}
}

_IN_
void UPRE::Handle::setHandler(s32cr k,Handler h)
{
	handler[k] = h;
}

_IN_
void UPRE::Handle::handlerRun()
{
	if(__isRun){
		handler[key](key);
		__isRun = false;
	}
}