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
	

	virtual void CalculateSphere() = 0;// ����������Χ
	
	Point my_pos;// λ��
	
	Rect my_rectSphere;
	
	COLORREF my_color;// ��ɫ 
	
	Dir my_dir;// ����
	
	bool my_boolDisappear;// ����״̬
	
	int my_step;// ���β���
};

#endif
