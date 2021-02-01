#ifndef Enemy_h
#define Enemy_h

#include "Tank.h"
#define MAX_STEP_TURN	10
#define MAX_STEP_SHOOT	15


class Enemy : public Tank
{
public:
	Enemy()
	{
		RandomTank();
	}

	~Enemy() {}

	void Display();
	void Move();

	Rect GetSphere()
	{
		return my_rectSphere;
	}

	void Shoot(list<Object*>& listBullets);

protected:
	void CalculateSphere();

	void RandomTank();
	
	void RandomDir(int type);

	int my_stepCnt;
};

#endif
