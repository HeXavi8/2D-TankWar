 #ifndef Rectangle_h
#define Rectangle_h

#include  "Position_Point.h"
/**
class Rect
{
public:
	Rect(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : my_ULPoint(x1, y1), my_DRPoint(x2, y2) {};//左上角坐标，右下角坐标
	Rect(const Point p1, const Point p2) : my_ULPoint(p1), my_DRPoint(p2) {};
	~Rect() {};

	Rect& operator=(const Rect &rect)
	{
		my_ULPoint = rect.GetULPoint();
		my_DRPoint = rect.GetDRPoint();

		return *this;
	}

	void Set(const Point pStart, const Point pEnd);
	void Set(int x1, int y1, int x2, int y2);

	void SetULPoint(const Point p);
	void SetDRPoint(const Point p);

	Point GetULPoint() const;
	Point GetDRPoint() const;

	int GetWidth();
	int GetHeight();

private:
	void Check();

	Point my_ULPoint;
	Point my_DRPoint;
};


**/
class Rect
{
public:
	Rect(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : my_startPoint(x1, y1), my_endPoint(x2, y2) {}
	Rect(const Point p1, const Point p2) : my_startPoint(p1), my_endPoint(p2) {}
	Rect(const Rect& r1) : my_startPoint(r1.GetStartPoint()), my_endPoint(r1.GetEndPoint()) {}
	~Rect() {};

	Rect& operator=(const Rect &rect)
	{
		my_startPoint = rect.GetStartPoint();
		my_endPoint = rect.GetEndPoint();

		return *this;
	}

	void Set(const Point pStart, const Point pEnd);
	void Set(int x1, int y1, int x2, int y2);

	void SetStartPoint(const Point p);
	void SetEndPoint(const Point p);

	Point GetStartPoint() const;
	Point GetEndPoint() const;

	Point GetTRPoint() const; // Get Top Right Point
	Point GetBLPoint() const; // Get Bottom Left Point

	int GetWidth();
	int GetHeight();


private:
	void Check();

	Point my_startPoint;
	Point my_endPoint;
};


#endif
