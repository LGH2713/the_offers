/*
	题目：利用两个栈实现一个队列。声明如下，请实现成员函数
*/

#include "Queue.h"
#include "Stack.h"
#include <iostream>

void test_1()
{
	CQueue<int> queue;

	for (int i = 0; i < 10; i++)
	{
		queue.appendTail(i);
	}

	for (int i = 0; i < 10; i++)
		std::cout << queue.deleteHead() << std::endl;
}

void test_2()
{
	CStack<int> stack;

	for (int i = 0; i < 10; i++)
		stack.push_back(i);

	for (int i = 0; i < 10; i++)
		std::cout << stack.pop_front() << std::endl;
}

int main(int argc, char* argv)
{
	test_2();
}