/*
*	��Ŀ������һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣
*		  ���磬һ��������6���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6.�������ĵ����������ڵ���ֵΪ4�Ľڵ㡣
* 
*	˼·��ʹ��˫ָ�뷨����һ��ָ������k-1�����ڶ���ָ��ָ��ͷ�ڵ㣬Ȼ������ָ����һ���ƶ�������һ��ָ��ָ������ĩβʱ����
*		  �����ڵ��ָ���˵�����k���ڵ�
* 
*	tips�������ֱ߽�������ܵ��³������
*			��1�������pListNodeλ��ָ�롣������ʿ�ָ��ָ����ڴ棬���������
*			��2���������pListNodeΪͷ�ڵ������Ľڵ�����С��k��������ѭ���л�����������k-1������Ȼ��Ϊ���ʿ�ָ��ָ�����
*				 �浼�³������
*			��3������Ĳ���kΪ0������k-1���޷���������k-1Ϊ4294967295��ѭ������Զ��Ԥ��
*/

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == nullptr || k == 0)
		return nullptr;

	ListNode* pAhead = pListHead;
	ListNode* pBehind = nullptr;

	for (unsigned int i = 0; i < k - 1; ++i)
	{
		if (pAhead->m_pNext != nullptr)
			pAhead = pAhead->m_pNext;
		else
			return nullptr;
	}

	pBehind = pListHead;
	while (pAhead->m_pNext != nullptr)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	return pBehind;
}

#include<iostream>
#include<exception>
using namespace std;



int main(int argc, char* argv)
{

}