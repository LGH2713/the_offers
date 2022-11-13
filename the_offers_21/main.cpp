/*
*	题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，是的所有奇数位都位于数组的前半部分，所有的偶数位都位于数组
*		  的后半部分。
* 
*	tips：双指针法
*/

#include<iostream>
#include<exception>
using namespace std;

void ReorderOddEvent_1(int* pData, unsigned int length)
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

void Reorder(int* pData, unsigned int length, bool(*func)(int))
{
	if (pData == nullptr || length == 0)
		return;

	int* pBegin = pData;
	int* pEnd = pData + length - 1;

	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
			pBegin++;

		while (pBegin < pEnd && func(*pEnd))
			pEnd--;

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEvent(int n)
{
	return (n & 1) == 0;
}

void ReorderOddEvent_2(int* pData, unsigned int length)
{
	Reorder(pData, length, isEvent);
}


int main(int argc, char* argv)
{
	int array_1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	ReorderOddEvent_1(array_1, 10);

	for (int i = 0; i < 10; i++)
		cout << array_1[i] << " ";

	cout << endl;

	int array_2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	ReorderOddEvent_2(array_2, 10);
	for (int i = 0; i < 10; i++)
		cout << array_2[i] << " ";
}