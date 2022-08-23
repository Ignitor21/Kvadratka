#ifndef _Header_H
#define _Header_H

enum variant
{
	OTHER,
	NO_SOLUTIONS,
	LINEAR,
	QUADRATIC_0,
	QUADRATIC_1,
	QUADRATIC_2
};

const double EPSILON = 10E-8;

void printResult(enum variant n, float x1, float x2);
enum variant solution(float a, float b, float c, float* x1, float* x2);

#endif
