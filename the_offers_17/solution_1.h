#pragma once
#include <iostream>
class Solution_1
{
public:
	void Print1ToMaxOfNDigits(int n)
	{
		// 位数小于0直接返回
		if (n <= 0)
			return;

		// 初始化数字数组
		char* number = new char[n + 1];
		// 数字数组每位设为'0'
		memset(number, '0', n);
		number[n] = '\0';

		while (!Increment(number))
		{
			PrintNumber(number);
		}

		delete[] number;
	}


	// 判断是否已经到达最大n位数
	bool Increment(char* number)
	{
		// 溢出标志位
		bool isOverflow = false;
		int nTakeOver = 0;
		// 计算位数
		int nLength = strlen(number);
		for (int i = nLength - 1; i >= 0; i--)
		{
			// 10以内加法
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)
				nSum++;

			// nSum大于10需进位
			if (nSum >= 10)
			{
				if (i == 0)
					isOverflow = true;
				else // 10位重置
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
		// 该标志位用于标识当前位是否是'0'
		bool isBeginning0 = true;
		int nLength = strlen(number);

		for (int i = 0; i < nLength; ++i)
		{
			// 当前位为'0'，则跳过不打印
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