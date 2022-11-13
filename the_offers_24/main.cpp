/*
*	题目：定义一个函数，输入一个链表的头节点，反转该链表并输出链表的头节点。
* 
*	tips: 需要使用3个指针
*/

struct ListNode
{
	int m_pValue;
	ListNode* m_pNext;
};

ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReversedHead = nullptr; // 反转后的头节点
	ListNode* pNode = pHead;
	ListNode* pPrev = nullptr;

	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext; // 当前节点的下一个节点

		if (pNext == nullptr)
			pReversedHead = pNode;		  // 当前节点为需要反转的节点

		pNode->m_pNext = pPrev;			  // 当前节点指向上一个节点

		pPrev = pNode;					  // 前一个节点设置为当前节点
		pNode = pNext;					  // 当前节点设置为原来的下一个节点
	}

	return pReversedHead;
}

int main(int argc, char* argv)
{

}