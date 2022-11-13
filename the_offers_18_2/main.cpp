/*
*	题目：删除链表中重复的节点
*		  在一个排序的链表中，如何删除重复的节点？例如：
*				删除前：1->2->3->3->4->4->5
*				删除后：1->2->5
*/				

#include<iostream>
#include<exception>
using namespace std;


struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void DeleteDuplication(ListNode** pHead)
{
	// 容错判断
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;

		// 值重复的节点标记needDelete为true
		if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
			needDelete = true;

		if (!needDelete) // 没有重复节点就继续向下遍历
		{
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else
		{
			int value = pNode->m_nValue; // 保存重复值
			ListNode* pToBeDel = pNode;  // 将当前节点标记为被删除节点
			while (pToBeDel != nullptr && pToBeDel->m_nValue == value) // 循环删除重复节点
			{
				pNext = pToBeDel->m_pNext;

				delete pToBeDel;	// 删除节点
				pToBeDel = nullptr; // 指针置空

				pToBeDel = pNext;
			}

			// 删除完重复节点，继续向下遍历
			if (pPreNode == nullptr)
				*pHead = pNext;
			else
				pPreNode->m_pNext = pNext;

			pNode = pNext;
		}
	}
}


int main(int argc, char* argv)
{
	return 0;
}