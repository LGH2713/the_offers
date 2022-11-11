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
	if (length < 2)		// 无法分割
		return 0;
	if (length == 2)	// 只能分割为1 1
		return 1;
	if (length == 3)	// 最大分割为1 2
		return 2;

	// 动规数组
	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;

	// 每一步的最大值都是基于上一次的结果
	for (int i = 4; i <= length; ++i)
	{
		max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			// 计算出当前位的值
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

	// 尽可能剪长度3
	int timesOf3 = length / 3;

	if (length - timesOf3 * 3 == 1)
		timesOf3 -= 1;

	// 不能减长度3的就尽可能剪长度2
	int timesOf2 = (length - timesOf3 * 3) / 2;

	// 计算出最大乘积
	return static_cast<double>(pow(3, timesOf3)) * static_cast<int>(pow(2, timesOf2));
}


int main(int argc, char* argv)
{
	cout << maxProductAfterCutting_solution1(8) << endl;
	cout << maxProductAfterCutting_solution2(8) << endl;
}