#ifndef _SERIALPORT_HPP_
#define _SERIALPORT_HPP_

#include "Base.hpp"

namespace UPRE{

	class SerialPort
	{
	private:
		USART_TypeDef* port;
		
			
	public:
		SerialPort(USART_TypeDef* p);
		
		SerialPort& operator << (const s8* str);
	};

}
#endif
