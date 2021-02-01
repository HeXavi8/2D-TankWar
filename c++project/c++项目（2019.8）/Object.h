#ifndef Object_h
#define Object_h

#include "Graphic.h"
#include <list>
enum Dir { UP, DOWN, LEFT, RIGHT };

class Object 
{
public:
	
	virtual void Display() = 0;

	virtual void Move() = 0;
	
	virtual bool IsDisappear() = 0;

	virtual void SetDisappear() = 0;

	virtual Rect GetSphere() = 0;


protected:
	

	virtual void CalculateSphere() = 0;// 计算势力范围
	
	Point my_pos;// 位置
	
	Rect my_rectSphere;
	
	COLORREF my_color;// 颜色 
	
	Dir my_dir;// 方向
	
	bool my_boolDisappear;// 存在状态
	
	int my_step;// 单次步长
};

#endif
