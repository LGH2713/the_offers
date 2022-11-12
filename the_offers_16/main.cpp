/*
*	题目：实现函数 double Power(double base, int exponent)，求base的exponent次方，同时不需要考虑大数问题
* 
*	tips：需要考虑指数小于1（负数和0）的情况，使用全局变量判断输入是否非法
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

bool g_InvalidInput = false;

double Power(double base, int exponent)
{
	// 全局标识符重置
	g_InvalidInput = false;

	// 0的0次方在数学上是没有意义的，所以返回1或0都可以（具体看面试官要求）
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

// 普通解法
/*
double powerwithunsignedexponent(double base, unsigned int exponent)
{
	double result = 1.0;
	for (int i = 1; i <= exponent; ++i)
		result *= base;

	return result;
}
*/

// 进阶解法: 使用斐波那契数列减少乘方次数
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if ((exponent & 0x1) == 1)
		result *= base;

	return result;
}


int main(int argc, char* argv)
{
	cout << Power(2, -1) << endl;
}