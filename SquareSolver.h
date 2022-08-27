#ifndef _SquareSolver_h
#define _SquareSolver_h

enum variant
{
	OTHER,
	NO_SOLUTIONS,
	LINEAR,
	QUADRATIC_0,
	QUADRATIC_1,
	QUADRATIC_2
};

enum step
{
	SOLVE = 1,
	FINISH = 2 
};

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
#endif
