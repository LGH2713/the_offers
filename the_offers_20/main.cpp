/*
*	题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串“+100”、“5e2”、“-123”、
*		  “3.1416”及“-1E-16”都表示数值，但“12e”、“1a3.14”、“+-5”及“12e+5.4”都不是。
* 
*	tips：字符划分-> A:整数部分、B:小数部分、C:指数部分
*		  A[.[B]][e|EC]或者.B[e|EC]
* 
*	ASCII: e: 101, E: 69, '9':  57
* 
*	先判断字符串是否有符号，在判断每位字符是否在0~9
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

	// 主要用于判断.前.后或e/E前e/E后的字符是否满足数字
	bool numeric = scanInteger(&str);

	// 用于区分只有小数部分的数字，如“.123”
	// 如果出现‘.’，则接下来是小数部分
	if (*str == '.')
	{
		++str;

		// 下面一行代码使用||的原因：
		// 1.小数可以没有整数部分，如.123等于0.123
		// 2.小数点后面可以没有数字，如233.等于233.0
		// 3.当然，小数点前面和后面都可以有数字233.666
		numeric = scanUnsignedInteger(&str) || numeric;
	}

	// 如果出现‘e’或‘E’，则接下来是数字的指数部分
	if (*str == 'e' || *str == 'E')
	{
		++str;

		// 下面一行代码用&&的原因
		// 1.当e或E前面没有数字时，整个字符串不能表示数字，如.e2、e1；
		// 2.当e或E后面没有整数时，整个字符串不能表示数字，如12e、12e+5.4
		numeric = numeric && scanInteger(&str);
	}

	return numeric && *str == '\0';
}

// 扫描字符串‘0’~‘9’的数位，用来匹配模式中的B部分
bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;
	// 未到末尾且字符在‘0’到‘9’之间
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str); // 继续下一位

	// 当str中存在若干0~9的数字时，返回true
	return *str > before;
}

// 扫描表示正负号为其实的0~9的数位，用来匹配A、C部分
bool scanInteger(const char** str)
{
	// 扫描开头为+/-号的字符串
	if (**str == '+' || **str == '-')
		++(*str); // 跳过符号位

	return scanUnsignedInteger(str);
}


int main(int argc, char* argv)
{
	cout << isNumeric("5e2") << endl;
	cout << isNumeric("+5e2") << endl;
	cout << isNumeric("12e+5.4") << endl;
}