#ifndef _SENSOR_HPP_
#define _SENSOR_HPP_

#include "Base.hpp"

namespace UPRE{
	
	class Sensor
	{
	public:
		s32 id;
	};
	
	class Sensor_Ultrasonic : public Sensor
	{
	public:
		s32 value;
		void update();
	};
}



#endif
