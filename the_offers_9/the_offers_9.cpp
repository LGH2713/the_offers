/*
	题目：利用两个栈实现一个队列。声明如下，请实现成员函数
*/

#include "Queue.h"
#include <iostream>

int main(int argc, char* argv)
{
	CQueue<int> queue;

	for (int i = 0; i < 10; i++)
	{
		queue.appendTail(i);
	}

	for(int i = 0; i < 10; i++)
		std::cout << queue.deleteHead() << std::endl;
}