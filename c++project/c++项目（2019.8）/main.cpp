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

//��ս̹���ڵ�����
list<Object*> listMainTankBullets;
//�о�̹���ڵ�����
list<Object*> listBullets;

// �о�̹������
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
				drawtext(_T("̫�˿�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				
			}**/
			
				
			
		}
	}

}

/**void loadimage(
	IMAGE* pDstImg,		// ����ͼ��� IMAGE ����ָ��
	LPCTSTR pImgFile,		// ͼƬ�ļ���
	int nWidth = 0,		// ͼƬ��������
	int nHeight = 0,		// ͼƬ������߶�
	bool bResize = false	// �Ƿ���� IMAGE �Ĵ�С����ӦͼƬ
);**/


//cleardevice�Ĵ��淽��
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
	loadimage(&img1, _T("D:\\2D_TankWar\\c++project\\image\\����.jpg"), 800, 540, true);
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
				break;// ��ͣ--Enter
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
			

			BeginBatchDraw();//����������ڿ�ʼ������ͼ

			Graphic::DrawBattleGround();
			CheckCrash();

			maintank.Move();
			maintank.Display();
			

			
			RECT r = { 580,10,780,80 };
			drawtext("Xavi ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


            RECT r1 = { 580,100,780,160 };
			LPTSTR szBuffer = new TCHAR[100];
			wsprintf(szBuffer, _T("����ֵ: %d"), Set::GetLife());
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


			loadimage(&img1, _T("D:\\2D_TankWar\\c++project\\image\\tree.jpg"), 20, 20, true);//���Ļ���

			putimage(200, 300, &img1);
			putimage(200, 280, &img1);
			putimage(220, 280, &img1);
			putimage(220, 300, &img1);
		


			EndBatchDraw();//����������ڽ�����������

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