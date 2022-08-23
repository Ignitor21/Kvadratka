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

void printResult(const enum variant n, const float x1, const float x2);
enum variant solution(const float a, const float b, const float c, float* x1, float* x2);
void isInputCorrect(float* a, float* b, float *c);
bool isEqual(const float a, const float b);

#endif
