/*
*  题目：求斐波那契数列的第n项
*/


#include<iostream>
using namespace std;

long long Fibonacci(unsigned n)
{
	int result[2] = { 0, 1 };

	if (n < 2)
		return result[n];

	long long fibNMinusOne = 1;
	long long fibNMinusTwo = 0;
	long long fibN = 0;

	for (unsigned int i = 2; i <= n; ++i)
	{
		fibN = fibNMinusOne + fibNMinusTwo;

		fibNMinusTwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}

	return fibN;
}

int main(int argc, char* argv)
{
	cout << Fibonacci(100) << endl;
}

