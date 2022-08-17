#include <stdio.h>
#include <math.h>

const double EPSILON = 0.000000001;
float x1 = 0, x2 = 0, d = 0;

void solution(float a, float b, float c);
int event(float a, float b, float c);
void printResult(float n);

int main(void)
{
	float a = 0, b = 0, c = 0;
	int variant = 0;
	printf("Программа решения квадратного уравнения\n");
	printf("Введите 3 коэффициента квадратного уравнения(введите q для выхода из программы): ");
	while (scanf("%f %f %f", &a, &b, &c) == 3)
	{
		variant = event(a, b, c);
		switch(variant)
		{
			case 0:
				printf("х - любое число.\n");
				break;
			case 1:
				printf("Это линейное уравнение, его корень: %.2f\n", -c / b);
				break;
			case 2:
				solution(a, b, c);
				printResult(d);
				break;
		}
		d = x1 = x2 = 0;
		printf("Введите через пробел 3 коэффициента квадратного уравнения(введите q для выхода из программы):\n");
	}
	printf("Работа завершена :D\n");
	return 0;
}

int event(float a,  float b, float c)
{
	if (fabs(a) < EPSILON && fabs(b) < EPSILON && fabs(c) < EPSILON)
		return 0;
	else if (fabs(a) < EPSILON)
		return 1;
	else
		return 2;
}

void solution(float a, float b, float c)
{
	d = b*b - 4 * a * c;
	if (d > 0)
	{
		x1 = (-b - pow(d, 0.5)) / (2 * a);
		x2 = (-b + pow(d, 0.5)) / (2 * a);
	}
	else if (fabs(d) < EPSILON)
		x1 = x2 = -b / (2 * a);
	
}

void printResult(float n)
{
	if (n > 0)
		printf("Корни этого уравнения: %.2f и %.2f\n", x1, x2);
	else if (fabs(n) < EPSILON)
		printf("Корень этого уравнения: %.2f\n", x1);
	else
		printf("Нет корней!\n");
}

