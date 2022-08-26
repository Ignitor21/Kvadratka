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
	int okTests = 0, tests = 0;
	okTests += oneTest(0, 0, 0, OTHER, 0, 0);
	tests++;
	okTests += oneTest(0, 0, 1, NO_SOLUTIONS, 0, 0);
	tests++;
	okTests += oneTest(0, 1, 0, LINEAR, 0, 0);
	tests++;
	okTests += oneTest(1, 0, 0, QUADRATIC_1, 0, 0);
	tests++;
	okTests += oneTest(0, 1, 2, LINEAR, -2, -2);
	tests++;
	okTests += oneTest(1, 2, 3, QUADRATIC_0, 0, 0);
	tests++;
	okTests += oneTest(1, -2, 1, QUADRATIC_1, 1, 1);
	tests++;
	okTests += oneTest(1, -5, 6, QUADRATIC_2, 2, 3);
	tests++;
	printf("Успешных тестов: %d\nНеуспешных тестов: %d\n", okTests, tests - okTests);
}
bool oneTest (const double a, const double b, const double c, const enum variant type_, double x1_, double x2_)
{
	double x1 = 0, x2 = 0;
	enum variant type = solveEquasion(a, b, c, &x1, &x2);
	if (!(type == type_ && isEqual(x1, x1_) && isEqual(x2, x2_)))
	{
		printf("НЕУСПЕШНО: type = %d, x1 = %lg, x2 = %lg \nОЖИДАЛОСЬ: type = %d, x1 = %lg, x2 = %lg\n", type, x1, x2, type_, x1_, x2_);
		return 0;
	}
	else
	{
		printf("ТЕСТ УСПЕШЕН!\n");
		return 1;
	}
}

