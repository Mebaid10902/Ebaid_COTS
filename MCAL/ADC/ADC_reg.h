/*
 * ADC_reg.h
 *
 *  Created on: Dec 16, 2023
 *      Author: admin
 */

#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX         *((volatile uint8*)0x27)       /*ADC Multiplexer selection register*/
#define ADMUX_REFS1   7u                                /*Reference selection Bit1*/
#define ADMUX_REFS0   6u                                /*Reference selection Bit0*/
#define ADLAR         5u                                /*Left Adjust result*/

#define ADCSRA        *((volatile uint8*)0x26)        /*ADC Control and status register*/
#define ADCSRA_ADEN   7u                                /*Enable*/
#define ADCSRA_ADSC   6u                                /*Start conversion*/
#define ADCSRA_ADATE  5u                                /*Auto trigger enable*/
#define ADCSRA_ADIF   4u                                /*Interrupt flag*/
#define ADCSRA_ADIE   3u                                /*interrupt enable*/


#define ADCH          *((volatile uint8*)0x25)        /*ADC Data high register*/
#define ADCL          *((volatile uint8*)0x24)        /*ADC Data low registerS*/
#define ADC           *((volatile uint16*)0x24)       /**/

#endif /* ADC_REG_H_ */
