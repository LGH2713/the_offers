/*
*	��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳���ǵ���������λ��λ�������ǰ�벿�֣����е�ż��λ��λ������
*		  �ĺ�벿�֡�
* 
*	tips��˫ָ�뷨
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

	// *pBegin & 0x1�����ж�����
	while (pBegin < pEnd)
	{
		// ����ƶ�pBegin��ֱ����ָ��ż��
		while (pBegin < pEnd && (*pBegin & 0x1) != 0)
			pBegin++;

		// ��ǰ�ƶ�pEnnnd��ֱ����ָ������
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