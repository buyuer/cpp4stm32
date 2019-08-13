#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

#include "Base.hpp"

namespace UPRE{
	class Robot
	{
	public:
		f32 x,y,a;
		/*x,y,a*/
		Robot(f32cr = 0.0f,f32cr = 0.0f,f32cr = 0.0f);
		
		virtual void update(f32cr,f32cr,f32cr);
		virtual void move(f32cr,f32cr,f32cr = 0)const;
	};
	
	class Robot_A1 : public Robot
	{
	public:	
		Robot_A1(f32cr = 0.0f,f32cr = 0.0f,f32cr = 0.0f);
		
		virtual void move(f32cr,f32cr,f32cr = 0)const;
	};
}


#endif
