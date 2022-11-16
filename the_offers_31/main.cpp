/*
*	题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出序列。假设压入栈的所有数字均不相等。
*	例如：压入序列=>{1, 2, 3, 4, 5}		弹出序列=>{4, 5, 3, 2, 1}
*/

#include <stack>

bool IsPopOrderconst(const int* pPush, const int* pPop, int nLength)
{
	bool bPossible = false;
	if (pPush != nullptr && pPop != nullptr && nLength > 0)
	{
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		std::stack<int> stackData;

		// 结束时，pNextPop == 序列长度，pPop一直为0（即是栈顶元素）
		while (pNextPop - pPop < nLength)
		{
			// 压栈过程。当数据栈为空或数据栈栈顶元素与弹栈元素不一样（即下一个需要弹出栈的元素），
			// 则将按压栈顺序将数据压入顺序栈
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				if (pNextPush - pPush == nLength)
					break;

				stackData.push(*pNextPush);

				pNextPush++;
			}

			if (stackData.top() != *pNextPop)
				break;

			// 出现需要弹栈的元素，直接弹出数据栈
			stackData.pop();
			// 弹栈序列也进入下一位
			pNextPop++;
		}

		// 数据栈已经为空且弹出序列已经到结束位
		if (stackData.empty() && pNextPop - pPop == nLength)
			bPossible = true;
	}

	return bPossible;
}

void Test(const char* testName, const int* pPush, const int* pPop)
{
	printf("%s begins: ", testName);

	if (IsPopOrderconst(pPush, pPop, 5))
		printf("Passed!\n");
	else
		printf("Failed!\n");
}

void Test1()
{
	const int push[] = {1, 2, 3, 4, 5};
	const int pop[] = { 4, 5, 3, 2, 1 };
	Test("Test1", (const int*)push, (const int*)pop);
}

int main(int argc, char* argv)
{
	Test1();
}