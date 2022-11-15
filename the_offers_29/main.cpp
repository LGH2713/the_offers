/*
*	��Ŀ������һ�����󣬰��մ�������һ˳ʱ���˳��һ�δ�ӡ��ÿ������
*/

#include<iostream>
#include<exception>
using namespace std;
void PrintNumber(int number);
void PrintMatrixClockwisely(int** numbers, int columns, int rows);
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start);

void PrintNumber(int number)
{
	printf("%d\t", number);
}

void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
	// �ݴ��ж�
	if (numbers == nullptr || columns <= 0 || rows <= 0)
		return;

	int start = 0;

	while (columns > start * 2 && rows > start * 2)
	{
		PrintMatrixInCircle(numbers, columns, rows, start);

		++start;
	 }
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
{
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	// ����һ��
	for (int i = start; i <= endX; ++i)
	{
		int number = numbers[start][i];
		PrintNumber(number);
	}
	
	// �ϵ���һ��
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			int number = numbers[i][endX];
			PrintNumber(number);
		}
	}

	// �ҵ���һ��
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			int number = numbers[endY][i];
			PrintNumber(number);
		}
	}

	// �µ���һ��
	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i >= start + 1; --i)
		{
			int number = numbers[i][start];
			PrintNumber(number);
		}
	}
}

void Test(int columns, int rows)
{
	printf("Test Begin: %d columns, %d rows.\n", columns, rows);

	if (columns < 1 || rows < 1)
		return;

	int** numbers = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		numbers[i] = new int[columns];
		for (int j = 0; j < columns; ++j)
		{
			numbers[i][j] = i * columns + j + 1;
		}
	}

	PrintMatrixClockwisely(numbers, columns, rows);
	printf("\n");

	for (int i = 0; i < rows; ++i)
		delete[](int*)numbers[i];

	delete[] numbers;
}


int main(int argc, char* argv)
{
	Test(1, 1);
	Test(5, 5);
}