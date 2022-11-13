/*
*	题目：输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
*		  例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6.这个链表的倒数第三个节点是值为4的节点。
* 
*	思路：使用双指针法，第一个指针先走k-1步，第二个指针指向头节点，然后两个指针再一起移动，当第一个指针指向链表末尾时，第
*		  二个节点就指向了倒数第k个节点
* 
*	tips：有三种边界情况可能导致程序崩溃
*			（1）输入的pListNode位空指针。代码访问空指针指向的内存，程序崩溃。
*			（2）输入的以pListNode为头节点的链表的节点总数小于k。由于在循环中会在链表上走k-1步，仍然因为访问空指针指向的内
*				 存导致程序崩溃
*			（3）输入的参数k为0，由于k-1是无符号整数，k-1为4294967295，循环次数远超预计
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