#include "MainTank.h"



void MainTank::SetDir(Dir dir)
{
	my_dir = dir;
}



void MainTank::DrawTankBody()
{
	fillrectangle(my_pos.GetX() - 6, my_pos.GetY() - 6, my_pos.GetX() + 6, my_pos.GetY() + 6);

	/**switch (my_dir)
	{
	case UP:
	case DOWN:
		fillrectangle(my_rectSphere.GetStartPoint().GetX(), my_rectSphere.GetStartPoint().GetY(),
			my_rectSphere.GetStartPoint().GetX() + 4, my_rectSphere.GetEndPoint().GetY());
		fillrectangle(my_rectSphere.GetEndPoint().GetX() - 4, my_rectSphere.GetStartPoint().GetY(),
			my_rectSphere.GetEndPoint().GetX(), my_rectSphere.GetEndPoint().GetY());
		break;
	case LEFT:
	case RIGHT:
		fillrectangle(my_rectSphere.GetStartPoint().GetX(), my_rectSphere.GetStartPoint().GetY(),
			my_rectSphere.GetEndPoint().GetX(), my_rectSphere.GetStartPoint().GetY() + 4);
		fillrectangle(my_rectSphere.GetStartPoint().GetX(), my_rectSphere.GetEndPoint().GetY() - 4,
			my_rectSphere.GetEndPoint().GetX(), my_rectSphere.GetEndPoint().GetY());
		break;
	default:
		break;
	}**/


	//注意改动
	switch (my_dir)
	{
	case UP: 
		fillrectangle(my_pos.GetX() + 8, my_pos.GetY() + 8, my_pos.GetX() + 12, my_pos.GetY() - 8);
		fillrectangle(my_pos.GetX() - 12, my_pos.GetY() + 8, my_pos.GetX() - 8, my_pos.GetY() - 8);
		break;

    case DOWN:
        fillrectangle(my_pos.GetX() + 8, my_pos.GetY() + 8, my_pos.GetX() + 12, my_pos.GetY() - 8);
		fillrectangle(my_pos.GetX() - 12, my_pos.GetY()+8, my_pos.GetX() - 8, my_pos.GetY() - 8);
		break;

	case LEFT:
        fillrectangle(my_pos.GetX() - 8, my_pos.GetY() + 12, my_pos.GetX() + 8, my_pos.GetY() + 8);
		fillrectangle(my_pos.GetX() - 8, my_pos.GetY() - 8, my_pos.GetX() + 8, my_pos.GetY() - 12);
		break;

	case RIGHT:
		fillrectangle(my_pos.GetX() - 8, my_pos.GetY() + 12, my_pos.GetX() + 8, my_pos.GetY() + 8);
		fillrectangle(my_pos.GetX() - 8, my_pos.GetY() - 8, my_pos.GetX() + 8,  my_pos.GetY() - 12);
		break;

	default:
		break;
		
	}
}

void MainTank::Display()
{

	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(my_color);
	setcolor(my_color);

	DrawTankBody();

	//坦克炮筒
	switch (my_dir)
	{
	case UP:
		line(my_pos.GetX(), my_pos.GetY(), my_pos.GetX(), my_pos.GetY() - 15);
		break;

	case DOWN:
		line(my_pos.GetX(), my_pos.GetY(), my_pos.GetX(), my_pos.GetY() + 15);
		break;

	case LEFT:
		line(my_pos.GetX(), my_pos.GetY(), my_pos.GetX() - 15, my_pos.GetY());
		break;

	case RIGHT:
		line(my_pos.GetX(), my_pos.GetY(), my_pos.GetX() + 15, my_pos.GetY());
		break;

	default:
		break;
	}

	setcolor(color_save);
	setfillcolor(fill_color_save);

}

