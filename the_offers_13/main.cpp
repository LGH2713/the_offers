/*
*	题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，他每次可以向左、上、右、下移动一格
*		  但不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入(35, 37)，因为3 + 5 + 3 + 7 = 18
*		  但他不能进入方格(35, 38)，因为3 + 5 + 3 + 8 = 19。请问该机器人能够达到多少个格子。
* 
*	模块分割：1.初始化函数 2.回溯核心函数 3.边界判断/相等判断函数 4.计算数位和函数
*/

#include <iostream>
#include <exception>
using namespace std;

int movingCount(int threashold, int rows, int cols);
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visted);
bool check(int threshold, int rows, int cols, int row, int col, bool* visted);
int getDigitSum(int number);

int movingCount(int threashold, int rows, int cols)
{
	if (threashold < 0 || rows <= 0 || cols <= 0)
		return 0;

	// 设置访问矩阵
	bool* visted = new bool[rows * cols];
	// 访问矩阵置零
	for (int i = 0; i < rows * cols; ++i)
		visted[i] = false;

	int count = movingCountCore(threashold, rows, cols, 0, 0, visted);

	// 清理空间
	delete[]visted;

	return count;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visted)
{
	int count = 0;

	// 每次调用都判断当前方格能不能走
	if (check(threshold, rows, cols, row, col, visted))
	{
		visted[row * cols + col] = true;

		// 计算当前步 + 上 / 左 / 下 / 右 步（回溯主体）
		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visted)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visted)
			+ movingCountCore(threshold, rows, cols, row + 1, col, visted)
			+ movingCountCore(threshold, rows, cols, row, col + 1, visted);
	}

	return count;
}

// 检查能否走当前这一步
bool check(int threshold, int rows, int cols, int row, int col, bool* visted)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols    // 判断边界情况
		&& getDigitSum(row) + getDigitSum(col) <= threshold // 判断数位和是否小于阈值
		&& !visted[row * cols + col])						// 判断当前位置是否走过
		return true;

	return false;
}

// 计算数位和
int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}

	return sum;
}

/*  测试  */
void test(const char* testName, int threshold, int rows, int cols, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (movingCount(threshold, rows, cols) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

// 方格多行多列
void test1()
{
	test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2()
{
	test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
	test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4()
{
	test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
	test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
	test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7()
{
	test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8()
{
	test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9()
{
	test("Test9", -10, 10, 10, 0);
}


int main(int argc, char* argv)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();

	return 0;

}