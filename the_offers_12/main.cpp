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
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;

	bool* visted = new bool[rows * cols];
	memset(visted, 0, rows * cols);

	int pathLength = 0;
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

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col,
	const char* str, int& pathLength, bool* visted)
{
	if (str[pathLength] == '\0')
		return true;

	bool hasPath = false;
	if (row >= 0 && row < rows && cols >= 0 && col < cols
		&& matrix[row * cols + col] == str[pathLength]
		&& !visted[row * cols + col])
	{
		++pathLength;
		visted[row * cols + col] = true;

		hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
			str, pathLength, visted)
			|| hasPathCore(matrix, rows, cols, row - 1, col,
				str, pathLength, visted)
			|| hasPathCore(matrix, rows, cols, row, col + 1,
				str, pathLength, visted)
			|| hasPathCore(matrix, rows, cols, row + 1, col,
				str, pathLength, visted);

		if (!hasPath)
		{
			--pathLength;
			visted[row * cols + col] = false;
		}
	}
	return hasPath;
}

int main(int argc, char* argv)
{
	char str[] = "bfce";
	std::cout << hasPath(Matrix, 3, 4, str) << std::endl;
}