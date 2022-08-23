#include <stdio.h>
#include <math.h>
#include "Header.h"

bool isEqual(float a, float b)
{
	return (fabs(a-b) < EPSILON);
}

enum variant solution(float a, float b, float c, float* x1, float* x2)
{
	if (isEqual(a, 0) && isEqual(b, 0) && isEqual(c, 0))
		return OTHER;
	else if (isEqual(a, 0) && isEqual(b, 0))
		return NO_SOLUTIONS;
	else if (isEqual(a, 0))
	{
		*x1 = *x2 = -c / b;
		return LINEAR;
	}
	else
	{
		float d = 0, d_sqrt = 0;
		d = b * b - 4 * a * c;
		d_sqrt = sqrt(d);
		if (d < 0)
			return QUADRATIC_0;
		else if (isEqual(d, 0))
		{
			*x1 = *x2 = -b / (2 * a);
			return QUADRATIC_1;
		}
		else
		{
			*x1 = (-b + d_sqrt) / (2 * a);
			*x2 = (-b - d_sqrt) / (2 * a);
			return QUADRATIC_2;
		}
	}
}

void printResult(enum variant n, float x1, float x2)
{
	switch(n)
	{
	case OTHER:
		printf("х - любое число.\n");
		break;
	case NO_SOLUTIONS:
		printf("Нет корней!\n");
		break;
	case LINEAR:
		printf("Корень этого уравнения: %.2f\n", x1);
		break;
	case QUADRATIC_0:
		printf("Нет корней!\n");
		break;
	case QUADRATIC_1:
		printf("Корень этого уравнения: %.2f\n", x1);
		break;
	case QUADRATIC_2:
		printf("Корни этого уравнения: %.2f %.2f\n", x1, x2);
		break;
	}
}
