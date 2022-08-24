#ifndef _prototypes_h
#define _prototypes_h

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

void printResult(const enum variant n, const double x1, const double x2);
enum variant squareSolution(const double a, const double b, const double c, double* x1, double* x2);
void isDoubleInputCorrect(double* a);
enum variant linearSolution(const double a, const double b, const double c, double* x1, double* x2);
void isIntInputCorrect(int* a);
bool isEqual(const double a, const double b);
void printMenu(void);
#endif
