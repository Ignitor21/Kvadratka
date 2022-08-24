#include <stdio.h>
#include <math.h>
#include "SquareSolver.h"
#include <cassert>
static const double EPSILON = 10E-8;

bool isEqual(const double a, const double b)
{
	return (fabs(a-b) < EPSILON);
}

enum variant linearSolution(const double b, const double c, double* x1, double* x2)
{
	if (isEqual(b, 0) && isEqual(c, 0))
		return OTHER;
	else if (isEqual(b, 0))
		return NO_SOLUTIONS;
	else 
	{
		*x1 = *x2 = -c / b;
		return LINEAR;
	}
}

enum variant squareSolution(const double a, const double b, const double c, double* x1, double* x2)
{

	if (isEqual(b, 0) && isEqual(c, 0))
	{
		*x1 = *x2 = 0;
		return QUADRATIC_1;
	}
	else if (isEqual(c, 0))
	{
		*x1 = 0;
		*x2 = -b / a;
		return QUADRATIC_2;
	}
	else if (isEqual(b, 0))
	{
		if (c > 0)
			return QUADRATIC_0;
		else
		{
			*x1 = sqrt(-c / a);
			*x2 = -*x1;
			return QUADRATIC_2;
		}		
	}
	else
	{
		double d = 0, d_sqrt = 0;
		d = b * b - 4 * a * c;

		if (d < 0)
			return QUADRATIC_0;
		else if (isEqual(d, 0))
		{
			*x1 = *x2 = -b / (2 * a);
			return QUADRATIC_1;
		}
		else
		{
			d_sqrt = sqrt(d);
			*x1 = (-b - d_sqrt) / (2 * a);
			*x2 = (-b + d_sqrt) / (2 * a);
			return QUADRATIC_2;
		}
	}
}

enum variant solveEquasion(const double a, const double b, const double c, double* x1, double* x2)
{
	enum variant type = {};
	if (isEqual(a, 0))
		type = linearSolution(b, c, x1, x2);
	else
		type =  squareSolution(a, b, c, x1, x2);
	return type;
}

void printResult(const enum variant n, const double x1, const double x2)
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
		printf("Корень этого уравнения: %lg\n", x1);
		break;
	case QUADRATIC_0:
		printf("Нет корней!\n");
		break;
	case QUADRATIC_1:
		printf("Корень этого уравнения: %lg\n", x1);
		break;
	case QUADRATIC_2:
		printf("Корни этого уравнения: %lg и %lg\n", x1, x2);
		break;
	default:
		break;
	}
}

void isInputCorrect(double* a, double* b, double* c)
{
	while (scanf("%lg %lg %lg", a, b, c) != 3)
	{
		printf("Некорректный ввод! Повторите попытку: ");
	}
}

void unitTest()
{
	double x1 = 0, x2 = 0;
	enum variant type = solveEquasion(0, 0, 0, &x1, &x2);
	if (!(type == OTHER && isEqual(x1, 0) && isEqual(x2, 0)))
	{
		printf("FAILED; type = %d, x1 = %lg, x2 = %lg\nEXPECTED: type = %d, x1 = %lg, x2 = %lg", type, x1, x2, 0, .0, .0);

	}
	assert(type == OTHER && isEqual(x1, 0) && isEqual(x2, 0));
	x1 = 0, x2 = 0;

	type = solveEquasion(0, 0, 5, &x1, &x2);
	if (!(type == NO_SOLUTIONS && isEqual(x1, 0) && isEqual(x2, 0)))
	{
		printf("FAILED; type = %d, x1 = %lg, x2 = %lg\nEXPECTED: type = %d, x1 = %lg, x2 = %lg", type, x1, x2, 1, .0, .0);

	}
	assert(type == NO_SOLUTIONS && isEqual(x1, 0) && isEqual(x2, 0));
	x1 = 0, x2 = 0;

	type = solveEquasion(0, 5, 0, &x1, &x2);
	if (!(type == LINEAR && isEqual(x1, 0) && isEqual(x2, 0)))
	{
		printf("FAILED; type = %d, x1 = %lg, x2 = %lg\nEXPECTED: type = %d, x1 = %lg, x2 = %lg", type, x1, x2, 2, .0, .0);

	}
	assert(type == LINEAR && isEqual(x1, 0) && isEqual(x2, 0));
	x1 = 0, x2 = 0;

	type = solveEquasion(5, 0, 0, &x1, &x2);
	if (!(type == QUADRATIC_1 && isEqual(x1, 0) && isEqual(x2, 0)))
	{
		printf("FAILED; type = %d, x1 = %lg, x2 = %lg\nEXPECTED: type = %d, x1 = %lg, x2 = %lg", type, x1, x2, 4, .0, .0);

	}
	assert(type == QUADRATIC_1 && isEqual(x1, 0) && isEqual(x2, 0));
	x1 = 0, x2 = 0;

	type = solveEquasion(0, 5, 1, &x1, &x2);
	if (!(type == LINEAR && isEqual(x1, -0.2) && isEqual(x2, -0.2)))
	{
		printf("FAILED; type = %d, x1 = %lg, x2 = %lg\nEXPECTED: type = %d, x1 = %lg, x2 = %lg", type, x1, x2, 2, -1.2, -1.2);

	}
	assert(type == LINEAR && isEqual(x1, -0.2) && isEqual(x2, -0.2));
	x1 = 0, x2 = 0;

	type = solveEquasion(1, -2, 1, &x1, &x2);
	if (!(type == QUADRATIC_1 && isEqual(x1, 1) && isEqual(x2, 1)))
	{
		printf("FAILED; type = %d, x1 = %lg, x2 = %lg\nEXPECTED: type = %d, x1 = %lg, x2 = %lg\n", type, x1, x2, 4, 1.0, 1.0);
	}		
	assert(type == QUADRATIC_1 && isEqual(x1, 1) && isEqual(x2, 1));
	x1 = 0, x2 = 0;

	type = solveEquasion(1, -5, 6, &x1, &x2);
	if (!(type == QUADRATIC_2 && isEqual(x1, 2) && isEqual(x2, 3)))
	{
		printf("FAILED; type = %d, x1 = %lg, x2 = %lg\nEXPECTED: type = %d, x1 = %lg, x2 = %lg", type, x1, x2, 5 , 2.0, 3.0);

	}
	assert(type == QUADRATIC_2 && isEqual(x1, 2) && isEqual(x2, 3));
	x1 = 0, x2 = 0;

	type = solveEquasion(1, 2, 3, &x1, &x2);
	if (!(type == QUADRATIC_0 && isEqual(x1, 0) && isEqual(x2, 0)))
	{
		printf("FAILED; type = %d, x1 = %lg, x2 = %lg \nEXPECTED: type = %d, x1 = %lg, x2 = %lg", type, x1, x2, 3, .0, .0);

	}
	assert(type == QUADRATIC_0 && isEqual(x1, 0) && isEqual(x2, 0));
x1 = 0, x2 = 0;

}

/*enum variant
{
	OTHER,
	NO_SOLUTIONS,
	LINEAR,
	QUADRATIC_0,
	QUADRATIC_1,
	QUADRATIC_2
};*/

