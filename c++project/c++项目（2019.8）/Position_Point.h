#ifndef Position_Point_h
#define Position_Point_h
#include <list>
class Point
{
public:
	Point(int x = 0.0, int y = 0.0) : my_x(x), my_y(y) {}; //坦克及炮弹的横纵坐标
	~Point() {};

	Point& operator=(const Point &p) //便于赋值
	{
		my_x = p.my_x;
		my_y = p.my_y;

		return *this;
	}



	void Set(int x, int y);
	//void Set(int x1, int y1, int x2, int y2);


	void SetX(int x);
	void SetY(int y);

	int GetX() const;
	int GetY() const;

	int GetX1();
	int GetX2();
	int GetY1();
	int GetY2();


private:
	int my_x;
	int my_y;

	int my_x1;
	int my_x2;
	int my_y1;
	int my_y2;


};

#endif
