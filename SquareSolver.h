#ifndef _SquareSolver_h
#define _SquareSolver_h
/**
* @brief Entry point
*
* Execution of the program
* starts here.
*
*/
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

bool isEqual(const double a, const double b);
void isInputCorrect(double* a, double* b, double* c);
variant squareSolution(const double a, const double b, const double c, double* x1, double* x2);
variant linearSolution(const double b, const double c, double* x1, double* x2);
void printResult(const enum variant n, const double x1, const double x2);
void unitTest();
bool oneTest(const double a, const double b, const double c, const enum variant type_, double x1_, double x2_);
#endif
