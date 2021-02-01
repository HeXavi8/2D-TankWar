#ifndef Tank_h
#define Tank_h

#include "Object.h"

#include <list>

using namespace std;


class Tank : public Object
{
public:
	Tank()
	{
		my_pos.Set(300, 300);

		this->CalculateSphere();

		my_color = WHITE;
		my_dir = Dir::UP;
		my_step = 10;

		my_boolDisappear = false;
		my_boolNeedShoot = false;
	}


	~Tank() {}


	void Display() {};

	void Move() {};

	void Shoot(list<Object*>& listBullets) {};

	bool IsDisappear()
	{
		return my_boolDisappear;
	}

	void SetDisappear()
	{
		my_boolDisappear = true;
	}


	bool NeedShoot()
	{
		return my_boolNeedShoot;
	}

	Rect GetSphere()
	{
		return my_rectSphere;
	}

protected:

	void CalculateSphere() {};
	bool my_boolNeedShoot;
};

#endif
