/*
*	��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·�����ԴӾ����е�����һ��ʼ��
*		  ÿһ�������ھ����������ҡ��ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·���Ͳ����ٴν���ø��ӡ�
*		  ���磬�������3 * 4�ľ����а���һ���ַ�����bfce��·����·���е���ĸ��*��������������в������ַ�����abfb��
*		  ��·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
* 
*	����
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