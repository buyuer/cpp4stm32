#ifndef _BASE_HPP_
#define _BASE_HPP_


/**/
#include "stm32f4xx.h"
//IO输入输出
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO口地址映射
#define GPIOA_ODR_Addr    (GPIOA_BASE+20) //0x40020014
#define GPIOB_ODR_Addr    (GPIOB_BASE+20) //0x40020414 
#define GPIOC_ODR_Addr    (GPIOC_BASE+20) //0x40020814 
#define GPIOD_ODR_Addr    (GPIOD_BASE+20) //0x40020C14 
#define GPIOE_ODR_Addr    (GPIOE_BASE+20) //0x40021014 
#define GPIOF_ODR_Addr    (GPIOF_BASE+20) //0x40021414    
#define GPIOG_ODR_Addr    (GPIOG_BASE+20) //0x40021814   
#define GPIOH_ODR_Addr    (GPIOH_BASE+20) //0x40021C14    
#define GPIOI_ODR_Addr    (GPIOI_BASE+20) //0x40022014     

#define GPIOA_IDR_Addr    (GPIOA_BASE+16) //0x40020010 
#define GPIOB_IDR_Addr    (GPIOB_BASE+16) //0x40020410 
#define GPIOC_IDR_Addr    (GPIOC_BASE+16) //0x40020810 
#define GPIOD_IDR_Addr    (GPIOD_BASE+16) //0x40020C10 
#define GPIOE_IDR_Addr    (GPIOE_BASE+16) //0x40021010 
#define GPIOF_IDR_Addr    (GPIOF_BASE+16) //0x40021410 
#define GPIOG_IDR_Addr    (GPIOG_BASE+16) //0x40021810 
#define GPIOH_IDR_Addr    (GPIOH_BASE+16) //0x40021C10 
#define GPIOI_IDR_Addr    (GPIOI_BASE+16) //0x40022010 
 
//IO口操作,只对单一的IO口!
//确保n的值小于16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出 
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //输出 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //输入

#define PHout(n)   BIT_ADDR(GPIOH_ODR_Addr,n)  //输出 
#define PHin(n)    BIT_ADDR(GPIOH_IDR_Addr,n)  //输入

#define PIout(n)   BIT_ADDR(GPIOI_ODR_Addr,n)  //输出 
#define PIin(n)    BIT_ADDR(GPIOI_IDR_Addr,n)  //输入


#define OUTPUT_PWM(T,C,R) 		TIM##T->CCR##C = R##u
#define GET_TIM_CCR(T,C)  		TIM##T->CCR##C
/**/


/**/
#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart6;

#define USART_SEND(U,BUFF)		HAL_UART_Transmit(&huart##U,BUFF,sizeof(BUFF),1);
#define	DELAY_MS(MS)			HAL_Delay(MS);
/**/

/*type*/
	using 	u8		=	unsigned char;
	using	s8		=			 char;
	using 	u16		=	unsigned short;
	using	s16		=			 short;
	using 	u32		=	unsigned int;
	using	s32		=			 int;
	using	f32		=	float;
	using	f64		=	double;

	using	u8c		=	const u8;
	using	s8c		=	const s8;
	using	u16c	=	const u16;
	using	s16c	=	const s16;
	using	u32c	=	const u32;
	using	s32c	=	const s32;
	using	f32c	=	const f32;
	using	f64c	=	const f64;

	using	u8r		=	u8&;
	using	s8r		=	s8&;
	using	u16r	=	u16&;
	using	s16r	=	s16&;
	using	u32r	=	u32&;
	using	s32r	=	s32&;
	using	f32r	=	f32&;
	using	f64r	=	f64&;

	using	u8cr	=	const u8&;
	using	s8cr	=	const s8&;
	using	u16cr	=	const u16&;
	using	s16cr	=	const s16&;
	using	u32cr	=	const u32&;
	using	s32cr	=	const s32&;
	using	f32cr	=	const f32&;
	using	f64cr	=	const f64&;
	
	
	using	Handler	=	void (*)(s32cr);
	

	#define		_S_		static
	#define		_IN_	inline
	#define		_S_IN_	static inline
	
namespace UPRE
{
	class Base{
		
	};
}
#endif
