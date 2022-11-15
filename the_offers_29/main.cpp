/*
*	题目：输入一个矩阵，按照从外向里一顺时针的顺序一次打印出每个数字
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
	// 容错判断
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

	// 左到右一行
	for (int i = start; i <= endX; ++i)
	{
		int number = numbers[start][i];
		PrintNumber(number);
	}
	
	// 上到下一行
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			int number = numbers[i][endX];
			PrintNumber(number);
		}
	}

	// 右到左一行
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			int number = numbers[endY][i];
			PrintNumber(number);
		}
	}

	// 下到上一行
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