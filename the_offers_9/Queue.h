#pragma once
#include <stack>
#include <exception>

using namespace std;

template <typename T> class CQueue
{
public:
	CQueue();
	~CQueue();

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

// 记得补充实现构造函数和析构函数
template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template<typename T> void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead()
{
	// 如果stack2栈不为空则直接返回stack2的top元素
	// 若stack2栈为空，则将stack1中的元素按栈顺序搬运到stack2，然后再取出top元素
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0)
		throw new exception("queue is empty");

	T head = stack2.top();
	stack2.pop();

	return head;
}