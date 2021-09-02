/**
  ******************************************************************************
  * @file			screen.c
  * @brief		菜单所用显示函数
  * @version	0.1
  * @date			Aug 25, 2021
  ******************************************************************************
  * @attention	
  *						菜单刷新所使用函数，功能已经写明，若使用不同的屏幕或驱动
							则根据需要修改
  ******************************************************************************
  */

#include "ssd1306.h"
#include "screen.h"

//在菜单中添加文字
void AddScreen(char* text,int x,int y)
{

		ssd1306_SetCursor(x,y);
		ssd1306_WriteString(text,Font_7x10,White);
		ssd1306_UpdateScreen();

}

//在菜单中添加反色文字
void AddScreenR(char* text,int x,int y)
{

		ssd1306_SetCursor(x,y);
		ssd1306_WriteString(text,Font_7x10,Black);
		ssd1306_UpdateScreen();

}
//清屏
void ClearScreen(void)
{
	ssd1306_SetCursor(0,0);
	ssd1306_Fill(Black);
	ssd1306_UpdateScreen();
}