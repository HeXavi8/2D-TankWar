#ifndef graphic_h
#define graphic_h


#include<graphics.h>
#include"Position_Point.h"
#include"Rectangle.h"

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   540

#define BATTLEGROUND_LEFT 20
#define BATTLEGROUND_TOP 20
#define BATTLEGROUND_BOTTON 520
#define BATTLEGROUND_RIGHT (SCREEN_HEIGHT + BATTLEGROUND_LEFT)


class Graphic
{
public: 

	static void Create();
	static void Destroy();

	static void DrawBattleGround();
	static void DrawHit();
	static void DrawGameOver();

	static int GetScreenWidth();
	static int GetScreenHeight();

	//static int GetBattleGround();

	/**Graphic & operator=(const Graphic &rectangle)
	{
		my_BattleGround = rectangle.GetBattleGround();

		return *this;
	}**/



private:
	static  int my_Screen;

	

	//static  int my_BattleGround;
};

#endif