/*
*	��Ŀ��ɾ���������ظ��Ľڵ�
*		  ��һ������������У����ɾ���ظ��Ľڵ㣿���磺
*				ɾ��ǰ��1->2->3->3->4->4->5
*				ɾ����1->2->5
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
	// �ݴ��ж�
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;

		// ֵ�ظ��Ľڵ���needDeleteΪtrue
		if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
			needDelete = true;

		if (!needDelete) // û���ظ��ڵ�ͼ������±���
		{
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else
		{
			int value = pNode->m_nValue; // �����ظ�ֵ
			ListNode* pToBeDel = pNode;  // ����ǰ�ڵ���Ϊ��ɾ���ڵ�
			while (pToBeDel != nullptr && pToBeDel->m_nValue == value) // ѭ��ɾ���ظ��ڵ�
			{
				pNext = pToBeDel->m_pNext;

				delete pToBeDel;	// ɾ���ڵ�
				pToBeDel = nullptr; // ָ���ÿ�

				pToBeDel = pNext;
			}

			// ɾ�����ظ��ڵ㣬�������±���
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