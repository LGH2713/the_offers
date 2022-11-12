/*
*	��Ŀ��ʵ�ֺ��� double Power(double base, int exponent)����base��exponent�η���ͬʱ����Ҫ���Ǵ�������
* 
*	tips����Ҫ����ָ��С��1��������0���������ʹ��ȫ�ֱ����ж������Ƿ�Ƿ�
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

bool g_InvalidInput = false;

double Power(double base, int exponent)
{
	// ȫ�ֱ�ʶ������
	g_InvalidInput = false;

	// 0��0�η�����ѧ����û������ģ����Է���1��0�����ԣ����忴���Թ�Ҫ��
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

// ��ͨ�ⷨ
/*
double powerwithunsignedexponent(double base, unsigned int exponent)
{
	double result = 1.0;
	for (int i = 1; i <= exponent; ++i)
		result *= base;

	return result;
}
*/

// ���׽ⷨ: ʹ��쳲��������м��ٳ˷�����
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