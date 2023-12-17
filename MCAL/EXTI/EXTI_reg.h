#ifndef EXIT_REG_H
#define EXIT_REG_H
#define GICR   *((volatile uint8*)0x5B)   /*General interrupt control register*/
#define GICR_INT1   7u                    /*int1 bit*/
#define GICR_INT0   6u                    /*int0 bit*/
#define GICR_INT2   5u                    /*int2 bit*/
 
#define  MCUCR *((volatile uint8*)0x55)   /*MCU Control register*/
#define  MCUCR_ISC00   0u                 /*int0 sense control  bit0*/
#define  MCUCR_ISC01   1u                 /*int0 sense control  bit1*/
#define  MCUCR_ISC10   2u                 /*int1 sense control  bit0*/
#define  MCUCR_ISC11   3u                 /*int1 sense control  bit1*/

#define MCUCSR  *((volatile uint8*)0x54)  /*MCU Control and status register*/
#define MCUCSR_ISC2  6u                   /*Int2 sense control bit*/




#endif