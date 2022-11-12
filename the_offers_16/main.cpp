/*
*	题目：实现函数 double Power(double base, int exponent)，求base的exponent次方，同时不需要考虑大数问题
* 
*	tips：需要考虑指数小于1（负数和0）的情况
*/

#include<iostream>
#include<exception>
using namespace std;

double PowerWithUnsignedExponent(double base, unsigned int exponent);
double Power(double base, int exponent);

// 浮点数相等判断函数，不能直接使用==判断
bool equal(double a, double b)
{
	if (abs(a - b) < DBL_EPSILON)
		return true;
	return false;
}

// 普通解法：当

bool g_InvalidInput = false;

double Power(double base, int exponent)
{
	g_InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = static_cast<unsigned int>(exponent);
	if (exponent < 0)
		absExponent = static_cast<unsigned int>(-exponent);

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	double result = 1.0;
	for (int i = 1; i <= exponent; ++i)
		result *= base;

	return result;
}


int main(int argc, char* argv)
{
	cout << Power(5, -5) << endl;
}