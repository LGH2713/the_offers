/*
*	��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳���ǵ���������λ��λ�������ǰ�벿�֣����е�ż��λ��λ������
*		  �ĺ�벿�֡�
* 
*	tips��˫ָ�뷨
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


int main(int argc, char* argv)
{
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	ReorderOddEvent(array, 10);

	for (int i = 0; i < 10; i++)
		cout << array[i] << " ";
}