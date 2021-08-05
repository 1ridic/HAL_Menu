#define OK GPIO_PIN_15
#define RIGHT GPIO_PIN_14
#define LEFT GPIO_PIN_13
#define UP GPIO_PIN_11
#define DOWN GPIO_PIN_12



//菜单更新
void RenewMenu(int depth,int select,int tag);

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
