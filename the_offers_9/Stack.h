#pragma once
#include <queue>
#include <exception>
using namespace std;

template <typename T> class CStack
{
public:
	CStack();
	~CStack();

	void push_back(const T& element);
	T pop_front();

private:
	queue<T> queue1;
	queue<T> queue2;
};

template<typename T> CStack<T>::CStack(void)
{

}

template<typename T> CStack<T>::~CStack(void)
{

}

template<typename T> void CStack<T>::push_back(const T& element)
{
	if (queue1.empty() && queue2.empty())
	{
		queue1.push(element);
		return;
	}

	if (queue1.empty())
	{
		queue1.push(element);
	}
	else
	{
		queue2.push(element);
	}
}

template<typename T> T CStack<T>::pop_front()
{
	if (queue1.empty() && queue2.empty())
		throw exception("Invalid input");

	T res;

	if (queue1.empty())
	{
		while (queue2.size() != 1)
		{
			T temp = queue2.front();
			queue2.pop();
			queue1.push(temp);
		}
		res = queue2.front();
		queue2.pop();
	}
	else
	{
		while (queue1.size() != 1)
		{
			T temp = queue1.front();
			queue1.pop();
			queue2.push(temp);
		}
		res = queue1.front();
		queue1.pop();
	}

	return res;
}
