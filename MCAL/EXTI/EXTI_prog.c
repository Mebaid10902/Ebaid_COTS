#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include "EXTI_reg.h"
#include "EXTI_interface.h"
#include "EXTI_prv.h"
#include "EXTI_cfg.h"

static void(*EXIT_pvCallBack[3])(void)={0};

void EXTI_VoidInit(void)
{

#if INT0_SENCE_CTRL == 	EXTI_LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENCE_CTRL == EXTI_ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENCE_CTRL == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENCE_CTRL == EXTI_RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#else
	#error Wrong INT0_SENCE_CTRL configuration option
#endif

#if INT1_SENCE_CTRL == 	EXTI_LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENCE_CTRL == EXTI_ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENCE_CTRL == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENCE_CTRL == EXTI_RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
	#error Wrong INT1_SENCE_CTRL configuration option
#endif


#if INT2_SENCE_CTRL == EXTI_FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2);

#elif INT2_SENCE_CTRL == EXTI_RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);

#else
	#error Wrong INT0_SENCE_CTRL configuration option
#endif
#if INT0_INIT_STATE == DISABLED
	CLR_BIT(GICR, GICR_INT0);
#elif INT0_INIT_STATE == ENABLED
	SET_BIT(GICR, GICR_INT0);

#else  #error Wrong INT0_INIT_STATE configuration option
#endif
#if INT1_INIT_STATE == DISABLED
	CLR_BIT(GICR, GICR_INT1);
#elif INT1_INIT_STATE == ENABLED
	SET_BIT(GICR, GICR_INT1);

#else  #error Wrong INT1_INIT_STATE configuration option
#endif
#if INT2_INIT_STATE == DISABLED
	CLR_BIT(GICR, GICR_INT2);
#elif INT2_INIT_STATE == ENABLED
	SET_BIT(GICR, GICR_INT2);

#else  #error  Wrong INT2_INIT_STATE configuration option
#endif
}

uint8 EXTI_u8SetSenseCtrl(IntChannel_t Copy_u8IntCh, SencseCtrl_t Copy_SenseCtrl )

{
uint8 Local_u8ErrorState = OK;
if(Copy_u8IntCh == INT0)
{
	switch(Copy_SenseCtrl)
	{
	case LOW_LEVEL:CLR_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
	case ON_CHANGE:SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
	case FALLING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
	case RISING_EDGE:SET_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
	default: Local_u8ErrorState =NOK; break;
	}
}
else if(Copy_u8IntCh == INT1)
{
	switch(Copy_SenseCtrl)
	{
	case LOW_LEVEL:CLR_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
	case ON_CHANGE:SET_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
	case FALLING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
	case RISING_EDGE:SET_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
	default: Local_u8ErrorState =NOK; break;
	}
}
else if(Copy_u8IntCh == INT2)
{
	switch(Copy_SenseCtrl)
	{
	case FALLING_EDGE:CLR_BIT(MCUCSR,MCUCSR_ISC2); break;
	case RISING_EDGE:SET_BIT(MCUCSR,MCUCSR_ISC2);  break;
	default: Local_u8ErrorState =NOK; break;
	}
}
else
{
 Local_u8ErrorState =NOK;
}
}

uint8 EXTI_u8EnableIntChannel(IntChannel_t Copy_Intch)

{
uint8 Local_u8ErrorState = OK;
switch(Copy_Intch)
{
case INT0: SET_BIT(GICR,GICR_INT0); break;
case INT1: SET_BIT(GICR,GICR_INT1); break;
case INT2: SET_BIT(GICR,GICR_INT2); break;
default: Local_u8ErrorState = NOK; break;
}

}

uint8 EXTI_u8DisableIntChannel(IntChannel_t Copy_Intch)

{
uint8 Local_u8ErrorState = OK;
	switch(Copy_Intch)
	{
	case INT0: CLR_BIT(GICR,GICR_INT0); break;
	case INT1: CLR_BIT(GICR,GICR_INT1); break;
	case INT2: CLR_BIT(GICR,GICR_INT2); break;
	default: Local_u8ErrorState = NOK; break;
	}

}
uint8 EXTI_u8Set_CallBack(IntChannel_t Copy_Intch,void(*Copy_pvCallBackFunc(void)))
{
	uint8 Local_u8ErrorStatus = OK;
	if(Copy_pvCallBackFunc !=NULL)
	{
		EXIT_pvCallBack[Copy_Intch] = Copy_pvCallBackFunc;
	}
	else
	{

	}
}

__attribute__((signal)) void __vector_1(void);
void __vector_1(void)
{
	if(EXIT_pvCallBack[INT0] != NULL)
	{
		EXIT_pvCallBack[INT0]();
	}
}
__attribute__((signal)) void __vector_2(void);
void __vector_2(void)
{
	if(EXIT_pvCallBack[INT1] != NULL)
	{
		EXIT_pvCallBack[INT1]();
	}
}
__attribute__((signal)) void __vector_3(void);
void __vector_3(void)
{
	if(EXIT_pvCallBack[INT2] != NULL)
	{
		EXIT_pvCallBack[INT2]();
	}
}
