/**
  ******************************************************************************
  * @file			menu.h
  * @brief		菜单模块头文件
  * @version	V0.3
  * @date			2021年8月19日
  ******************************************************************************
  * @attention		使用方法 在主函数中引用此文件 
	*								注意使用STM32CubeMX重新生成后
	*								要在HAL_GPIO_EXTI_IRQHandler()中注释清除标志位
	*								防止多次进入中断
  ******************************************************************************
  */

#ifndef _menu_h_
#define _munu_h_

#include "screen.h"

#define OK GPIO_PIN_15
#define RIGHT GPIO_PIN_14
#define LEFT GPIO_PIN_13
#define UP GPIO_PIN_11
#define DOWN GPIO_PIN_12
//定义引脚简称

#endif


/**
	* @brief 刷新屏幕 展示为菜单样式
  * @note None
  * @param	传入的参数分别为定位菜单层级的变量
  * @retval None
  */
void RenewMenu(int depth,int select,int tag);




/**
	* @brief 	菜单结构体类型定义
  * @note 	使用此类型标记菜单位置
  */
typedef struct
{
	
	//菜单标志位
	int depth;
	int select;
	int tag;
	
	
	//上一层级菜单标志位
	int pselect;
	int ptag;
	
	
	
} MenuTypedef;
