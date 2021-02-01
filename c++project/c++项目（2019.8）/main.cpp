#include<iostream>
#include <conio.h>
#include <time.h>
#include <list>
#include<stdio.h>
#include<graphics.h>
#include<stdio.h>
#define MAX_TANKS 10

#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"WinMM.Lib")




#include "Graphic.h"


#include "MainTank.h"
#include "Enemy.h"
#include "Check.h"
#include "Set.h"

using namespace std;



MainTank maintank;

//主战坦克炮弹链表
list<Object*> listMainTankBullets;
//敌军坦克炮弹链表
list<Object*> listBullets;

// 敌军坦克链表
list<Tank*> listTanks;


void CheckCrash()
{
	for (list<Object*>::iterator it = listMainTankBullets.begin(); it != listMainTankBullets.end(); it++)
	{
 		for (list<Tank*>::iterator ittt = listTanks.begin(); ittt != listTanks.end(); ittt++)
		{
			Rect a = (*it)->GetSphere(); Rect b = (*ittt)->GetSphere();
			if (Check::CheckIntersect(a, b))
			//if (Check::CheckIntersect((*it)->GetSphere(), (*itt)->GetSphere()))
			{
				(*ittt)->SetDisappear();
				(*it)->SetDisappear();
			}
		}
	}

	for (list<Object*>::iterator it = listBullets.begin(); it != listBullets.end(); it++)
	{
		Rect c = (*it)->GetSphere(); Rect d = maintank.GetSphere();
		if (Check::CheckIntersect( c , d))
		{
            // maintank.SetDisappear();
			 Graphic::DrawHit();
			 if (Set::GetLife() > 0)
			 {
				 (*it)->SetDisappear();
			 }

			Set::Hitted();
			/**if (Set::GetLife() <= 0)
			{
			
				RECT r = { 40, 40, 760, 500 };
				drawtext(_T("太菜咯"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				
			}**/
			
				
			
		}
	}

}

/**void loadimage(
	IMAGE* pDstImg,		// 保存图像的 IMAGE 对象指针
	LPCTSTR pImgFile,		// 图片文件名
	int nWidth = 0,		// 图片的拉伸宽度
	int nHeight = 0,		// 图片的拉伸高度
	bool bResize = false	// 是否调整 IMAGE 的大小以适应图片
);**/


//cleardevice的代替方法
void clearScreen() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };    // home for the cursor
	SetConsoleCursorPosition(hConsole, coordScreen);
}




int main()
{
	srand((unsigned)time(NULL));
	

	Graphic::Create();

	
	//PlaySound(TEXT("F:\\TWbgm.wav"), NULL, SND_FILENAME | SND_ASYNC);

	
	IMAGE img1;
	loadimage(&img1, _T("D:\\2D_TankWar\\c++project\\image\\封面.jpg"), 800, 540, true);
	putimage(0, 0, &img1);
	Sleep(2000);

	
	listMainTankBullets.clear();
	listTanks.clear();


	for (int i = 0; i < MAX_TANKS; i++)
	{
		Enemy* p = new Enemy();
		listTanks.push_back(p);
	}


    
	bool loop = true;
	bool skip = false;
    
	while (loop)
	{
		

		if (_kbhit())
		{
			int key = _getch();

			switch (key)
			{

			case 87:
				maintank.SetDir(Dir::UP);
				break;// Up--W

			case 83:
				maintank.SetDir(Dir::DOWN);
				break;// Down--S

			case 65:
				maintank.SetDir(Dir::LEFT);
				break;// Left--A

			case 68:
				maintank.SetDir(Dir::RIGHT);
				break;// Right--D

			case 27:
				loop = false;
				break;// Esc

			case 32:
				maintank.Shoot(listMainTankBullets);
				break;// Space

			case 13:
				if (skip)
					skip = false;
				else
					skip = true;
				break;// 暂停--Enter
			default:
				break;
			}
		}
		if (Set::GetLife() <= 0)
		{
			skip = true;
			Graphic::DrawGameOver();
		}


		if (!skip)
		{


		    cleardevice();
			

			BeginBatchDraw();//这个函数用于开始批量绘图

			Graphic::DrawBattleGround();
			CheckCrash();

			maintank.Move();
			maintank.Display();
			

			
			RECT r = { 580,10,780,80 };
			drawtext("Xavi ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


            RECT r1 = { 580,100,780,160 };
			LPTSTR szBuffer = new TCHAR[100];
			wsprintf(szBuffer, _T("生命值: %d"), Set::GetLife());
			drawtext(szBuffer, &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


			



			for (list<Tank*>::iterator it = listTanks.begin(); it != listTanks.end(); )
			{
				(*it)->Move();
				if ((*it)->IsDisappear())
				{
					
					// Delete the tank
					delete *it;
					it = listTanks.erase(it);
					continue;

				}
				(*it)->Display();

				if ((*it)->NeedShoot())
				{
					Enemy* p = (Enemy*)*it;
					p->Shoot(listBullets);
				}

				it++;
								
			}


			for (list<Object*>::iterator it = listMainTankBullets.begin(); it != listMainTankBullets.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{

					delete *it;
					it = listMainTankBullets.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}

			for (list<Object*>::iterator it = listBullets.begin(); it != listBullets.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
		

					// Delete the bullet
					delete *it;
					it = listBullets.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}


			loadimage(&img1, _T("D:\\2D_TankWar\\c++project\\image\\tree.jpg"), 20, 20, true);//树的绘制

			putimage(200, 300, &img1);
			putimage(200, 280, &img1);
			putimage(220, 280, &img1);
			putimage(220, 300, &img1);
		


			EndBatchDraw();//这个函数用于结束批量绘制

		}
		

		Sleep(5);
	}


	// Destroy
	for (list<Tank*>::iterator it = listTanks.begin(); it != listTanks.end(); it++)
	{
		delete *it;
	}
	listTanks.clear();

	for (list<Object*>::iterator it = listMainTankBullets.begin(); it != listMainTankBullets.end(); it++)
	{
		delete *it;
	}

	for (list<Object*>::iterator it = listBullets.begin(); it != listBullets.end(); it++)
	{
		delete *it;
	}
	listBullets.clear();
	
	Graphic::Destroy();

	return 0;

}