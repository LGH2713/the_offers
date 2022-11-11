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
	// �ų����󲻴��ڣ���СΪ0*0���ж��ַ���Ϊ��ָ������
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;

	// ���÷��ʾ��󣬴�С���ַ�������ͬ
	bool* visted = new bool[rows * cols];

	// ���ʾ����ÿ�
	memset(visted, 0, rows * cols);

	// ��ʼ��·������
	int pathLength = 0;

	// ��ѭ�������к���
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

// ���Ĵ���
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col,
	const char* str, int& pathLength, bool* visted)
{
	// ����Ѿ��ߵ��ж��ַ���ĩβ����Ϊ·�����ڣ�����true
	if (str[pathLength] == '\0')
		return true;

	bool hasPath = false;
	if (row >= 0 && row < rows && cols >= 0 && col < cols // �ж�����û�����������
		&& matrix[row * cols + col] == str[pathLength]    // �жϵ�ǰѰ���ַ��뵱ǰλ���Ƿ�һ�£����жϣ�
		&& !visted[row * cols + col])					  // �жϸ�·���Ƿ��Ѿ��߹�
	{
		++pathLength;						// �ҵ���Ӧ�ַ���·������+1
		visted[row * cols + col] = true;	// ��־λ�ã��ҹ���λ����Ϊ��


		// ����Ѱ��
		hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
			str, pathLength, visted)								// ������
			|| hasPathCore(matrix, rows, cols, row - 1, col,
				str, pathLength, visted)							// ������
			|| hasPathCore(matrix, rows, cols, row, col + 1,
				str, pathLength, visted)							// ������
			|| hasPathCore(matrix, rows, cols, row + 1, col,
				str, pathLength, visted);							// ������

		if (!hasPath)
		{
			// �������ߵ�һ��û���ҵ���Ӧ·�����ҵ�·������-1������һ���мӵ�pathLength���������Ҳ�����Ҫ��������
			// ͬʱ��Ǹ�·��û���߹�
			--pathLength;
			visted[row * cols + col] = false;
		}
	}

	// �����Ƿ��ҵ�·��
	return hasPath;
}

int main(int argc, char* argv)
{
	char str[] = "bfce";
	std::cout << hasPath(Matrix, 3, 4, str) << std::endl;
}