/*
*	��Ŀ����O(1)ʱ����ɾ������ڵ�
*		  �������������ͷ�ڵ����һ���ڵ�ָ�룬����һ��������O(1)ʱ����ɾ���ýڵ㡣����ڵ��뺯���Ķ������£�
* 
*	tips: ɾ��һ���ڵ㲻һ����Ҫ֪������ڵ����һ���ڵ㣬ֻ��Ҫ����һ���ڵ�����ݸ��ǵ���Ҫ��ɾ���ڵ��������
*		  ��ɾ����һ���ڵ㼴��
* 
*	���´������һ�����裺Ҫɾ���Ľڵ��ȷ�������С���δ˵����ȷ���ڵ��������е�ְ���Ƹ�DeleteNode()�����Ӷ�O(n)
*/

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

#include <iostream>
#include<exception>


void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	// �ݴ��ж�
	if (!pListHead || !pToBeDeleted)
		return;

	// Ҫɾ���Ľڵ㲻��β�ڵ�
	if (pToBeDeleted->m_pNext != nullptr)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = nullptr;
	}
	// ����ֻ��һ���ڵ㣬ɾ��ͷ�ڵ㣨Ҳ��β�ڵ㣩
	else if (*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pListHead = nullptr;
	}
	// �������ж���ڵ㣬ɾ��β�ڵ�
	else
	{
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted)
			pNode = pNode->m_pNext;

		pNode->m_pNext = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

#include<unordered_map>
using namespace std;
int main(int argc, char* argv)
{
	unordered_multimap<string, int> multimap = {
		{"hello", 1},
		{"hello", 1},
		{"hello", 3}
	};

	cout << "sizeof undered_multimap = " << multimap.count("hello") << endl;
	auto it_1 = multimap.find("hello");
	for (; it_1 != multimap.end(); ++it_1)
		cout << "undered_multimap value = " << it_1->second << endl;

	unordered_map<string, int> map = {
		{"hello", 1},
		{"hello", 1},
		{"hello", 3}
	};

	cout << "sizeof undered_map = " << map.count("hello") << endl;
	auto it_2 = map.find("hello");
	for (; it_2 != map.end(); ++it_2)
		cout << "undered_map value = " << it_2->second << endl;
}