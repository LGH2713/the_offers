/*
*	��Ŀ����ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ�����
*		  ��������Σ�����0�Σ����ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���""aaa"��ģʽ"a.a"��"ab*ac*a"ƥ��
*		  ����"aa.a"��"ab.a"����ƥ��
*/

#include <iostream>
#include <exception>
using namespace std;

bool match(const char* str, const char* pattern);
bool matchCore(const char* str, const char* pattern);

bool match(const char* str, const char* pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;

	return matchCore(str, pattern);
}

bool matchCore(const char* str, const char* pattern)
{
	// ģʽ���ַ�����Ϊ�գ�ƥ��ɹ�
	if (*str == '\0' && *pattern == '\0')
		return true;
	// �ַ���δƥ���꣬ģʽ�Ѿ�ƥ���꣬ƥ��ʧ��
	if (*str != '\0' && *pattern == '\0')
		return false;

	// ģʽ���¸��ַ�Ϊ * 
	if (*(pattern + 1) == '*')
	{
		// ģʽ�ĵ�ǰ�ַ����ַ����ַ���ͬ��ģʽ��ǰ�ַ���Ϊ'.'���ַ���δ��ĩβ
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			// ģʽ�ƶ�����һλ
			return matchCore(str + 1, pattern + 2) // ����ƥ���ַ�������һλ��ģʽ������λ
			// ģʽ���ڵ�ǰλ
			|| matchCore(str + 1, pattern)		   // ����ƥ���ַ�������һλ����ǰģʽ�ĵ�ǰλ
			// ģʽ����һ��'*'
			|| matchCore(str, pattern + 2);		   // ����ƥ���ַ�����ǰλ��ģʽ������λ
		else
			// ģʽ����һ��'*'
			return matchCore(str, pattern + 2);
	}

	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1); // ����ƥ���ַ�������һλ��ģʽ����һλ

	return false;
}

int main(int argc, char* argv)
{
	cout << match("aaa", "a.a") << endl;
	cout << match("aaa", "ab*ac*a") << endl;
	cout << match("aa.a", "ab*a") << endl;
}