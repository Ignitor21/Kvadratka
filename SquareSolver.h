#ifndef _SquareSolver_h
#define _SquareSolver_h

/// Варианты возможного количества корней уравнения 

enum variant
{
	OTHER, ///< Все коэффициенты 0 0
	NO_SOLUTIONS, ///< Линейное уравнение без корней 1
	LINEAR, ///< Линейное уравнение с 1 корнем 2
	QUADRATIC_0,///< Квадратное уравнение без корней 3
	QUADRATIC_1, ///< Квадратное уравнение с 1 корнем 4
	QUADRATIC_2 ///< Квадратное уравнение с 2 корнями 5
};


/*!
@brief Структура для тестов
*/

struct test_data {
	double a;
	double b;
	double c;
	variant type_expected;
	double x1_expected;
	double x2_expected;
};


bool isEqual(const double a, const double b);
void isInputCorrect(double* a, double* b, double* c);
variant squareSolution(const double a, const double b, const double c, double* x1, double* x2);
variant linearSolution(const double b, const double c, double* x1, double* x2);
void printResult(const enum variant n, const double x1, const double x2);
void unitTest();
bool oneTest(test_data testik);
void testFromFile();
#endif
