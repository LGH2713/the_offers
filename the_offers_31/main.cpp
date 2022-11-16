/*
*	��Ŀ�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ������С�����ѹ��ջ���������־�����ȡ�
*	���磺ѹ������=>{1, 2, 3, 4, 5}		��������=>{4, 5, 3, 2, 1}
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

		// ����ʱ��pNextPop == ���г��ȣ�pPopһֱΪ0������ջ��Ԫ�أ�
		while (pNextPop - pPop < nLength)
		{
			// ѹջ���̡�������ջΪ�ջ�����ջջ��Ԫ���뵯ջԪ�ز�һ��������һ����Ҫ����ջ��Ԫ�أ���
			// �򽫰�ѹջ˳������ѹ��˳��ջ
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				if (pNextPush - pPush == nLength)
					break;

				stackData.push(*pNextPush);

				pNextPush++;
			}

			if (stackData.top() != *pNextPop)
				break;

			// ������Ҫ��ջ��Ԫ�أ�ֱ�ӵ�������ջ
			stackData.pop();
			// ��ջ����Ҳ������һλ
			pNextPop++;
		}

		// ����ջ�Ѿ�Ϊ���ҵ��������Ѿ�������λ
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