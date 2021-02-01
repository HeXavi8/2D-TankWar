#include "Check.h"



/**
bool Check::CheckPointInRectangle(Point & object1, Object & object2)
{
	if (object1.my_rectSphere.GetX1() > object2.my_rectSphere.GetX1() && object1.my_rectSphere.GetX1() < object2.my_rectSphere.GetX2())
	{
		if (object1.my_rectSphere.GetY1() > object2.my_rectSphere.GetY1() && object1.my_rectSphere.GetY1() < object2.my_rectSphere.GetY2())
        return false;
		if (object1.my_rectSphere.GetY2() > object2.my_rectSphere.GetY1() && object1.my_rectSphere.GetY2() < object2.my_rectSphere.GetY2())
		return false;
	}
	if (object1.my_rectSphere.GetX2() > object2.my_rectSphere.GetX1() && object1.my_rectSphere.GetX2() < object2.my_rectSphere.GetX2())
	{
		if (object1.my_rectSphere.GetY1() > object2.my_rectSphere.GetY1() && object1.my_rectSphere.GetY1() < object2.my_rectSphere.GetY2())
			return false;
		if (object1.my_rectSphere.GetY2() > object2.my_rectSphere.GetY1() && object1.my_rectSphere.GetY2() < object2.my_rectSphere.GetY2())
			return false;
	}
	else
	{
		return true;
	}
}
**/
bool Check::CheckPointInRect(Point point, Rect& rect)
{
	if (point.GetX() < rect.GetStartPoint().GetX() || point.GetX() > rect.GetEndPoint().GetX() ||
		point.GetY() < rect.GetStartPoint().GetY() || point.GetY() > rect.GetEndPoint().GetY())
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Check::CheckIntersect(Rect & rect1, Rect & rect2)
{


	if (CheckPointInRect(rect1.GetStartPoint(), rect2) ||
		CheckPointInRect(rect1.GetEndPoint(), rect2) ||
		CheckPointInRect(rect1.GetTRPoint(), rect2) ||
		CheckPointInRect(rect1.GetBLPoint(), rect2))
	{
		return true;
	}
	else
	{
		return false;
	}

}
	

