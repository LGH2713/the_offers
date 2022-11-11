/*
*	��Ŀ������һ������Ϊn�����ӣ�������Ӽ���m�Σ�m��n����������n>1����m>1����ÿ�����ӵĳ��ȼ�Ϊk[0], k[1], ... ,k[m]��
*		  ����k[m]���ܵ����˻��Ƕ��٣����磬�����ӵĳ���Ϊ8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2�� 3�� 3�����Σ���ʱ�õ������
*		  �˻���18
*/

#include <iostream>
#include <exception>
using namespace std;

//================  ��̬�滮  ====================
int maxProductAfterCutting_solution1(int length)
{
	if (length < 2)		// �޷��ָ�
		return 0;
	if (length == 2)	// ֻ�ָܷ�Ϊ1 1
		return 1;
	if (length == 3)	// ���ָ�Ϊ1 2
		return 2;

	// ��������
	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;

	// ÿһ�������ֵ���ǻ�����һ�εĽ��
	for (int i = 4; i <= length; ++i)
	{
		max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			// �������ǰλ��ֵ
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;

			products[i] = max;
		}
	}

	max = products[length];

	delete[]products;

	return max;
}

//================  ̰���㷨  ====================
int maxProductAfterCutting_solution2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	// �����ܼ�����3
	int timesOf3 = length / 3;

	if (length - timesOf3 * 3 == 1)
		timesOf3 -= 1;

	// ���ܼ�����3�ľ;����ܼ�����2
	int timesOf2 = (length - timesOf3 * 3) / 2;

	// ��������˻�
	return static_cast<double>(pow(3, timesOf3)) * static_cast<int>(pow(2, timesOf2));
}


int main(int argc, char* argv)
{
	cout << maxProductAfterCutting_solution1(8) << endl;
	cout << maxProductAfterCutting_solution2(8) << endl;
}