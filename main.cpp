#include <stdio.h>
#include "SquareSolver.h"

int main(void)
{	
	double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
	enum variant type = {};

	printf("Вас привествуете программа решения квадратного уравнения!\n");
	printf("Введите 3 коэффициента квадратного уравнения: ");
	isInputCorrect(&a, &b, &c);
	type = solveEquasion(a, b, c, &x1, &x2);
	printResult(type, x1, x2);
	printf("%lg %lg", x1, x2);
	//unitTest();
	printf("Работа завершена :D\n");

	return 0;
}
