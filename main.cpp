#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SquareSolver.h"
int main(int argc, char* argv[])
{	

	if (argc < 2)
	{
		printf("Введите флаги запуска (solve, test)\n");
		exit(1);
	}

	for (int i = 1; i < argc; i++)
	{
		if (!strncmp (argv[i], "test", 20))
		{
			unitTest();

			return 0;
		}

		else if (!strncmp (argv[i], "solve", 20))
		{
			double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
			enum variant type = {};
			printf("Вас привествуете программа решения квадратного уравнения!\n");
			printf("Введите 3 коэффициента квадратного уравнения: ");
			isInputCorrect(&a, &b, &c);
			type = solveEquasion(a, b, c, &x1, &x2);
			printResult(type, x1, x2);	
			printf("Работа завершена :D\n");

			return 0;
		}

		else
		{
			printf("Введите правильный флаг запуска (solve, test)\n");
			exit(1);
		}
	}
}
