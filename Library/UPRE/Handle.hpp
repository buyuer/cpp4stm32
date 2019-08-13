#ifndef _HANDLE_HPP_
#define _HANDLE_HPP_

#include "Base.hpp"


namespace UPRE{
	class Handle
	{
	private:
		bool __isRun;
	public:
		s32 key;
		f32 rocker_x;
		f32 rocker_y;
		f32 rocker_a;
		Handler* handler;
		
		Handle();
		
		void set(u8cr,f32cr = 1.0f);
	
		void setHandler(s32cr,Handler);
	
		void handlerRun();
	};

}


#endif