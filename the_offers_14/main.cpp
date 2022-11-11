/*
*	题目：给你一根长度为n的绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0], k[1], ... ,k[m]。
*		  请问k[m]可能的最大乘积是多少？例如，当绳子的长度为8时，我们把它剪成长度分别为2， 3， 3的三段，此时得到的最大
*		  乘积是18
*/

#include <iostream>
#include <exception>
using namespace std;

//================  动态规划  ====================
int maxProductAfterCutting_solution1(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i = 4; i <= length; ++i)
	{
		max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;

			products[i] = max;
		}
	}

	max = products[length];

	delete[]products;

	return max;
}

//================  贪婪算法  ====================
int maxProductAfterCutting_solution2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int timesOf3 = length / 3;

	if (length - timesOf3 * 3 == 1)
		timesOf3 -= 1;

	int timesOf2 = (length - timesOf3 * 3) / 2;

	return static_cast<double>(pow(3, timesOf3)) * static_cast<int>(pow(2, timesOf2));
}


int main(int argc, char* argv)
{
	cout << maxProductAfterCutting_solution1(50) << endl;
	cout << maxProductAfterCutting_solution2(50) << endl;
}