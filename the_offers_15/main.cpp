/*
*	题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如，把9表示成二进制是1001，
*		  有2位是1.因此，如果输入9，则该函数输出2；
* 
*	tips：除法效率比位运算低得多，效率(x >> 1) > 效率(x / 2)
*/

#include <iostream>
#include <exception>
using namespace std;

// 常规解法 32位整数需要硬性循环32次
/*
int NumberOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;

	while (flag)
	{
		if (n & flag)
			count++;

		flag = flag << 1;
	}
	return count;
}
*/


// 进阶解法
// 思路：把一个整数减去1，再和原整数做与运算，就会把该整数最右边的1变成0.那么一个整数的二进制中有多少个1，
//       就可以进行多少次这种操作
//  
//  例：1001 -> -1 -> 1000 -> 和1001做与运算 -> 1000 -> -1 -> 0111 -> 和1000做与运算 -> 0000 -> 结束
int NumberOf1(int n)
{
	int count = 0;

	while (n)
	{
		++count;
		n = (n - 1) & n;
	}

	return count;
}


int main(int argc, char* argv)
{
	cout << NumberOf1(9) << endl;
}