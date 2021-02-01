#include "Rectangle.h"
/**
void Rect::Set(Point pUL, Point pDR)
{
	my_ULPoint = pUL;
	my_DRPoint = pDR;
}

void Rect::Set(int x1, int y1, int x2, int y2)
{
	my_ULPoint.Set(x1, y1);
	my_DRPoint.Set(x2, y2);
}

void Rect::SetULPoint(Point p)
{
	my_ULPoint = p;
}

void Rect::SetDRPoint(Point p)
{
	my_DRPoint = p;
}

Point Rect::GetULPoint() const
{
	return my_ULPoint;
}

Point Rect::GetDRPoint() const
{
	return my_DRPoint;
}

int Rect::GetWidth()
{
	return my_DRPoint.GetX() - my_ULPoint.GetX();
}

int Rect::GetHeight()
{
	return my_DRPoint.GetY() - my_ULPoint.GetY();
}

void Rect::Check()
{
	if (my_ULPoint.GetX() > my_DRPoint.GetX() || my_ULPoint.GetY() > my_DRPoint.GetY())
	{
		Point p = my_ULPoint;
		my_ULPoint = my_DRPoint;
		my_DRPoint = p;
	}
}
**/

void Rect::Set(Point pStart, Point pEnd)
{
	my_startPoint = pStart;
	my_endPoint = pEnd;
}

void Rect::Set(int x1, int y1, int x2, int y2)
{
	my_startPoint.Set(x1, y1);
	my_endPoint.Set(x2, y2);
}

void Rect::SetStartPoint(Point p)
{
	my_startPoint = p;
}

void Rect::SetEndPoint(Point p)
{
	my_endPoint = p;
}

Point Rect::GetStartPoint() const
{
	return my_startPoint;
}

Point Rect::GetEndPoint() const
{
	return my_endPoint;
}

Point Rect::GetTRPoint() const
{
	Point p = my_startPoint;
	p.SetX(my_endPoint.GetX());

	return p;
}

Point Rect::GetBLPoint() const
{
	Point p = my_startPoint;
	p.SetY(my_endPoint.GetY());

	return p;
}

int Rect::GetWidth()
{
	return my_endPoint.GetX() - my_startPoint.GetX();
}

int Rect::GetHeight()
{
	return my_endPoint.GetY() - my_startPoint.GetY();
}

void Rect::Check()
{
	if (my_startPoint.GetX() > my_endPoint.GetX() || my_startPoint.GetY() > my_endPoint.GetY())
	{
		Point p = my_startPoint;
		my_startPoint = my_endPoint;
		my_endPoint = my_startPoint;
	}
}