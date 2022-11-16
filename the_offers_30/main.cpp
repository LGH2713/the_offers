/*
*	��Ŀ������ջ���ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�min������
*		  �ڸ�ջ�У�����min��push��pop��ʱ�临�Ӷȶ���O(1)
* 
*	tips: ʹ�ø���ջ�洢��СԪ�أ�ѹ��Ԫ�ر���СԪ�ش����ظ�ѹ����СԪ�أ�����ѹ���µ���СԪ��
*/

#include<iostream>
#include<exception>
#include"StackWithMin.h"

// ========= ���Դ��� ==========
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