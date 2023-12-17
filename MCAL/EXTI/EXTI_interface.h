#ifndef  EXTI_INTERFACE_H
#define  EXTI_INTERFACE_H

typedef enum
{
	INT0, INT1, INT2
}	IntChannel_t;

typedef enum
{
	
	LOW_LEVEL, ON_CHANGE, FALLING_EDGE, RISING_EDGE
}SencseCtrl_t;

void EXTI_VoidInit(void);

uint8 EXTI_u8SetSenseCtrl(IntChannel_t Copy_u8Intpin, SencseCtrl_t Copy_SenseCtrl );

uint8 EXTI_u8EnableIntChannel(IntChannel_t Copy_Intch);

uint8 EXTI_u8DisableIntChannel(IntChannel_t Copy_Intch);
uint8 EXTI_u8Set_CallBack(IntChannel_t Copy_Intch,void(*Copy_pvCallBackFunc(void)));




#endif 
