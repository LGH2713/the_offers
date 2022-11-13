/*
*	��Ŀ�����һ�������а�����������ҳ�������ڽڵ㣿
* 
*	˼·���ж������л�->���㻷�нڵ�ĸ���->�ҵ���ڽڵ�
*/

#include<iostream>
#include<exception>
using namespace std;

struct ListNode
{
	int m_pValue;
	ListNode* m_pNext;
};

// �ú�������Ѱ�������ڵ�
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
		// pFastÿ����������pSlowÿ����һ��
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

// �ú������ڼ��㻷�еĽڵ���Ŀ���ҳ�������ڼ��ڵ�
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);
	if (meetingNode == nullptr)
		return nullptr;

	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;			// ��¼��ǰ�ڵ�
	while (pNode1->m_pNext != meetingNode)  // ��һȦ�ֻص�meeting�ڵ㣬���㻷�нڵ����Ŀ
	{
		pNode1 = pNode1->m_pNext;
		++nodesInLoop;
	}

	pNode1 = pHead;
	// �ߵ�����ͷ�ڵ�nodesInLoop���Ľڵ�
	for (int i = 0; i < nodesInLoop; ++i)
		pNode1 = pNode1->m_pNext;

	ListNode* pNode2 = pHead;
	// pNode1��pNode2ͬʱ�ߣ������ڵ������Ľڵ������ڽڵ�
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