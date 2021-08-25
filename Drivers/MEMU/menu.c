/**
  ******************************************************************************
  * @file			menu.c
  * @brief		存放菜单刷新函数与中断回调函数
  * @version	V0.3
  * @date			2021年8月19日
  ******************************************************************************
  * @attention		使用方法 在主函数中引用此文件 
	*								注意使用STM32CubeMX重新生成后
	*								要在HAL_GPIO_EXTI_IRQHandler()中注释清除标志位
	*								防止多次进入中断
  ******************************************************************************
  */

#include "ssd1306.h"
#include <stdio.h>
#include "menu.h"

//#define DebugMode

/*调试模式:在屏幕打印菜单层级
并在屏幕更新时闪烁LED灯
在需要时取消注释
*/

MenuTypedef menu={0}; 
//声明菜单结构体类型变量


float P=0.0,I=0.0,D=0.0;
char cP[10],cI[10],cD[10];
//PID调参显示所需的变量


char* line1;
char* line2;
char* line3;
char* line4;
char* line5;
char* line6;
char* line7;
char* line8;
char* line9;
//用于装填需要显示的内容



void RenewMenu(int depth,int select,int tag)
{


		ClearScreen();
		switch (depth)
		{
			
			case 0:
				AddScreen("Init Complete.",0,0);
				AddScreen("Tap OK",0,10);
				AddScreen("to Select Mode",0,20);
				break;
			
			case 1:
				line1="Please Select";
				line2="Using Up and Down";
				line3="Set P";
				line4="Set I";
				line5="Set D";
				line6="MODE 1";
				line7="MODE 2";
				line8="MODE 3";
				line9="MODE 4";
			
			switch (select)
			{
				case 0:
					AddScreen(line1,0,0);
					AddScreen(line2,0,10);
							switch(tag)
							{
								case 0:
									AddScreen(line3,1,21);
									AddScreen(line4,1,36);
									AddScreen(line5,1,52);
									break;
								
								case 1:
									AddScreenR(line3,1,21);
									AddScreen(line4,1,36);
									AddScreen(line5,1,52);		
									break;
								
								case 2:
									AddScreen(line3,1,21);
									AddScreenR(line4,1,36);
									AddScreen(line5,1,52);
									break;
								
								case 3:
									AddScreen(line3,1,21);
									AddScreen(line4,1,36);
									AddScreenR(line5,1,52);
									break;
								
								case 4:
									AddScreenR(line6,1,21);
									AddScreen(line7,1,36);
									AddScreen(line8,1,52);
									break;
								
								case 5:
									AddScreen(line6,1,21);
									AddScreenR(line7,1,36);
									AddScreen(line8,1,52);
									break;
								
								case 6:
									AddScreen(line6,1,21);
									AddScreen(line7,1,36);
									AddScreenR(line8,1,52);
									break;
							}		
					break;
				}
				break;
					
			case 2:
				sprintf(cP,"%.1f",P);
				sprintf(cI,"%.2f",I);
				sprintf(cD,"%.1f",D);
				
				if(select<=3&&select>0)
				{					
					ssd1306_SetCursor(0,0);
					ssd1306_WriteString("P",Font_16x26,White);
					ssd1306_UpdateScreen();
					
					ssd1306_SetCursor(41,0);
					ssd1306_WriteString("I",Font_16x26,White);
					ssd1306_UpdateScreen();
					
					ssd1306_SetCursor(82,0);
					ssd1306_WriteString("D",Font_16x26,White);
					ssd1306_UpdateScreen();
				}
				switch(select)
				{					
					case 1:
					AddScreenR(cP,1,40);
					AddScreen(cI,42,40);
					AddScreen(cD,83,40);
					break;
					
					case 2:
					AddScreen(cP,1,40);
					AddScreenR(cI,42,40);
					AddScreen(cD,83,40);
					break;
				
					case 3:
					AddScreen(cP,1,40);
					AddScreen(cI,42,40);
					AddScreenR(cD,83,40);
					break;
								
					case 4:
					line1="You Choose";
					line2="       MODE 1 !";
					line3="Tap OK";
					line4="To Return";
					AddScreen(line1,0,0);
					AddScreen(line2,0,12);
					AddScreen(line3,0,30);
					AddScreen(line4,0,50);
					break;
					
					case 5:
					line1="You Choose";
					line2="       MODE 2 !";
					line3="Tap OK";
					line4="To Return";
					AddScreen(line1,0,0);
					AddScreen(line2,0,12);
					AddScreen(line3,0,30);
					AddScreen(line4,0,50);
					break;
					
					case 6:
					line1="You Choose";
					line2="       MODE 3 !";
					line3="Tap OK";
					line4="To Return";
					AddScreen(line1,0,0);
					AddScreen(line2,0,12);
					AddScreen(line3,0,30);
					AddScreen(line4,0,50);
					break;
					
				}
			break;
		}
		#ifdef DebugMode
		char a[20];
		extern MenuTypedef menu;
		sprintf(a,"%d,%d,%d",menu.depth,menu.select,menu.tag);
		AddScreen(a,50,50);
		#endif


}		


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{	
			
//	 HAL_Delay(50);
//	
//    if(HAL_GPIO_ReadPin(GPIOD,GPIO_Pin))
//    {
//	HAL_GPIO_TogglePin(GPIOD,GPIO_Pin);
//	HAL_Delay(100);
//    }

//		__HAL_GPIO_EXTI_CLEAR_IT(GPIO_Pin);
//		HAL_Delay(100);
//		另一种防抖方法，根据具体情况决定是否使用
	
	#define MENU_1_MAX 6 //某一级菜单的选项个数
	
	#ifdef DebugMode
	HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_12);
	#endif
	
	//关于菜单的判断
	switch (GPIO_Pin)
	{
		case OK:
		switch (menu.depth)
		{
			case 0:
			menu.depth++;
			menu.tag=1;
			break;
	
			case 1:
			menu.pselect=menu.select;
			menu.ptag=menu.tag;
			menu.select=menu.tag;
			menu.depth++;
			menu.tag=1;
			break;
		
			case 2:
			menu.select=menu.pselect;
			menu.tag=menu.ptag;
			menu.depth--;
			break;		
		}
		break;
	
		case UP:
		switch (menu.depth)
		{
			case 1:
			menu.tag=menu.tag-1;
			if((menu.tag<=0)||(menu.tag>MENU_1_MAX))
				menu.tag=1;
			break;
			case 2:
				switch (menu.select)
				{
					case 1:
					P=P+1.0f;
					break;
					
					case 2:
					I=I+0.1f;
					break;
					
					case 3:
					D=D+10.0f;
					break;
				}
		}
		break;
		
		case DOWN:
		switch (menu.depth)
		{
			case 1:
			menu.tag=menu.tag+1;
			if((menu.tag<=0)||(menu.tag>MENU_1_MAX))
				menu.tag=1;
			break;
			case 2:
			switch (menu.select)
				{
					case 1:
					P=P-1.0f;
					break;
					
					case 2:
					I=I-0.1f;
					break;
					
					case 3:
					D=D-10.0f;
					break;
				}
			break;
		}
		break;
	}

	RenewMenu(menu.depth,menu.select,menu.tag);
		
	HAL_Delay(150);
	
	//在HAL_GPIO_EXTI_IRQHandler()中注释清除标志位并在此添加，防止多次进入中断
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_Pin);
		
}
