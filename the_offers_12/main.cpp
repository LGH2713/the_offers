/*
*	题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，
*		  每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径就不能再次进入该格子。
*		  例如，在下面的3 * 4的矩阵中包含一条字符串“bfce”路径（路径中的字母用*标出）。但矩阵中不包含字符串“abfb”
*		  的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
* 
*	矩阵：
*		a	*b	t	g
*		c	*f	*c	s
*		j	d	*e	h
*/

#include<iostream>
#include<exception>

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col,
	const char* str, int& pathLength, bool* visted);
bool hasPath(char* matrix, int rows, int cols, char* str);

char Matrix[12] = {
	'a', 'b', 't', 'g',
	'c', 'f', 'c', 's',
	'j', 'd', 'e', 'h'
};

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	// 排除矩阵不存在，大小为0*0，判断字符串为空指针的情况
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;

	// 设置访问矩阵，大小和字符矩阵相同
	bool* visted = new bool[rows * cols];

	// 访问矩阵置空
	memset(visted, 0, rows * cols);

	// 初始化路径长度
	int pathLength = 0;

	// 主循环，先行后列
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visted))
			{
				return true;
			}
		}
	}

	delete[] visted;

	return false;
}

// 核心代码
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col,
	const char* str, int& pathLength, bool* visted)
{
	// 如果已经走到判断字符的末尾则认为路径存在，返回true
	if (str[pathLength] == '\0')
		return true;

	bool hasPath = false;
	if (row >= 0 && row < rows && cols >= 0 && col < cols // 判断行列没有上溢和下溢
		&& matrix[row * cols + col] == str[pathLength]    // 判断当前寻找字符与当前位置是否一致（主判断）
		&& !visted[row * cols + col])					  // 判断该路径是否已经走过
	{
		++pathLength;						// 找到相应字符，路径长度+1
		visted[row * cols + col] = true;	// 标志位置，找过的位置置为真


		// 继续寻找
		hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
			str, pathLength, visted)								// 向左走
			|| hasPathCore(matrix, rows, cols, row - 1, col,
				str, pathLength, visted)							// 向上走
			|| hasPathCore(matrix, rows, cols, row, col + 1,
				str, pathLength, visted)							// 向右走
			|| hasPathCore(matrix, rows, cols, row + 1, col,
				str, pathLength, visted);							// 向下走

		if (!hasPath)
		{
			// 若向下走的一步没有找到相应路径则找到路径长度-1（在下一步中加的pathLength，在这里找不到就要减回来）
			// 同时标记该路径没有走过
			--pathLength;
			visted[row * cols + col] = false;
		}
	}

	// 返回是否找到路径
	return hasPath;
}

int main(int argc, char* argv)
{
	char str[] = "bfce";
	std::cout << hasPath(Matrix, 3, 4, str) << std::endl;
}