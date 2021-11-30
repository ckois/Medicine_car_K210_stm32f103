#include "motor.h"


//所需要的引脚  PA6 PA7  PB0 PB1
//TIM3_CH1 PA6
//TIM3_CH2 PA7
//TIM3_CH3 PB0
//TIM3_CH4 PB1
//1 2左轮




//void CarGo(void)
//{
//  //TIM_SetCompare1(TIM3 , 0);  //数值越大速度越慢
//  TIM_SetCompare2(TIM3 , 200);   //170
//  
//	TIM_SetCompare3(TIM3 ,200);  
// //TIM_SetCompare4(TIM3 , 0);	
//}
void CarGo(void)
{
  TIM_SetCompare1(TIM3 , 0);  //数值越大速度越慢
  TIM_SetCompare2(TIM3 , 18);   //170
  
	TIM_SetCompare3(TIM3 ,20);  
 TIM_SetCompare4(TIM3 , 0);	
}

void CarRight(void)
{
 TIM_SetCompare1(TIM3 , 0);
  TIM_SetCompare2(TIM3 , 25);
  TIM_SetCompare3(TIM3 , 0);
  TIM_SetCompare4(TIM3 , 25);
}



void CarLeft(void)
{
 TIM_SetCompare1(TIM3 ,  28);//90
  TIM_SetCompare2(TIM3 , 0);
  TIM_SetCompare3(TIM3 , 28);
 TIM_SetCompare4(TIM3 , 0);
//  
}
void CarDT(void)
{
  TIM_SetCompare1(TIM3 , 50);//
  TIM_SetCompare2(TIM3 , 0);
  TIM_SetCompare3(TIM3 , 50);
  TIM_SetCompare4(TIM3 , 0);
//  
}

void CarDT1(void)
{
  TIM_SetCompare1(TIM3 , 0);
  TIM_SetCompare2(TIM3 , 50);
  TIM_SetCompare3(TIM3 , 0);
  TIM_SetCompare4(TIM3 , 50);
//  
}


void CarBigright(void)
{
  TIM_SetCompare1(TIM3 , 0);
  TIM_SetCompare2(TIM3 , 100);
  TIM_SetCompare3(TIM3 , 0);
  TIM_SetCompare4(TIM3 , 70);
}
void CarBigleft(void)
{
  TIM_SetCompare1(TIM3 , 70);//90
 TIM_SetCompare2(TIM3 , 00);
  TIM_SetCompare3(TIM3 , 100);
 TIM_SetCompare4(TIM3 , 00);
  
}

void CarStop(void)
{
  TIM_SetCompare1(TIM3 , 05);  //数值越大速度越慢
  TIM_SetCompare2(TIM3 , 00);
  TIM_SetCompare3(TIM3 , 00);  
  TIM_SetCompare4(TIM3 , 05);	
  
}
//void CarStop(void)
//{
//  TIM_SetCompare1(TIM3 , 200); 
//  TIM_SetCompare2(TIM3 , 200);
//  TIM_SetCompare3(TIM3 , 200);  
//  TIM_SetCompare4(TIM3 , 200);
//}

void TIM3_PWM_Init(u16 arr,u16 psc)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  TIM_OCInitTypeDef TIM_OCInitStructure; 
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 , ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
  
  
  TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
  
  //端口复用
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;   //初始化要用的A6/A7口
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	
  GPIO_Init(GPIOA, &GPIO_InitStructure);   
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;   //初始化要用的B0/B1口
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	
  GPIO_Init(GPIOB, &GPIO_InitStructure);   
  
  //PWM通道1
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC1Init(TIM3 , &TIM_OCInitStructure);
  TIM_OC1PreloadConfig(TIM3 , TIM_OCPreload_Enable);
  
  //PWM通道2
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC2Init(TIM3 , &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM3 , TIM_OCPreload_Enable);
  
  //PWM通道3
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC3Init(TIM3 , &TIM_OCInitStructure);
  TIM_OC3PreloadConfig(TIM3 , TIM_OCPreload_Enable);
  
  //PWM通道4
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC4Init(TIM3 , &TIM_OCInitStructure);
  TIM_OC4PreloadConfig(TIM3 , TIM_OCPreload_Enable);
  
  TIM_CtrlPWMOutputs(TIM3,ENABLE);	//MOE 主输出使能	
	TIM_ARRPreloadConfig(TIM3, ENABLE); //使能TIMx在ARR上的预装载寄存器
  TIM_Cmd(TIM3 , ENABLE);
}
