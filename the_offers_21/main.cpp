/*
*	题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，是的所有奇数位都位于数组的前半部分，所有的偶数位都位于数组
*		  的后半部分。
* 
*	tips：双指针法
*/

#include<iostream>
#include<exception>
using namespace std;

void ReorderOddEvent(int* pData, unsigned int length)
{
	if (pData == nullptr || length == 0)
		return;

	int* pBegin = pData;
	int* pEnd = pData + length - 1;

	// *pBegin & 0x1用于判断奇数
	while (pBegin < pEnd)
	{
		// 向后移动pBegin，直到它指向偶数
		while (pBegin < pEnd && (*pBegin & 0x1) != 0)
			pBegin++;

		// 向前移动pEnnnd，直到它指向奇数
		while (pBegin < pEnd && (*pEnd & 0x1) == 0)
			pEnd--;

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}


int main(int argc, char* argv)
{
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	ReorderOddEvent(array, 10);

	for (int i = 0; i < 10; i++)
		cout << array[i] << " ";
}