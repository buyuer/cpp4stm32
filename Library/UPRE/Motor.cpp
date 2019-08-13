#include "Motor.hpp"



/*Motor*/
UPRE::Motor::Motor(s32cr _id):id(_id)
{
	
}

void UPRE::Motor::turn(s32cr)const
{
	
}

void UPRE::Motor::pos(s32cr,s32cr)const
{
	
}

/*Motor_CDS*/
UPRE::Motor_CDS::Motor_CDS(s32cr _id):Motor(_id)
{
	
}

void UPRE::Motor_CDS::pos(s32cr pos,s32cr speed)const
{
	u8 send_buff[11] = {0};
	send_buff[0] 	= 0xffu;
	send_buff[1] 	= 0xffu;
	send_buff[2] 	= id;
	send_buff[3] 	= 0x07u;
	send_buff[4] 	= 0x03u;
	send_buff[5] 	= 0x1eu;
	send_buff[6] 	= (uint8_t) pos;
	send_buff[7] 	= (uint8_t)(pos>>8);
	send_buff[8] 	= (uint8_t) speed;
	send_buff[9] 	= (uint8_t)(speed>>8);
	send_buff[10]	= ~(uint8_t)(	send_buff[2] + 
									send_buff[3] + 
									send_buff[4] + 
									send_buff[5] + 
									send_buff[6] + 
									send_buff[7] + 
									send_buff[8] + 
									send_buff[9]);
	USART_SEND(6,send_buff);
}



/*Motor_PWM*/
void UPRE::Motor_PWM::turn(s32cr speed)const
{
	
}