#pragma once
#include <iostream>
class Solution_1
{
public:
	void Print1ToMaxOfNDigits(int n)
	{
		// λ��С��0ֱ�ӷ���
		if (n <= 0)
			return;

		// ��ʼ����������
		char* number = new char[n + 1];
		// ��������ÿλ��Ϊ'0'
		memset(number, '0', n);
		number[n] = '\0';

		while (!Increment(number))
		{
			PrintNumber(number);
		}

		delete[] number;
	}


	// �ж��Ƿ��Ѿ��������nλ��
	bool Increment(char* number)
	{
		// �����־λ
		bool isOverflow = false;
		int nTakeOver = 0;
		// ����λ��
		int nLength = strlen(number);
		for (int i = nLength - 1; i >= 0; i--)
		{
			// 10���ڼӷ�
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)
				nSum++;

			// nSum����10���λ
			if (nSum >= 10)
			{
				if (i == 0)
					isOverflow = true;
				else // 10λ����
				{
					nSum -= 10;
					nTakeOver = 1;
					number[i] = '0' + nSum;
				}
			}
			else
			{
				number[i] = '0' + nSum; // '0' + nSum = 'nSum'
				break;
			}
		}

		return isOverflow;
	}

	void PrintNumber(char* number)
	{
		// �ñ�־λ���ڱ�ʶ��ǰλ�Ƿ���'0'
		bool isBeginning0 = true;
		int nLength = strlen(number);

		for (int i = 0; i < nLength; ++i)
		{
			// ��ǰλΪ'0'������������ӡ
			if (isBeginning0 && number[i] != '0')
				isBeginning0 = false;

			if (!isBeginning0)
			{
				printf("%c", number[i]);
			}
		}

		printf("\t");
	}
};