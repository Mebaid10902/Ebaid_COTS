/*
 * ADC_cfg.h
 *
 *  Created on: Dec 16, 2023
 *      Author: admin
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/*configure the ADC prescaler devision factor, option: 1- DIVISION_BY_2
 *                                                     2- DIVISION_BY_4
 *                                                     3- DIVISION_BY_8
 *                                                     4- DIVISION_BY_16
 *                                                     5- DIVISION_BY_32
 *                                                     6- DIVISION_BY_64
 *                                                     7- DIVISION_BY_128  */

/*Configure the adc resolution, option                 1- EIGHT_BITS
 *                                                     2- TEN_BITS*/
#define ADC_u8Resolution                               EIGHT_BITS

#define ADC_u8PRESCALER_DIVISION_FACTOR                 DIVISION_BY_128
#endif /* ADC_CFG_H_ */
