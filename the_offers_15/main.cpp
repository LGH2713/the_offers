/*
*	��Ŀ����ʵ��һ������������һ��������������������Ʊ�ʾ��1�ĸ��������磬��9��ʾ�ɶ�������1001��
*		  ��2λ��1.��ˣ��������9����ú������2��
* 
*	tips������Ч�ʱ�λ����͵ö࣬Ч��(x >> 1) > Ч��(x / 2)
*/

#include <iostream>
#include <exception>
using namespace std;

// ����ⷨ 32λ������ҪӲ��ѭ��32��
/*
int NumberOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;

	while (flag)
	{
		if (n & flag)
			count++;

		flag = flag << 1;
	}
	return count;
}
*/


// ���׽ⷨ
// ˼·����һ��������ȥ1���ٺ�ԭ�����������㣬�ͻ�Ѹ��������ұߵ�1���0.��ôһ�������Ķ��������ж��ٸ�1��
//       �Ϳ��Խ��ж��ٴ����ֲ���
//  
//  ����1001 -> -1 -> 1000 -> ��1001�������� -> 1000 -> -1 -> 0111 -> ��1000�������� -> 0000 -> ����
int NumberOf1(int n)
{
	int count = 0;

	while (n)
	{
		++count;
		n = (n - 1) & n;
	}

	return count;
}


int main(int argc, char* argv)
{
	cout << NumberOf1(9) << endl;
}