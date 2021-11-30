#include "motor.h"


//����Ҫ������  PA6 PA7  PB0 PB1
//TIM3_CH1 PA6
//TIM3_CH2 PA7
//TIM3_CH3 PB0
//TIM3_CH4 PB1
//1 2����




//void CarGo(void)
//{
//  //TIM_SetCompare1(TIM3 , 0);  //��ֵԽ���ٶ�Խ��
//  TIM_SetCompare2(TIM3 , 200);   //170
//  
//	TIM_SetCompare3(TIM3 ,200);  
// //TIM_SetCompare4(TIM3 , 0);	
//}
void CarGo(void)
{
  TIM_SetCompare1(TIM3 , 0);  //��ֵԽ���ٶ�Խ��
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
  TIM_SetCompare1(TIM3 , 05);  //��ֵԽ���ٶ�Խ��
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
  
  
  TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
  
  //�˿ڸ���
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;   //��ʼ��Ҫ�õ�A6/A7��
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	
  GPIO_Init(GPIOA, &GPIO_InitStructure);   
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;   //��ʼ��Ҫ�õ�B0/B1��
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	
  GPIO_Init(GPIOB, &GPIO_InitStructure);   
  
  //PWMͨ��1
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC1Init(TIM3 , &TIM_OCInitStructure);
  TIM_OC1PreloadConfig(TIM3 , TIM_OCPreload_Enable);
  
  //PWMͨ��2
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC2Init(TIM3 , &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM3 , TIM_OCPreload_Enable);
  
  //PWMͨ��3
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC3Init(TIM3 , &TIM_OCInitStructure);
  TIM_OC3PreloadConfig(TIM3 , TIM_OCPreload_Enable);
  
  //PWMͨ��4
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OC4Init(TIM3 , &TIM_OCInitStructure);
  TIM_OC4PreloadConfig(TIM3 , TIM_OCPreload_Enable);
  
  TIM_CtrlPWMOutputs(TIM3,ENABLE);	//MOE �����ʹ��	
	TIM_ARRPreloadConfig(TIM3, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
  TIM_Cmd(TIM3 , ENABLE);
}
