#include "mathfunctions.h"

MathFunctions::MathFunctions()
{
}

unsigned long int MathFunctions::factorial(unsigned int n)
{
	switch(n)
	{
		case 0: return 0;
		case 1: return 1;
		default: return n * factorial(n-1);
	}
}
