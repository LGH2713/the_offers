/*
*	题目：输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序。
* 
*	例：
*		链表1 1->3->5->7
*		链表2 2->4->6->8
*		合并链表 1->2->3->4->5->6->7->8->9
* 
*	容易出现的问题：链表断裂、健壮性差
* 
*/

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	// 容错处理
	if (pHead1 == nullptr)
		return pHead2;
	else if (pHead2 == nullptr)
		return pHead1;

	ListNode* pMergedHead = nullptr;

	if (pHead1->m_nValue < pHead2->m_nValue)
	{
		pMergedHead = pHead1;
		pMergedHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
	}
	else
	{
		pMergedHead = pHead2;
		pMergedHead->m_pNext = Merge(pHead2->m_pNext, pHead1);
	}

	return pMergedHead;
}

int main(int argc, char* argv)
{

}
