#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "exti.h"
#include "motor.h" 
#include "stm32f10x.h"
#include "usart.h"
#include "stdio.h"
#include "timer.h"




//5.5�ո�
/************************************************
С������
��С��������5������

ƽ��2�����ܣ����ֽ�KEY0��KEY1��д���������                   �������ұ���  
б��3������ �����жϺ�����ֱ����ж���2-4��      ���ڷ�׹��

key.c�����������ܽ� �ֱ���PA0 PA1(��ֵ����)
exti.c������3���ܽ� �ֱ���PA2 PA3 PA4(�жϺ���)
motor.c����һ���������  ���潫ǰ�������ˡ���ת����ת������ת������ת

�����õ����ţ�IN1,IN2,IN3,IN4��
//TIM3_CH1 PA6
//TIM3_CH2 PA7
//TIM3_CH3 PB0
//TIM3_CH4 PB1
��������õ�PWM���٣����ö�ʱ��3���ĸ�ͨ��
************************************************/

 int main(void)
 {		
	 int aaa=1;
	 int bbb=1;
	 int ccc=1;
	 int ddd=1;
	 int i;
	delay_init();	    	 //��ʱ������ʼ��	  
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
  LED_Init();
  TIM3_PWM_Init(199,7199);  //����Ƶ��PWMƵ��===(7200*200)/72000000=0.02=20ms
//	KEY_Init();         	    //��ʼ���밴�����ӵ�Ӳ���ӿ�
	//EXTIX_Init();		          //�жϳ�ʼ��
	 usart1_init(115200);	 //����1��ʼ��Ϊ115200
	USART3_Init(9600);     //����3��ʼ��Ϊ9622
//	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
//	EXTIX_Init();  
	 
	 
 
 
   	while(1)
	{
		
//		PAout (9) =1;
//		delay_ms (200);
	//PAout (9)=0;PAout (10)=0;
//		delay_ms (200);
	//		CarGo();

//		delay_ms(800);
//		CarLeft ();
//		delay_ms(800);	
		
		
								if(  USART1_RX_BUF[0]=='1' )      
							{ delay_ms(50);	USART1_RX_STA=0;
								if(  USART1_RX_BUF[0]=='1' )      
								 {	delay_ms(50);	USART1_RX_STA=0;										
										while(  USART1_RX_BUF[0]=='1' )  
										{if(PAin(5)==0&&PBin(12)==0)        
											{if(PAin(2)==1&&PAin(3)==1&&aaa==1)       
											{CarDT();aaa=0;ccc=1;delay_ms(280);
											CarGo();delay_ms(80);}
											else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       
											{CarDT1();aaa=3;delay_ms(280);
														CarGo();delay_ms(80);}
													else if(PBin(12)==1&&bbb==3)
														{CarStop();PAin (10)=1;
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);}			
														else if(PAin(2)==0&&PAin(3)==1)
														{CarRight();delay_ms(3);}
														else if(PAin(2)==1&&PAin(3)==0)
														{CarLeft();delay_ms(3);}
														else
														{CarGo();delay_ms(3);}}
											else if(PAin (5)==0&&PBin (12)==1)
														{if(bbb==1)
															{  CarStop ();delay_ms(1200);CarGo();
																 delay_ms(600);bbb=0;}
															 else if(bbb==0)
															 {PAout(9)=1;CarStop();aaa=2;
																 ccc=2;bbb=3;
														delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
																 PAout (9)=0;
														delay_ms(400);
															CarDT();
															delay_ms(620);CarGo();
															delay_ms(100);}}
														else if(PAin(5)==1)    
											{if(aaa==1)
												{CarStop ();delay_ms (10);}
												else if(PAin(2)==1&&PAin(3)==1&&aaa==2)      
														{aaa=3;CarDT1();
														delay_ms(280);
														CarGo();delay_ms(80);}
														else if(PBin(12)==1&&bbb==3)
														{CarStop();PAin (10)=1;
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);}			
														else if(PAin(2)==0&&PAin(3)==1)
														{CarRight();delay_ms(3);}
														else if(PAin(2)==1&&PAin(3)==0)
														{CarLeft();delay_ms(3);}
														else{CarGo();delay_ms(3);	}	}	}}}	
							
										 
								
											if(  USART1_RX_BUF[0]=='2' )      
							{     
										delay_ms(50);
										USART1_RX_STA=0;
								if(  USART1_RX_BUF[0]=='2' )      
								 {
										delay_ms(50);
										USART1_RX_STA=0;
										
										while(  USART1_RX_BUF[0]=='2' )  
										{
												if(PAin(5)==0&&PBin(12)==0)        //5�л�  12�޺���
											{

												
											   if(PAin(2)==1&&PAin(3)==1&&aaa==1)       //����⵽����  ʮ��·��  ��
														{
															CarDT1();
															aaa=0;
															ccc=1;
														//delay_ms(800);
														 delay_ms(270);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //����⵽����  ʮ��·��  ��
														{
															CarDT();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														
													
														else if(PBin(12)==1&&bbb==3)
														{
														  CarStop();
															PAin (10)=1;
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
														}			
														
																
														else if(PAin(2)==0&&PAin(3)==1)
														{CarRight();
														delay_ms(3);
														}
														else if(PAin(2)==1&&PAin(3)==0)
														{CarLeft();
														delay_ms(3);}
														else
														{CarGo();
														delay_ms(3);			
														}										
											      }
											
														else if(PAin (5)==0&&PBin (12)==1)
														{
														if(bbb==1)
														   {  CarStop ();
																 delay_ms(1200); 																  
															 CarGo();
																 delay_ms(600);
																 bbb=0;
															 }
															 else if(bbb==0)
															 {PAout(9)=1;
															 CarStop();
															aaa=2;
																 ccc=2;
																 bbb=3;
														delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
																 PAout (9)=0;
														delay_ms(400);
															CarDT1();
															delay_ms(650);
															//delay_ms(200);
															CarGo();
															delay_ms(100);
															 }	
														}						
														
											  else if(PAin(5)==1)        //�޻�
											{
												
												
												if(aaa==1)
												{
												CarStop ();
													delay_ms (10);
												
												}
													
											   else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //����⵽����  ʮ��·��  ���
														{
															
															aaa=3;
															CarDT();
														
														//delay_ms(800);
														delay_ms(280);
															CarGo();
															delay_ms(80);
																										
														}												
														
														else if(PBin(12)==1&&bbb==3)
														{
														  CarStop();
															PAin (10)=1;
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
														}			
														
																								
												
														else if(PAin(2)==0&&PAin(3)==1)
														{CarRight();
														delay_ms(3);
														}
														else if(PAin(2)==1&&PAin(3)==0)
														{CarLeft();
														delay_ms(3);}
														else
														{CarGo();
														delay_ms(3);			
														}	
											}	
														
											
	
	                   }}}	

										 if(  USART1_RX_BUF[0]=='3' )      
							{     
										delay_ms(50);
										USART1_RX_STA=0;
								if(  USART1_RX_BUF[0]=='3' )      
								 {
										delay_ms(50);
										USART1_RX_STA=0;
										
										while(  USART1_RX_BUF[0]=='3' )  
										{
											if(PAin(5)==0&&PBin(12)==0)        //5�л�  12�޺���
											{
		
												
											   if(PAin(2)==1&&PAin(3)==1&&aaa==5)       //����⵽����  ʮ��·��  ���
														{
															CarDT();
															aaa=0;
															ccc=1;
														//delay_ms(800);
														 delay_ms(280);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //����⵽����  ʮ��·��  �ҹ�
														{
															CarDT1();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(80);aaa=8;
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==1)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(80);aaa=5;
														}
														
														
//													else	if(PAin(2)==1&&PAin(3)==1&&aaa==0&&ccc==1)       //����⵽����  ʮ��·��  ���
//														{PAout (9)=1;
//															CarStop();
//															aaa=2;
//															ccc=2;
//														delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															PAout(9)=0;
//														delay_ms(400);
//															CarDT();
//															delay_ms(620);
//															//delay_ms(200);
//															CarGo();
//															delay_ms(100);
//														}
														else if(PBin(12)==1&&bbb==2)
														{
														  CarStop();
															PAin (10)=1;
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
														}			
														
														
														else if(PAin(2)==0&&PAin(3)==1)
														{CarRight();
														delay_ms(3);
														}
														else if(PAin(2)==1&&PAin(3)==0)
														{CarLeft();
														delay_ms(3);}
														else
														{CarGo();
														delay_ms(3);			
														}										
											      }
											
														else if(PAin (5)==0&&PBin (12)==1)
														{
														if(bbb==1)
														   {  CarStop ();
																 delay_ms(1200); 
																  
															 CarGo();
																 delay_ms(600);
																 bbb=0;
															 }
															 else if(bbb==0)
															 {PAout(9)=1;
															 CarStop();
															aaa=2;
																 ccc=2;bbb=2;
														delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
																 PAout (9)=0;
														delay_ms(400);
															CarDT();
															delay_ms(620);
															//delay_ms(200);
															CarGo();
															delay_ms(100);
															 }	
														}						
														
											  else if(PAin(5)==1)        //�޻�
											{
												
												
												if(aaa==1)
												{
												CarStop ();
													delay_ms (10);
												
												}
													
											   else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //����⵽����  ʮ��·��  �ҹ�
														{
															CarDT1();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(80);aaa=8;
														}										
														
														else if(PBin(12)==1&&bbb==2)
														{
														  CarStop();
															PAin (10)=1;
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
														}			
														
																								
												
														else if(PAin(2)==0&&PAin(3)==1)
														{CarRight();
														delay_ms(3);
														}
														else if(PAin(2)==1&&PAin(3)==0)
														{CarLeft();
														delay_ms(3);}
														else
														{CarGo();
														delay_ms(3);			
														}	
											}	
														
											
	
	                   }}}
							
											if(  USART1_RX_BUF[0]=='4' )      
							{     
										delay_ms(50);
										USART1_RX_STA=0;
								if(  USART1_RX_BUF[0]=='4' )      
								 {
										delay_ms(50);
										USART1_RX_STA=0;
										
										while(  USART1_RX_BUF[0]=='4' )  
										{
											if(PAin(5)==0&&PBin(12)==0)        //5�л�  12�޺���
											{
												

											   if(PAin(2)==1&&PAin(3)==1&&aaa==5)       //����⵽����  ʮ��·��  ���
														{
															CarDT1();
															aaa=0;
															ccc=1;
														//delay_ms(800);
														 delay_ms(270);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //����⵽����  ʮ��·��  �ҹ�
														{
															CarDT();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==1)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(80);aaa=5;
														}
														
														
//													else	if(PAin(2)==1&&PAin(3)==1&&aaa==0&&ccc==1)       //����⵽����  ʮ��·��  ���
//														{PAout (9)=1;
//															CarStop();
//															aaa=2;
//															ccc=2;
//														delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															PAout(9)=0;
//														delay_ms(400);
//															CarDT();
//															delay_ms(620);
//															//delay_ms(200);
//															CarGo();
//															delay_ms(100);
//														}
														else if(PBin(12)==1&&bbb==2)
														{
														  CarStop();
															PAin (10)=1;
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
														}			
														
//														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)
//														{
//														  CarStop();PAin (10)=1;
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//														}					
														else if(PAin(2)==0&&PAin(3)==1)
														{CarRight();
														delay_ms(3);
														}
														else if(PAin(2)==1&&PAin(3)==0)
														{CarLeft();
														delay_ms(3);}
														else
														{CarGo();
														delay_ms(3);			
														}										
											      }
											
														else if(PAin (5)==0&&PBin (12)==1)
														{
														if(bbb==1)
														   {  CarStop ();
																 delay_ms(1200); 
																  
															 CarGo();
																 delay_ms(600);
																 bbb=0;
															 }
															 else if(bbb==0)
															 {PAout(9)=1;
															 CarStop();
															aaa=2;
																 ccc=2;bbb=2;
														delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
																 PAout (9)=0;
														delay_ms(400);
															CarDT1();
															delay_ms(570);
															//delay_ms(200);
															CarGo();
															delay_ms(100);
															 }	
														}						
														
											  else if(PAin(5)==1)        //�޻�
											{
												
												
												if(aaa==1)
												{
												CarStop ();
													delay_ms (10);
												
												}
													
											   else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //����⵽����  ʮ��·��  �ҹ�
														{
															CarDT();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(80);
														}											
														
														else if(PBin(12)==1&&bbb==2)
														{
														  CarStop();
															PAin (10)=1;
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
														}			
														
//														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)
//														{
//														  CarStop();PAin (10)=1;
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//														}												
												
														else if(PAin(2)==0&&PAin(3)==1)
														{CarRight();
														delay_ms(3);
														}
														else if(PAin(2)==1&&PAin(3)==0)
														{CarLeft();
														delay_ms(3);}
														else
														{CarGo();
														delay_ms(3);			
														}	
											}	
														
											
	
	                   }}}		
													
													
											if(  USART1_RX_BUF[0]=='5' )      
							{     
										delay_ms(50);
										USART1_RX_STA=0;
								if(  USART1_RX_BUF[0]=='5' )      
								 {
										delay_ms(50);
										USART1_RX_STA=0;
										
										while(  USART1_RX_BUF[0]=='5' )  
										{
												if(PAin(5)==0&&PBin(12)==0)        //5�л�  12�޺���
											{
			
												
											   if(PAin(2)==1&&PAin(3)==1&&aaa==6)       //����⵽����  ʮ��·��  ���
														{
															CarDT();
															aaa=2;
															ccc=1;
														//delay_ms(800);
														 delay_ms(300);
															
															CarGo();
															delay_ms(80);
														}
														if(PAin(2)==1&&PAin(3)==1&&aaa==1)       //����⵽����  ʮ��·��  ���
														{
															
															
															CarGo();
															delay_ms(130);
															aaa=5;
														}
														if(PAin(2)==1&&PAin(3)==1&&aaa==5)       //����⵽����  ʮ��·��  ���
														{
															
															
															CarGo();
															delay_ms(130);
															aaa=6;
														}
														
														else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //����⵽����  ʮ��·��  �ҹ�
														{
															CarDT1();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(80);
															aaa=7;
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==7)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(130);
														}
														
//													else	if(PAin(2)==1&&PAin(3)==1&&aaa==0&&ccc==1)       //����⵽����  ʮ��·��  ���
//														{PAout (9)=1;
//															CarStop();
//															aaa=2;
//															ccc=2;
//														delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															PAout(9)=0;
//														delay_ms(400);
//															CarDT();
//															delay_ms(640);
//															//delay_ms(200);
//															CarGo();
//															delay_ms(100);
//														}
														else if(PBin(12)==1&&bbb==2)
														{
														  CarStop();
															PAin (10)=1;
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
														}			
														
//														else if(PAin(2)==1&&PAin(3)==1&&aaa==7)
//														{
//														  CarStop();PAin (10)=1;
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//														}					
														else if(PAin(2)==0&&PAin(3)==1)
														{CarRight();
														delay_ms(3);
														}
														else if(PAin(2)==1&&PAin(3)==0)
														{CarLeft();
														delay_ms(3);}
														else
														{CarGo();
														delay_ms(3);			
														}										
											      }
											
														else if(PAin (5)==0&&PBin (12)==1)
														{
														if(bbb==1)
														   {  CarStop ();
																 delay_ms(1200); 
																  
															 CarGo();
																 delay_ms(600);
																 bbb=0;
															 }
															 else if(bbb==0&&ccc==1)
															 {PAout(9)=1;
															 CarStop();
															aaa=2;
																 ccc=2;bbb=2;
														delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
																 PAout (9)=0;
														delay_ms(400);
															CarDT();
															delay_ms(640);
															//delay_ms(200);
															CarGo();
															delay_ms(100);
															 }	
														}						
														
											  else if(PAin(5)==1)        //�޻�
											{
												
												
												if(aaa==1)
												{
												CarStop ();
													delay_ms (10);
												
												}
													
											   else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //����⵽����  ʮ��·��  �ҹ�
														{
															CarDT1();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(80);
															aaa=7;
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==7)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(130);
														}										
														
														else if(PBin(12)==1&&bbb==2)
														{
														  CarStop();
															PAin (10)=1;
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
														}			
														
//														else if(PAin(2)==1&&PAin(3)==1&&aaa==7)
//														{
//														  CarStop();PAin (10)=1;
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//														}												
												
														else if(PAin(2)==0&&PAin(3)==1)
														{CarRight();
														delay_ms(3);
														}
														else if(PAin(2)==1&&PAin(3)==0)
														{CarLeft();
														delay_ms(3);}
														else
														{CarGo();
														delay_ms(3);			
														}	
											}	
														
											
	
	                   }}}	
	                      
							          
										if(  USART1_RX_BUF[0]=='6' )      
							{     
										delay_ms(50);
										USART1_RX_STA=0;
								if(  USART1_RX_BUF[0]=='6' )      
								 {
										delay_ms(50);
										USART1_RX_STA=0;
										
										while(  USART1_RX_BUF[0]=='6' )  
										{
											if(PAin(5)==0&&PBin(12)==0)        //5�л�  12�޺���
											{
			
												
											   if(PAin(2)==1&&PAin(3)==1&&aaa==6)       //����⵽����  ʮ��·��  ���
														{
															CarDT1();
															aaa=2;
															ccc=1;
														//delay_ms(800);
														 delay_ms(270);
															
															CarGo();
															delay_ms(130);
														}
														if(PAin(2)==1&&PAin(3)==1&&aaa==1)       //����⵽����  ʮ��·��  ���
														{
															
															
															CarGo();
															delay_ms(80);
															aaa=5;
														}
														if(PAin(2)==1&&PAin(3)==1&&aaa==5)       //����⵽����  ʮ��·��  ���
														{
															
															
															CarGo();
															delay_ms(80);
															aaa=6;
														}
														
														else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //����⵽����  ʮ��·��  �ҹ�
														{
															CarDT();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(80);
															aaa=7;
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==7)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(80);
														}
														
//													else	if(PAin(2)==1&&PAin(3)==1&&aaa==0&&ccc==1)       //����⵽����  ʮ��·��  ���
//														{PAout (9)=1;
//															CarStop();
//															aaa=2;
//															ccc=2;
//														delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															PAout(9)=0;
//														delay_ms(400);
//															CarDT();
//															delay_ms(640);
//															//delay_ms(200);
//															CarGo();
//															delay_ms(100);
//														}
														else if(PBin(12)==1&&bbb==2)
														{
														  CarStop();
															PAin (10)=1;
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
														}			
														
//														else if(PAin(2)==1&&PAin(3)==1&&aaa==7)
//														{
//														  CarStop();PAin (10)=1;
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//														}					
														else if(PAin(2)==0&&PAin(3)==1)
														{CarRight();
														delay_ms(3);
														}
														else if(PAin(2)==1&&PAin(3)==0)
														{CarLeft();
														delay_ms(3);}
														else
														{CarGo();
														delay_ms(3);			
														}										
											      }
											
														else if(PAin (5)==0&&PBin (12)==1)
														{
														if(bbb==1)
														   {  CarStop ();
																 delay_ms(1200); 
																  
															 CarGo();
																 delay_ms(600);
																 bbb=0;
															 }
															 else if(bbb==0&&ccc==1)
															 {PAout(9)=1;
															 CarStop();
															aaa=2;
																 ccc=2;bbb=2;
														delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
																 PAout (9)=0;
														delay_ms(400);
															CarDT1();
															delay_ms(570);
															//delay_ms(200);
															CarGo();
															delay_ms(100);
															 }	
														}						
														
											  else if(PAin(5)==1)        //�޻�
											{
												
												
												if(aaa==1)
												{
												CarStop ();
													delay_ms (10);
												
												}
													
											   else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //����⵽����  ʮ��·��  �ҹ�
														{
															CarDT();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(80);
															aaa=7;
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==7)       //����⵽����  ʮ��·��  �ҹ�
														{
															
															
															CarGo();
															delay_ms(80);
														}												
														
														else if(PBin(12)==1&&bbb==2)
														{
														  CarStop();
															PAin (10)=1;
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
														}			
														
//														else if(PAin(2)==1&&PAin(3)==1&&aaa==7)
//														{
//														  CarStop();PAin (10)=1;
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//															delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);delay_ms(800);
//														}												
												
														else if(PAin(2)==0&&PAin(3)==1)
														{CarRight();
														delay_ms(3);
														}
														else if(PAin(2)==1&&PAin(3)==0)
														{CarLeft();
														delay_ms(3);}
														else
														{CarGo();
														delay_ms(3);			
														}	
											}	
														
											
	
	                   }}}	
												
	                          
 
		
									







USART1_RX_STA=0;
	}
}

