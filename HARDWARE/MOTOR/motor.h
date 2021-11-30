#ifndef __MOTOR_H
#define	__MOTOR_H


#include "stm32f10x.h"

//#define IN1_up GPIO_SetBits(GPIOA, GPIO_Pin_6)
//#define IN1_down  GPIO_ResetBits(GPIOA,GPIO_Pin_6)

//#define IN2_up GPIO_SetBits(GPIOA, GPIO_Pin_7)
//#define IN2_down  GPIO_ResetBits(GPIOA,GPIO_Pin_7)

//#define IN3_up GPIO_SetBits(GPIOA, GPIO_Pin_3)
//#define IN3_down  GPIO_ResetBits(GPIOA,GPIO_Pin_3)

//#define IN4_up GPIO_SetBits(GPIOA, GPIO_Pin_4)
//#define IN4_down  GPIO_ResetBits(GPIOA,GPIO_Pin_4)


void TIM3_PWM_Init(u16 arr,u16 psc);
void CarGo(void);
void CarLeft(void);
void CarRight(void);
void CarStop(void);
void CarStop(void);
void CarBigright(void);
void CarBigleft(void);
void CarDT(void);
void CarDT1(void);
#endif
