#include <stdio.h>
#include "Header.h"

int main(void)
{	
	float x1 = 0, x2 = 0;
	float a = 0, b = 0, c = 0;
	enum variant type = {};

	printf("Программа решения квадратного уравнения\n");
	printf("Введите 3 коэффициента квадратного уравнения (введите q для выхода из программы): ");

	isInputCorrect(&a, &b, &c);
	type = solution(a, b, c, &x1, &x2);
	printResult(type, x1, x2);	
	//printf("Введите 3 коэффициента квадратного уравнения (введите q для выхода из программы): ");
	printf("Работа завершена :D\n");

	return 0;
}
