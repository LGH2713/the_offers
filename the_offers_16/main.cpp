/*
*	��Ŀ��ʵ�ֺ��� double Power(double base, int exponent)����base��exponent�η���ͬʱ����Ҫ���Ǵ�������
* 
*	tips����Ҫ����ָ��С��1��������0�������
*/

#include<iostream>
#include<exception>
using namespace std;

double PowerWithUnsignedExponent(double base, unsigned int exponent);
double Power(double base, int exponent);

// ����������жϺ���������ֱ��ʹ��==�ж�
bool equal(double a, double b)
{
	if (abs(a - b) < DBL_EPSILON)
		return true;
	return false;
}

// ��ͨ�ⷨ����

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