/*
*	题目：如果一个链表中包含环，如何找出环的入口节点？
* 
*	思路：判断链表有环->计算环中节点的个数->找到入口节点
*/

#include<iostream>
#include<exception>
using namespace std;

struct ListNode
{
	int m_pValue;
	ListNode* m_pNext;
};

// 该函数用于寻找相遇节点
ListNode* MeetingNode(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;

	ListNode* pSlow = pHead->m_pNext;
	if (pSlow == nullptr)
		return nullptr;

	ListNode* pFast = pSlow->m_pNext;
	while (pFast != nullptr && pSlow != nullptr)
	{
		// pFast每次走两步，pSlow每次走一步
		if (pFast != nullptr && pSlow != nullptr)
		{
			if (pFast == pSlow)
				return pFast;

			pSlow = pSlow->m_pNext;

			pFast = pFast->m_pNext;
			if (pFast != nullptr)
				pFast = pFast->m_pNext;
		}
	}
	return nullptr;
}

// 该函数用于计算环中的节点数目并找出环的入口即节点
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);
	if (meetingNode == nullptr)
		return nullptr;

	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;			// 记录当前节点
	while (pNode1->m_pNext != meetingNode)  // 跑一圈又回到meeting节点，计算环中节点的数目
	{
		pNode1 = pNode1->m_pNext;
		++nodesInLoop;
	}

	pNode1 = pHead;
	// 走到距离头节点nodesInLoop步的节点
	for (int i = 0; i < nodesInLoop; ++i)
		pNode1 = pNode1->m_pNext;

	ListNode* pNode2 = pHead;
	// pNode1和pNode2同时走，两个节点相遇的节点就是入口节点
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}

	return pNode1;
}

int main(int argc, char* argv)
{

}