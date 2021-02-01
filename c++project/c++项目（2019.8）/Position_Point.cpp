#include "Position_Point.h"


void Point::Set(int x, int y)
{
	my_x = x;
	my_y = y;
}

/**void Point::Set(int x1, int y1, int x2, int y2)
{
	my_x1 = x1;
	my_y1 = y1;
	my_x2 = x2;
	my_y2 = y2;
}**/

void Point::SetX(int x)
{
	my_x = x;
}

void Point::SetY(int y)
{
	my_y = y;
}

int Point::GetX()const
{
	return my_x;
}

int Point::GetY()const
{
	return my_y;
}

int Point::GetX1()
{
	return my_x1;
}

int Point::GetX2()
{
	return my_x2;
}

int Point::GetY1()
{
	return my_y1;
}

int Point::GetY2()
{
	return my_y2;
}