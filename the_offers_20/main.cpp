/*
*	��Ŀ����ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬�ַ�����+100������5e2������-123����
*		  ��3.1416������-1E-16������ʾ��ֵ������12e������1a3.14������+-5������12e+5.4�������ǡ�
* 
*	tips���ַ�����-> A:�������֡�B:С�����֡�C:ָ������
*		  A[.[B]][e|EC]����.B[e|EC]
* 
*	ASCII: e: 101, E: 69, '9':  57
* 
*	���ж��ַ����Ƿ��з��ţ����ж�ÿλ�ַ��Ƿ���0~9
*/

#include<iostream>
#include<exception>
using namespace std;

bool scanInteger(const char** str);
bool scanUnsignedInteger(const char** str);

bool isNumeric(const char* str)
{
	if (str == nullptr)
		return false;

	// ��Ҫ�����ж�.ǰ.���e/Eǰe/E����ַ��Ƿ���������
	bool numeric = scanInteger(&str);

	// ��������ֻ��С�����ֵ����֣��硰.123��
	// ������֡�.�������������С������
	if (*str == '.')
	{
		++str;

		// ����һ�д���ʹ��||��ԭ��
		// 1.С������û���������֣���.123����0.123
		// 2.С����������û�����֣���233.����233.0
		// 3.��Ȼ��С����ǰ��ͺ��涼����������233.666
		numeric = scanUnsignedInteger(&str) || numeric;
	}

	// ������֡�e����E����������������ֵ�ָ������
	if (*str == 'e' || *str == 'E')
	{
		++str;

		// ����һ�д�����&&��ԭ��
		// 1.��e��Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣���.e2��e1��
		// 2.��e��E����û������ʱ�������ַ������ܱ�ʾ���֣���12e��12e+5.4
		numeric = numeric && scanInteger(&str);
	}

	return numeric && *str == '\0';
}

// ɨ���ַ�����0��~��9������λ������ƥ��ģʽ�е�B����
bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;
	// δ��ĩβ���ַ��ڡ�0������9��֮��
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str); // ������һλ

	// ��str�д�������0~9������ʱ������true
	return *str > before;
}

// ɨ���ʾ������Ϊ��ʵ��0~9����λ������ƥ��A��C����
bool scanInteger(const char** str)
{
	// ɨ�迪ͷΪ+/-�ŵ��ַ���
	if (**str == '+' || **str == '-')
		++(*str); // ��������λ

	return scanUnsignedInteger(str);
}


int main(int argc, char* argv)
{
	cout << isNumeric("5e2") << endl;
	cout << isNumeric("+5e2") << endl;
	cout << isNumeric("12e+5.4") << endl;
}