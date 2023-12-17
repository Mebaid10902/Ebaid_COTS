#ifndef EXTI_CFG_H
#define EXTI_CFG_H

/*configure the sense control option for int0 channel, Option:
                                                        1-EXTI_LOW_LEVEL
                                                        2-EXTI_ON_CHANGE
                                                        3-EXTI_FALLING_EDGE
                                                        4-EXTI_RISING_EDGE */

#define  INT0_SENCE_CTRL                                 EXTI_FALLING_EDGE
/*configure the sense control option for int0 channel, Option:
                                                        1-EXTI_LOW_LEVEL
                                                        2-EXTI_ON_CHANGE
                                                        3-EXTI_FALLING_EDGE
                                                        4-EXTI_RISING_EDGE */
#define  INT1_SENCE_CTRL                                EXTI_FALLING_EDGE
/*configure the sense control option for int0 channel, Option:
                                                        1-EXTI_FALLING_EDGE
                                                        2-EXTI_RISING_EDGE */
#define  INT2_SENCE_CTRL                                EXTI_FALLING_EDGE

/*configure the initial state option for int0 channel, Option:

 *                                                       1- ENABLED
 *                                                       2-DISABLED*/
#define INT0_INIT_STATE                                  ENABLED

/*configure the initial state option for int1 channel, Option:

 *                                                       1- ENABLED
 *                                                       2- DISABLED*/
#define INT1_INIT_STATE                                  DISABLED

/*configure the initial state option for int0 channel, Option:

 *                                                       1- ENABLED
 *                                                       2- DISABLED*/
#define INT2_INIT_STATE                                  DISABLED


#endif
