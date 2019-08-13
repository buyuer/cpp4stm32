#ifndef _MOTOR_HPP_
#define _MOTOR_HPP_

#include "Base.hpp"


namespace UPRE{
	
	class Motor
	{
	public:
		s32 id;
		Motor(s32cr);
		virtual void turn(s32cr) 		const;
		virtual void pos(s32cr,s32cr)	const;
	};
	
	class Motor_CDS : public Motor
	{
	public:
		Motor_CDS(s32cr);
		void pos(s32cr,s32cr)		const;
	};
	
	class Motor_PWM : public Motor
	{
	public:
		void turn(s32cr) const;
	};
}










#endif
