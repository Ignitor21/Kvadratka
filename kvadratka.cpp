#include <stdio.h>
#include <math.h>

enum Event
{
OTHER,
LINEAR1,
LINEAR2,
QUADRATIC
};

const double EPSILON = 0.000000001;

enum Event variant(float a, float b, float c);
void solution(float a, float b, float c, float* x1, float* x2, float* d);
void printResult(enum Event n, float b, float c, float x1, float x2, float d);

int main(void)
{	
	float x1 = 0, x2 = 0, d = 0;
	float a = 0, b = 0, c = 0;
	enum Event type;
	printf("Программа решения квадратного уравнения\n");
	printf("Введите 3 коэффициента квадратного уравнения (введите q для выхода из программы): ");
	while (scanf("%f %f %f", &a, &b, &c) == 3)
	{
		type = variant(a, b, c);	
		solution(a, b, c, &x1, &x2, &d);
		printResult(type, b, c , x1, x2, d);	
		printf("Введите через пробел 3 коэффициента квадратного уравнения (введите q для выхода из программы): ");
	}
	printf("Работа завершена :D\n");
	return 0;
}

enum Event variant(float a,  float b, float c)
{
	if (fabs(a) < EPSILON && fabs(b) < EPSILON && fabs(c) < EPSILON)
		return OTHER;
	else if (fabs(a) < EPSILON && fabs(b) < EPSILON)
		return LINEAR1;
	else if (fabs(a) < EPSILON)
		return LINEAR2;
	else
		return QUADRATIC;
}

void solution(float a, float b, float c, float* x1, float* x2, float* d)
{
	float d_sqrt = 0;
	*d = b*b - 4 * a * c;
	d_sqrt = pow(*d, 0.5);
	if (*d > 0)
	{
		*x1 = (-b - d_sqrt) / (2 * a);
		*x2 = (-b + d_sqrt) / (2 * a);
	}
	else if (fabs(*d) < EPSILON)
		*x1 = *x2 = -b / (2 * a);
	
}

void printResult(enum Event n, float b, float c, float x1, float x2, float d)
{
	switch(n)
	{
	case OTHER:
		printf("х - любое число.\n");
		break;
	case LINEAR1:
		printf("Нет корней!\n");
		break;
	case LINEAR2:
		printf("Корень этого уравнения: %.2f\n", fabs(c) < EPSILON ? 0: -1 * c / b);
		break;
	case QUADRATIC:
		if (d > 0)
			printf("Корни этого уравнения: %.2f и %.2f\n", x1, x2);
		else if (fabs(d) < EPSILON)
			printf("Корень этого уравнения: %.2f\n", (fabs(b) < EPSILON && fabs(c) < EPSILON) ? 0 : x1);
		else
			printf("Нет корней!\n");
		break;
	}

}
