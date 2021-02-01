#ifndef MainTank_h
#define MainTank_h

#include "Tank.h"
#include "bullet.h"
class MainTank : public Tank
{
public:
	MainTank() : Tank()
	{
		my_pos.Set(360, 360);

		this->CalculateSphere();

		my_color = BLUE;
		my_dir = Dir::UP;
		my_step = 8;
	}

	~MainTank() {}


	void SetDir(Dir dir);
	void Display();
	void Move();
	void Shoot(list<Object*>& listBullets);


	Rect GetSphere()
	{
		return my_rectSphere;
	}

protected:

	void CalculateSphere();
	
	
	void DrawTankBody();// 绘制坦克主体
};

#endif
