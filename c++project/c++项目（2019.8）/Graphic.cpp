#include"Graphic.h"
#include "Set.h"

void Graphic::Create()
{
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	setbkcolor(BLACK);
	
}

void Graphic::Destroy()
{
	closegraph();
}

void Graphic::DrawBattleGround()
{
	rectangle(BATTLEGROUND_LEFT, BATTLEGROUND_TOP, BATTLEGROUND_RIGHT, BATTLEGROUND_BOTTON);

	IMAGE img;
	loadimage(&img, _T("D:\\2D_TankWar\\c++project\\image\\Tank.png"), 220, 116, true);
	putimage(580, 190, &img);

	loadimage(&img, _T("D:\\2D_TankWar\\c++project\\image\\1.jpg"), 54, 50, true);
	for (int r = 0; r <= 9; r++)
	{
		for (int l = 0; l <= 9; l++)
		{
			putimage(20+54*r, 20+50*l, &img);
		}
	}

    int a = 0, b = 0;
	loadimage(&img, _T("D:\\2D_TankWar\\c++project\\image\\qiang.jpg"), 20, 20, true);
	for (a=0; a <= 28; a++)
	{
		putimage(0 + 20 * a, 0, &img);
		putimage(0 + 20 * a, 520, &img);
	}
	for (b=0; b <= 28; b++)
	{
		putimage(0, 0 + 20 * b, &img);
		putimage(560, 0 + 20 * b, &img);
	}



	char s0[] = "太菜警告！：";
	outtextxy(600, 330, s0);
	rectangle(600, 350, 700, 390);

	char s1[] = "操作指示：";
	outtextxy(600, 400, s1);
	char s2[] = "W--向上";
	outtextxy(600, 420, s2);
	char s3[] = "S--向下";
	outtextxy(600, 440, s3);
	char s4[] = "A--向左";
	outtextxy(600, 460, s4);
	char s5[] = "D--向右";
	outtextxy(600, 480, s5);

	char s7[] = "Space--射击";
	outtextxy(700, 420, s7);
	char s8[] = "Enter--暂停";
	outtextxy(700, 440, s8);
	char s9[] = "Esc--退出";
	outtextxy(700, 460, s9);



    loadimage(&img, _T("D:\\2D_TankWar\\c++project\\image\\3.jpg"), 20, 20, true);
	for (a=0; a <= 8; a++)
	{
		putimage(120 + 20 * a, 360, &img);
		putimage(280 + 20 * a, 160, &img);
	}
	for (b = 0; b <= 8; b++)
	{
		putimage(440, 160 + 20 * b, &img);
		putimage(120, 360 - 20 * b, &img);
	}

	loadimage(&img, _T("D:\\2D_TankWar\\c++project\\image\\river.jpg"), 20, 20, true);
	putimage(340, 240, &img);
	putimage(360, 240, &img);
	putimage(340, 260, &img);
	putimage(360, 260, &img);
	
	

}

int Graphic::GetScreenWidth()
{
	return SCREEN_WIDTH;
}

int Graphic::GetScreenHeight()
{
	return SCREEN_HEIGHT;
}

/**int Graphic::GetBattleGround()
{
	return my_BattleGround;
}**/

void Graphic::DrawHit()
{
	//cleardevice();
	//settextstyle(30, 20, _T("宋体"));
	RECT r = { 600,350,700,390 };
	drawtext(_T("被击中!!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	

	//char s[] = "被击中!";
	//outtextxy(600, 350, s);
}



void Graphic::DrawGameOver()
{
	IMAGE img;
	loadimage(&img, _T("D:\\2D_TankWar\\c++project\\image\\GameOver.jpg"), 800, 540, true);
	putimage(0,0, &img);
	//cleardevice();

}


