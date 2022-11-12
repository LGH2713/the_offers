/*
*	题目：在O(1)时间内删除链表节点
*		  给定单向链表的头节点和下一个节点指针，定义一个函数在O(1)时间内删除该节点。链表节点与函数的定义如下：
* 
*	tips: 删除一个节点不一定需要知道这个节点的上一个节点，只需要将下一个节点的内容覆盖到需要被删除节点的内容上
*		  再删除下一个节点即可
* 
*	以下代码基于一个假设：要删除的节点的确在链表中。如未说明则确定节点在链表中的职责被推给DeleteNode()，复杂度O(n)
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
	// 容错判断
	if (!pListHead || !pToBeDeleted)
		return;

	// 要删除的节点不是尾节点
	if (pToBeDeleted->m_pNext != nullptr)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = nullptr;
	}
	// 链表只有一个节点，删除头节点（也是尾节点）
	else if (*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pListHead = nullptr;
	}
	// 链表中有多个节点，删除尾节点
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