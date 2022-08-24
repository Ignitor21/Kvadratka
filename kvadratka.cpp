#include <stdio.h>
#include "prototypes.h"

int main(void)
{	
	double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
	int response = 0;
	enum variant type = {};
	enum step action = {};
	printf("Вас привествуете программа решения квадратного уравнения!\n");
	printMenu();
	while(true)
	{
		isIntInputCorrect(&response);
		if (response == SOLVE)
		{
			printf("Введите 3 коэффициента квадратного уравнения: \n");
			printf("Введите коэффициент a: ");
			isDoubleInputCorrect(&a);
			printf("Введите коэффициент b: ");
			isDoubleInputCorrect(&b);
			printf("Введите коэффициент c: ");
			isDoubleInputCorrect(&c);

			if (isEqual(a, 0))
				type = linearSolution(a, b, c, &x1, &x2);
			else
				type = squareSolution(a, b, c, &x1, &x2);

			printResult(type, x1, x2);
			printMenu();
		}
		else if (response == FINISH)
			break;
		else 
			printf("Некорректный ввод! Введите 1 или 2: ");
	}
	printf("Работа завершена :D\n");

	return 0;
}
