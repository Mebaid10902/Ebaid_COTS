/*

 * ADC_prog.c
 *
 *  Created on: Dec 16, 2023
 *      Author: admin
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include "ADC_interface.h"
#include "ADC_reg.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"

void ADC_voidInit(void)
{
	/*Set AVCC as reference voltage*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	/*Select left or right  adjust according to resolution configuration*/
#if ADC_u8Resolution  == EIGHT_BITS

	SET_BIT(ADMUX,ADLAR);
#elif ADC_u8Resolution  == TEN_BITS
	CLR_BIT(ADMUX,ADLAR);
#else
#error Wrong ADC_u8Resolution configuration option
#endif
	/*Disable auto trigger mode*/
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
	/*Disable interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
	/*Enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
	/*CLEAR the prescaler division factor*/
	ADCSRA &= PRESCALER_BIT_MASK;

	/*Configure the prescaler division factor*/
	ADCSRA |= ADC_u8PRESCALER_DIVISION_FACTOR <<PRESCALER_BIT_POS;


}
uint16 ADC_u8ChannelReading(uint8 copy_u8Channel)
{
	/*Set the input channel*/
	ADMUX &= CHANNEL_BIT_MASK;         /*Clear the channel selection bits*/
	ADMUX |= copy_u8Channel;
	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*Polling (with blocking) on the conversion complete*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	/*Clear the conversion flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	/*Get the conversion result*/
#if ADC_u8Resolution  == EIGHT_BITS
	return ADCH;
#elif ADC_u8Resolution  == TEN_BITS
    return ADC;
#endif

}


