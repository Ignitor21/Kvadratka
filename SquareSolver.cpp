#include <stdio.h>
#include <math.h>
#include <cassert>
#include "SquareSolver.h"

static const double EPSILON = 10E-8;

/*!
@brief Сравнивает два числа типа double
@param[in] a Первое число
@param[in] b Второе число
@return Возвращает 1, если числа равны с определенной точностью, 0 - в противном случае
*/

bool isEqual(const double a, const double b)
{
	assert(isfinite(a));
	assert(isfinite(b));

	return (fabs(a-b) < EPSILON);
}


/*!
@brief Решает линейное уравнение  
@param[in] b Коэффициент при х
@param[in] c Свободный член
@param[out] x1 Корень уравнения
@param[out] x2 Корень уравнения (В данном случае корни всегда будут равны)
@return Возвращает enum-вский тип, говорящий о количестве корней уравнения (нет корней, 1 корень, бесконечно много корней)
*/

enum variant linearSolution(const double b, const double c, double* x1, double* x2)
{
	assert(isfinite(b));
	assert(isfinite(c));
	assert(x1 != nullptr);
	assert(x2 != nullptr);

	if (isEqual(b, 0) && isEqual(c, 0))
		return OTHER;

	if (isEqual(b, 0))
		return NO_SOLUTIONS;

	*x1 = *x2 = -c / b;
	return LINEAR;
}

/*!
@brief Решает квадратное уравнение
@param[in] a Коэффициент при x^2
@param[in] b Коэффициент при х
@param[in] c Свободный член
@param[out] x1 Корень уравнения
@param[out] x2 Корень уравнения 
@return Возвращает enum-вский тип, говорящий о количестве корней уравнения (нет корней, 1 корень, 2 корня, бесконечно много корней)
*/

enum variant squareSolution(const double a, const double b, const double c, double* x1, double* x2)
{
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));
	assert(x1 != nullptr);
	assert(x2 != nullptr);

	if (isEqual(b, 0) && isEqual(c, 0))
	{
		*x1 = *x2 = 0;
		return QUADRATIC_1;
	}

	if (isEqual(c, 0))
	{
		*x1 = 0;
		*x2 = -b / a;
		return QUADRATIC_2;
	}

	if (isEqual(b, 0))
	{
		if (c > 0)
			return QUADRATIC_0;

		*x1 = sqrt(-c / a);
		*x2 = -*x1;
		return QUADRATIC_2;		
	}

	double d = 0, d_sqrt = 0;
	d = b * b - 4 * a * c;
	
	if (d < 0)
		return QUADRATIC_0;

	if (isEqual(d, 0))
	{
		*x1 = *x2 = -b / (2 * a);
		return QUADRATIC_1;
	}

	d_sqrt = sqrt(d);
	*x1 = (-b - d_sqrt) / (2 * a);
	*x2 = (-b + d_sqrt) / (2 * a);
	return QUADRATIC_2;
}

/*!
@brief Вывод результатов решения уравнения на экран  
@param[in] n enum-овский тип, говорящий о количестве корней уравнения
@param[in] x1 1-ый корень
@param[in] x2 2-ый корень
*/

void printResult(const variant n, const double x1, const double x2)
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

/*!
@brief Проверка корректности ввода  
@param[in] a Указатель на коэффициент при x^2
@param[in] b Указатель на коэффициент при x
@param[in] c Указатель на свободный член
*/

void isInputCorrect(double* a, double* b, double* c)
{
	assert(a != nullptr);
	assert(b != nullptr);
	assert(c != nullptr);

	while (scanf("%lg %lg %lg", a, b, c) != 3)
	{
		printf("Некорректный ввод! Повторите попытку: ");
		while (getchar() != '\n');
	}
}


/*!
@brief Функция, прогоняющая данные для тестов
*/

void unitTest()
{
	constexpr int numberOfTests = 8;
	int okTests = 0;

	struct test_data test_list[numberOfTests] = {
	{0, 0, 0, OTHER, 0, 0},
	{0, 0, 1, NO_SOLUTIONS, 0, 0},
	{0, 1, 0, LINEAR, 0, 0},
	{1, 0, 0, QUADRATIC_1, 0, 0},
	{0, 1, 2, LINEAR, -2, -2},
	{1, 2, 3, QUADRATIC_0, 0, 0},
	{1, -2, 1, QUADRATIC_1, 1, 1},
	{1, -5, 6, QUADRATIC_2, 2, 3}
	};
	
	for (int i = 0; i < numberOfTests; i++)
	{
		okTests += oneTest(test_list[i]);
	}
	printf("Успешных тестов: %d\nНеуспешных тестов: %d\n", okTests, numberOfTests - okTests);
}

/*!
@brief Тестирующая функция
@param[in] testik(структура test_data)
@return Возвращает 1, если тест успешен, 0 - в противном случае
*/

bool oneTest (test_data testik)
{
	assert(isfinite(testik.a));
	assert(isfinite(testik.b));
	assert(isfinite(testik.c));
	assert(isfinite(testik.x1_expected));
	assert(isfinite(testik.x2_expected));

	double x1 = 0, x2 = 0;
	variant type = isEqual(testik.a, 0) ? linearSolution(testik.b, testik.c, &x1, &x2): squareSolution(testik.a, testik.b, testik.c, &x1, &x2);

	if (!(type == testik.type_expected && isEqual(x1, testik.x1_expected) && isEqual(x2, testik.x2_expected)))
	{
		printf("НЕУСПЕШНО: type = %d, x1 = %lg, x2 = %lg \nОЖИДАЛОСЬ: type = %d, x1 = %lg, x2 = %lg\n", type, x1, x2, testik.type_expected, testik.x1_expected, testik.x2_expected);
		return 0;
	}

	printf("ТЕСТ УСПЕШЕН!\n");
	return 1;
}

/*!
@brief Функция принимающая тесты из файла
*/

void testFromFile()
{
	FILE *fp = NULL; 
	fp = fopen("test.txt", "r");
	int numberOfTests = 0, okTests = 0;
	test_data testik = {};

	fscanf(fp, "%d", &numberOfTests); 

	for (int i = 0; i < numberOfTests; i++)
	{
		fscanf(fp, "%lg %lg %lg %d %lg %lg", &testik.a, &testik.b, &testik.c, &testik.type_expected, &testik.x1_expected, &testik.x2_expected);
		okTests += oneTest(testik);
	}

	fclose(fp);
	printf("Успешных тестов: %d\nВсего тестов: %d\n", okTests, numberOfTests);
}