void MainTank::Move()
{
	switch (my_dir)
	{

	case UP:
	{
	my_pos.SetY(my_pos.GetY() - my_step);
	if (my_pos.GetY() < 20)
	{
		my_pos.SetY(my_pos.GetY() + my_step);
	}

	//障碍物设置
	if (112 < my_pos.GetX() && my_pos.GetX() < 308)
	{
		if (380 < my_pos.GetY() && my_pos.GetY() < 392)
		{
			my_pos.SetY(my_pos.GetY() + my_step);
		}
	}

	if (272 < my_pos.GetX() && my_pos.GetX() < 432)
	{
		if (180 < my_pos.GetY() && my_pos.GetY() < 192)
		{
			my_pos.SetY(my_pos.GetY() + my_step);
		}
	}

	if (432 < my_pos.GetX() && my_pos.GetX() < 468)
	{
		if (340 < my_pos.GetY() && my_pos.GetY() < 352)
		{
			my_pos.SetY(my_pos.GetY() + my_step);
		}
	}

	//river
	if (332 < my_pos.GetX() && my_pos.GetX() < 388)
	{
		if (280 < my_pos.GetY() && my_pos.GetY() < 292)
		{
			my_pos.SetY(my_pos.GetY() + my_step);
		}
	}
	}
		break;



	case DOWN:
		my_pos.SetY(my_pos.GetY() + my_step);
		if (my_pos.GetY() > 520)
			my_pos.SetY(my_pos.GetY() - my_step);

		


		if (272 < my_pos.GetX() && my_pos.GetX() < 468)
		{
			if (148 < my_pos.GetY() && my_pos.GetY() < 160)
			{
				my_pos.SetY(my_pos.GetY() - my_step);
			}
		}

		if (112 < my_pos.GetX() && my_pos.GetX() < 148)
		{
			if (188 < my_pos.GetY() && my_pos.GetY() < 200)
			{
				my_pos.SetY(my_pos.GetY() - my_step);
			}
		}

		if (148 < my_pos.GetX() && my_pos.GetX() < 308)
		{
			if (348 < my_pos.GetY() && my_pos.GetY() < 360)
			{
				my_pos.SetY(my_pos.GetY() - my_step);
			}
		}

		//river
		if (332 < my_pos.GetX() && my_pos.GetX() < 388)
		{
			if (228 < my_pos.GetY() && my_pos.GetY() < 240)
			{
				my_pos.SetY(my_pos.GetY() - my_step);
			}
		}
			
		break;

	case LEFT:
		my_pos.SetX(my_pos.GetX() - my_step);
		if (my_pos.GetX() < 20)
			my_pos.SetX(my_pos.GetX() + my_step);



		if (460 < my_pos.GetX() && my_pos.GetX() < 472)
		{
			if (152 < my_pos.GetY() && my_pos.GetY() < 348)
			{
				my_pos.SetX(my_pos.GetX() + my_step);
			}
		}

		if (300 < my_pos.GetX() && my_pos.GetX() < 312)
		{
			if (352 < my_pos.GetY() && my_pos.GetY() < 388)
			{
				my_pos.SetX(my_pos.GetX() + my_step);
			}
		}

		if (140 < my_pos.GetX() && my_pos.GetX() < 152)
		{
			if (192 < my_pos.GetY() && my_pos.GetY() < 352)
			{
				my_pos.SetX(my_pos.GetX() + my_step);
			}
		}
			//river
		if (380 < my_pos.GetX() && my_pos.GetX() < 392)
		{
			if (232 < my_pos.GetY() && my_pos.GetY() < 288)
			{
				my_pos.SetX(my_pos.GetX() + my_step);
			}
		}
		
		break;

	case RIGHT:
		my_pos.SetX(my_pos.GetX() + my_step);
		if (my_pos.GetX() > SCREEN_HEIGHT + BATTLEGROUND_LEFT)
			my_pos.SetX(my_pos.GetX() - my_step);
			//my_pos.SetX(5);

		if (108 < my_pos.GetX() && my_pos.GetX() < 120)
		{
			if (192 < my_pos.GetY() && my_pos.GetY() < 388)
			{
				my_pos.SetX(my_pos.GetX() - my_step);
			}
		}

		if (268 < my_pos.GetX() && my_pos.GetX() < 280)
		{
			if (152 < my_pos.GetY() && my_pos.GetY() < 188)
			{
				my_pos.SetX(my_pos.GetX() - my_step);
			}
		}

		if (428 < my_pos.GetX() && my_pos.GetX() < 440)
		{
			if (188 < my_pos.GetY() && my_pos.GetY() < 348)
			{
				my_pos.SetX(my_pos.GetX() - my_step);
			}
		}

		//river
		if (328 < my_pos.GetX() && my_pos.GetX() < 340)
		{
			if (232 < my_pos.GetY() && my_pos.GetY() < 288)
			{
				my_pos.SetX(my_pos.GetX() - my_step);
			}
		}
		break;
		
	default:
		break;
	}

	CalculateSphere();
}

void MainTank::CalculateSphere()
{
	switch (my_dir)
	{
	case UP:
	case DOWN:
		my_rectSphere.Set(my_pos.GetX() - 12, my_pos.GetY() - 8, my_pos.GetX() + 12, my_pos.GetY() + 8);
		break;
	case LEFT:
	case RIGHT:
		my_rectSphere.Set(my_pos.GetX() - 8, my_pos.GetY() - 12, my_pos.GetX() + 8, my_pos.GetY() + 12);
		break;
	default:
		break;
	}
}


void MainTank::Shoot(list<Object*>& listBullets)
{
	Bullet* pBullet = new Bullet(my_pos, my_dir, my_color);

	listBullets.push_back(pBullet);
}


