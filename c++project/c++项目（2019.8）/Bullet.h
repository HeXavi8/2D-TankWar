#ifndef Bullet_h
#define Bullet_h

#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	Bullet(Point pos, Dir dir, COLORREF color);
	~Bullet();

	void Display();//�����ӵ�

	void Move();//�����ӵ����˶�

	bool IsDisappear()
	{
		return my_boolDisappear;
	}

	

	Rect GetSphere()
	{
		return my_rectSphere;
	}

	void SetDisappear()
	{
		my_boolDisappear = true;
	}
protected:

    void CalculateSphere();

};

#endif
