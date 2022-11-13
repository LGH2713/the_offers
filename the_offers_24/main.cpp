/*
*	��Ŀ������һ������������һ�������ͷ�ڵ㣬��ת��������������ͷ�ڵ㡣
* 
*	tips: ��Ҫʹ��3��ָ��
*/

struct ListNode
{
	int m_pValue;
	ListNode* m_pNext;
};

ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReversedHead = nullptr; // ��ת���ͷ�ڵ�
	ListNode* pNode = pHead;
	ListNode* pPrev = nullptr;

	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext; // ��ǰ�ڵ����һ���ڵ�

		if (pNext == nullptr)
			pReversedHead = pNode;		  // ��ǰ�ڵ�Ϊ��Ҫ��ת�Ľڵ�

		pNode->m_pNext = pPrev;			  // ��ǰ�ڵ�ָ����һ���ڵ�

		pPrev = pNode;					  // ǰһ���ڵ�����Ϊ��ǰ�ڵ�
		pNode = pNext;					  // ��ǰ�ڵ�����Ϊԭ������һ���ڵ�
	}

	return pReversedHead;
}

int main(int argc, char* argv)
{

}