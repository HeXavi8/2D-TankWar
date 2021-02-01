#ifndef Check_h
#define Check_h
#include"Position_Point.h"
#include"Object.h"
#include "Rectangle.h"
#include"Bullet.h"
#include"Tank.h"
#include"MainTank.h"
class Check : public Object
{

public:


	//static bool CheckPointInRectangle(Point & object1, Point & object2);



	static bool CheckPointInRect(Point point, Rect& rect);
	static bool CheckIntersect(Rect & rect1, Rect & rect2);
	

};

#endif
  