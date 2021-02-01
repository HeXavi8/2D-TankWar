#include "Set.h"



int Set::my_Life = 100;



int Set::GetLife()
{
	return my_Life;
}



void Set::Hitted()
{
	my_Life -= 25;
}

