/*
*	题目：定义栈数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。
*		  在该栈中，调用min、push及pop的时间复杂度都是O(1)
* 
*	tips: 使用辅助栈存储最小元素，压入元素比最小元素大则重复压入最小元素，否则压入新的最小元素
*/

#include<iostream>
#include<exception>
#include"StackWithMin.h"

// ========= 测试代码 ==========
void Test(const char* testName, const StackWithMin<int>& stack, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (stack.min() == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

int main(int argc, char* argv)
{
	StackWithMin<int> stack;

	stack.push(3);
	Test("Test1", stack, 3);

	stack.push(4);
	Test("Test2", stack, 3);

	stack.push(2);
	Test("Test3", stack, 3);

}