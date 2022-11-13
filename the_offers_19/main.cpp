/*
*	题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以
*		  出现任意次（包括0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串""aaa"与模式"a.a"和"ab*ac*a"匹配
*		  但与"aa.a"和"ab.a"均不匹配
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
	// 模式和字符串都为空，匹配成功
	if (*str == '\0' && *pattern == '\0')
		return true;
	// 字符串未匹配完，模式已经匹配完，匹配失败
	if (*str != '\0' && *pattern == '\0')
		return false;

	// 模式的下个字符为 * 
	if (*(pattern + 1) == '*')
	{
		// 模式的当前字符和字符串字符相同或模式当前字符串为'.'且字符串未到末尾
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			// 模式移动到下一位
			return matchCore(str + 1, pattern + 2) // 继续匹配字符串的下一位，模式的下两位
			// 模式留在当前位
			|| matchCore(str + 1, pattern)		   // 继续匹配字符串的下一位，当前模式的当前位
			// 模式忽略一个'*'
			|| matchCore(str, pattern + 2);		   // 继续匹配字符串当前位，模式的下两位
		else
			// 模式忽略一个'*'
			return matchCore(str, pattern + 2);
	}

	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1); // 继续匹配字符串的下一位，模式的下一位

	return false;
}

int main(int argc, char* argv)
{
	cout << match("aaa", "a.a") << endl;
	cout << match("aaa", "ab*ac*a") << endl;
	cout << match("aa.a", "ab*a") << endl;
}