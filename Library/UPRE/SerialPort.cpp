#include "SerialPort.hpp"

using namespace UPRE;

SerialPort::SerialPort(USART_TypeDef* p):port(p)
{
	
}



SerialPort& SerialPort::operator<<(const s8* str)
{
	while(*str != '\0'){
		port->DR = *(str++);
		while(!port->SR);
	}
	return (*this);
}