#include "ssd1306.h"
#include <stdio.h>
#include "menu.h"

//#define DebugMode


extern float P,I,D;
//extern int flag;
char cP[10],cI[10],cD[10];
char* line1;
char* line2;
char* line3;
char* line4;
char* line5;
char* line6;
char* line7;
char* line8;
char* line9;

void RenewMenu(int depth,int select,int tag)
{


//	if(flag==0)
//	{
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

//	}
}		