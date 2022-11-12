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
using namespace std;


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

#include"../List.h"
// ====================���Դ���====================
void Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    DeleteNode(&pListHead, pNode);

    printf("The result list is: \n");
    PrintList(pListHead);
}

// �������ж����㣬ɾ���м�Ľ��
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��β���
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��ͷ���
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode1);

    DestroyList(pNode1);
}

// ������ֻ��һ����㣬ɾ��ͷ���
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1, pNode1);
}

// ����Ϊ��
void Test5()
{
    Test(nullptr, nullptr);
}


int main(int argc, char* argv)
{
    Test1();
}