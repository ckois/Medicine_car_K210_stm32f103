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




//5.5日改
/************************************************
小车程序
本小车共用了5个光电管

平放2个光电管（名字叫KEY0和KEY1，写在主函数里）                   用于左右避障  
斜放3个光电管 （在中断函数里，分别是中断线2-4）      用于防坠落

key.c定义了两个管脚 分别是PA0 PA1(键值函数)
exti.c定义了3个管脚 分别是PA2 PA3 PA4(中断函数)
motor.c这是一个电机函数  里面将前进、倒退、左转、右转、大左转、大右转

驱动用的引脚（IN1,IN2,IN3,IN4）
//TIM3_CH1 PA6
//TIM3_CH2 PA7
//TIM3_CH3 PB0
//TIM3_CH4 PB1
我这个是用的PWM调速，采用定时器3，四个通道
************************************************/

 int main(void)
 {		
	 int aaa=1;
	 int bbb=1;
	 int ccc=1;
	 int ddd=1;
	 int i;
	delay_init();	    	 //延时函数初始化	  
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
  LED_Init();
  TIM3_PWM_Init(199,7199);  //不分频。PWM频率===(7200*200)/72000000=0.02=20ms
//	KEY_Init();         	    //初始化与按键连接的硬件接口
	//EXTIX_Init();		          //中断初始化
	 usart1_init(115200);	 //串口1初始化为115200
	USART3_Init(9600);     //串口3初始化为9622
//	LED_Init();		  	//初始化与LED连接的硬件接口
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
												if(PAin(5)==0&&PBin(12)==0)        //5有货  12无黑线
											{

												
											   if(PAin(2)==1&&PAin(3)==1&&aaa==1)       //都检测到红线  十字路口  右
														{
															CarDT1();
															aaa=0;
															ccc=1;
														//delay_ms(800);
														 delay_ms(270);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //都检测到红线  十字路口  拐
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
														
											  else if(PAin(5)==1)        //无货
											{
												
												
												if(aaa==1)
												{
												CarStop ();
													delay_ms (10);
												
												}
													
											   else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //都检测到红线  十字路口  左拐
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
											if(PAin(5)==0&&PBin(12)==0)        //5有货  12无黑线
											{
		
												
											   if(PAin(2)==1&&PAin(3)==1&&aaa==5)       //都检测到红线  十字路口  左拐
														{
															CarDT();
															aaa=0;
															ccc=1;
														//delay_ms(800);
														 delay_ms(280);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //都检测到红线  十字路口  右拐
														{
															CarDT1();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //都检测到红线  十字路口  右拐
														{
															
															
															CarGo();
															delay_ms(80);aaa=8;
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==1)       //都检测到红线  十字路口  右拐
														{
															
															
															CarGo();
															delay_ms(80);aaa=5;
														}
														
														
//													else	if(PAin(2)==1&&PAin(3)==1&&aaa==0&&ccc==1)       //都检测到红线  十字路口  左拐
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
														
											  else if(PAin(5)==1)        //无货
											{
												
												
												if(aaa==1)
												{
												CarStop ();
													delay_ms (10);
												
												}
													
											   else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //都检测到红线  十字路口  右拐
														{
															CarDT1();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //都检测到红线  十字路口  右拐
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
											if(PAin(5)==0&&PBin(12)==0)        //5有货  12无黑线
											{
												

											   if(PAin(2)==1&&PAin(3)==1&&aaa==5)       //都检测到红线  十字路口  左拐
														{
															CarDT1();
															aaa=0;
															ccc=1;
														//delay_ms(800);
														 delay_ms(270);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //都检测到红线  十字路口  右拐
														{
															CarDT();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //都检测到红线  十字路口  右拐
														{
															
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==1)       //都检测到红线  十字路口  右拐
														{
															
															
															CarGo();
															delay_ms(80);aaa=5;
														}
														
														
//													else	if(PAin(2)==1&&PAin(3)==1&&aaa==0&&ccc==1)       //都检测到红线  十字路口  左拐
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
														
											  else if(PAin(5)==1)        //无货
											{
												
												
												if(aaa==1)
												{
												CarStop ();
													delay_ms (10);
												
												}
													
											   else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //都检测到红线  十字路口  右拐
														{
															CarDT();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //都检测到红线  十字路口  右拐
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
												if(PAin(5)==0&&PBin(12)==0)        //5有货  12无黑线
											{
			
												
											   if(PAin(2)==1&&PAin(3)==1&&aaa==6)       //都检测到红线  十字路口  左拐
														{
															CarDT();
															aaa=2;
															ccc=1;
														//delay_ms(800);
														 delay_ms(300);
															
															CarGo();
															delay_ms(80);
														}
														if(PAin(2)==1&&PAin(3)==1&&aaa==1)       //都检测到红线  十字路口  左拐
														{
															
															
															CarGo();
															delay_ms(130);
															aaa=5;
														}
														if(PAin(2)==1&&PAin(3)==1&&aaa==5)       //都检测到红线  十字路口  左拐
														{
															
															
															CarGo();
															delay_ms(130);
															aaa=6;
														}
														
														else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //都检测到红线  十字路口  右拐
														{
															CarDT1();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //都检测到红线  十字路口  右拐
														{
															
															
															CarGo();
															delay_ms(80);
															aaa=7;
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==7)       //都检测到红线  十字路口  右拐
														{
															
															
															CarGo();
															delay_ms(130);
														}
														
//													else	if(PAin(2)==1&&PAin(3)==1&&aaa==0&&ccc==1)       //都检测到红线  十字路口  左拐
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
														
											  else if(PAin(5)==1)        //无货
											{
												
												
												if(aaa==1)
												{
												CarStop ();
													delay_ms (10);
												
												}
													
											   else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //都检测到红线  十字路口  右拐
														{
															CarDT1();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //都检测到红线  十字路口  右拐
														{
															
															
															CarGo();
															delay_ms(80);
															aaa=7;
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==7)       //都检测到红线  十字路口  右拐
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
											if(PAin(5)==0&&PBin(12)==0)        //5有货  12无黑线
											{
			
												
											   if(PAin(2)==1&&PAin(3)==1&&aaa==6)       //都检测到红线  十字路口  左拐
														{
															CarDT1();
															aaa=2;
															ccc=1;
														//delay_ms(800);
														 delay_ms(270);
															
															CarGo();
															delay_ms(130);
														}
														if(PAin(2)==1&&PAin(3)==1&&aaa==1)       //都检测到红线  十字路口  左拐
														{
															
															
															CarGo();
															delay_ms(80);
															aaa=5;
														}
														if(PAin(2)==1&&PAin(3)==1&&aaa==5)       //都检测到红线  十字路口  左拐
														{
															
															
															CarGo();
															delay_ms(80);
															aaa=6;
														}
														
														else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //都检测到红线  十字路口  右拐
														{
															CarDT();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //都检测到红线  十字路口  右拐
														{
															
															
															CarGo();
															delay_ms(80);
															aaa=7;
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==7)       //都检测到红线  十字路口  右拐
														{
															
															
															CarGo();
															delay_ms(80);
														}
														
//													else	if(PAin(2)==1&&PAin(3)==1&&aaa==0&&ccc==1)       //都检测到红线  十字路口  左拐
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
														
											  else if(PAin(5)==1)        //无货
											{
												
												
												if(aaa==1)
												{
												CarStop ();
													delay_ms (10);
												
												}
													
											   else if(PAin(2)==1&&PAin(3)==1&&aaa==2)       //都检测到红线  十字路口  右拐
														{
															CarDT();
															aaa=3;
														delay_ms(280);
														//delay_ms(225);
															
															CarGo();
															delay_ms(80);
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==3)       //都检测到红线  十字路口  右拐
														{
															
															
															CarGo();
															delay_ms(80);
															aaa=7;
														}
														else if(PAin(2)==1&&PAin(3)==1&&aaa==7)       //都检测到红线  十字路口  右拐
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

