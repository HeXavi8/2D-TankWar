#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(Point pos, Dir dir, COLORREF color)
{
	my_pos = pos;
	my_dir = dir;
	my_color = color;
	my_step = 12;

	my_boolDisappear = false;

	CalculateSphere();
}

Bullet::~Bullet()
{

}


void Bullet::Display()  // 绘制
{
	COLORREF fill_color_save = getfillcolor();//这个函数用于获取当前的填充颜色
	COLORREF color_save = getcolor(); //这个函数用于获取当前绘图前景色
	my_color = YELLOW;
	setfillcolor(my_color);
	setcolor(my_color);

	fillcircle(my_pos.GetX() , my_pos.GetY() , 4);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}


void Bullet::Move()// 描述子弹的运动
{
	switch (my_dir)
	{
	case UP:
		my_pos.SetY(my_pos.GetY() - my_step);
		CalculateSphere();
		if (my_pos.GetY() < 20 )
		{
			my_boolDisappear = true;
		}

		//障碍物设置
		if (120 < my_pos.GetX() && my_pos.GetX() < 300)
		{
			if (360 < my_pos.GetY() && my_pos.GetY() < 380)
			{
				my_boolDisappear = true;
			}
		}

		if (280 < my_pos.GetX() && my_pos.GetX() < 440)
		{
			if (160 < my_pos.GetY() && my_pos.GetY() < 181)
			{
				my_boolDisappear = true;
			}
		}

		if (440 < my_pos.GetX() && my_pos.GetX() < 460)
		{
			if (320 < my_pos.GetY() && my_pos.GetY() < 341)
			{
				my_boolDisappear = true;
			}
		}
		break;
	case DOWN:
		my_pos.SetY(my_pos.GetY() + my_step);
		CalculateSphere();
		if (my_pos.GetY() > 520 )
		{
			my_boolDisappear = true;
		}

		if (280 < my_pos.GetX() && my_pos.GetX() < 460)
		{
			if (159 < my_pos.GetY() && my_pos.GetY() < 180)
			{
				my_boolDisappear = true;
			}
		}

		if (120 < my_pos.GetX() && my_pos.GetX() < 140)
		{
			if (199 < my_pos.GetY() && my_pos.GetY() < 220)
			{
				my_boolDisappear = true;
			}
		}

		if (140 < my_pos.GetX() && my_pos.GetX() < 300)
		{
			if (359 < my_pos.GetY() && my_pos.GetY() < 380)
			{
				my_boolDisappear = true;
			}
		}

		break;
	case LEFT:
		my_pos.SetX(my_pos.GetX() - my_step);
		CalculateSphere();

		if (my_pos.GetX() < 20)
		{
			my_boolDisappear = true;
		}

		if (440 < my_pos.GetX() && my_pos.GetX() < 461)
		{
			if (160 < my_pos.GetY() && my_pos.GetY() < 340)
			{
				my_boolDisappear = true;
			}
		}

		if (280 < my_pos.GetX() && my_pos.GetX() < 301)
		{
			if (360 < my_pos.GetY() && my_pos.GetY() < 380)
			{
				my_boolDisappear = true;
			}
		}

		if (120 < my_pos.GetX() && my_pos.GetX() < 141)
		{
			if (200 < my_pos.GetY() && my_pos.GetY() < 360)
			{
				my_boolDisappear = true;
			}
		}

		break;
	case RIGHT:
		my_pos.SetX(my_pos.GetX() + my_step);
		CalculateSphere();
		if (my_pos.GetX() > SCREEN_HEIGHT + BATTLEGROUND_LEFT )
		{
			my_boolDisappear = true;
		}

		if (119 < my_pos.GetX() && my_pos.GetX() < 140)
		{
			if (200 < my_pos.GetY() && my_pos.GetY() < 380)
			{
				my_boolDisappear = true;
			}
		}

		if (279 < my_pos.GetX() && my_pos.GetX() < 300)
		{
			if (160 < my_pos.GetY() && my_pos.GetY() < 180)
			{
				my_boolDisappear = true;
			}
		}

		if (439 < my_pos.GetX() && my_pos.GetX() < 460)
		{
			if (180 < my_pos.GetY() && my_pos.GetY() < 340)
			{
				my_boolDisappear = true;
			}
		}

		break;
	default:
		break;
	}
}




void Bullet::CalculateSphere()
{
	my_rectSphere.Set(my_pos.GetX() - 2, my_pos.GetY() - 2, my_pos.GetX() + 2, my_pos.GetY() + 2);
}
