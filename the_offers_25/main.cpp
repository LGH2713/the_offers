/*
*	��Ŀ������������������������ϲ�����������ʹ�������еĽڵ���Ȼ�ǵ�������
* 
*	����
*		����1 1->3->5->7
*		����2 2->4->6->8
*		�ϲ����� 1->2->3->4->5->6->7->8->9
* 
*	���׳��ֵ����⣺������ѡ���׳�Բ�
* 
*/

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	// �ݴ���
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
