#include <stdio.h>
#include <math.h>
#include "prototypes.h"

const double EPSILON = 10E-8;

bool isEqual(const double a, const double b)
{
	return (fabs(a-b) < EPSILON);
}

enum variant linearSolution(const double a, const double b, const double c, double* x1, double* x2)
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
			*x1 = (-b + d_sqrt) / (2 * a);
			*x2 = (-b - d_sqrt) / (2 * a);
			return QUADRATIC_2;
		}
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
	}
}

void isDoubleInputCorrect(double* a)
{
	while (scanf("%lg", a) != 1)
	{
		printf("Некорректный ввод! Повторите попытку: ");
		while (getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
			continue;
}

void isIntInputCorrect(int* a)
{
	while (scanf("%d", a) != 1)
	{
		printf("Некорректный ввод! Введите 1 или 2: ");
		while (getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
			continue;
}

void printMenu(void)
{
	printf("********************************************************************************\n");
	printf("           Введите одно из следующих чисел, чтобы продолжить:\n");
	printf("   1. Начать решение квадратного уравнения          2. Выход из программы\n");
	printf("********************************************************************************\n");
}
