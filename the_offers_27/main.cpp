/*
*	��Ŀ�������һ������������һ�ö��������ú���������ľ���
* 
*	tips: ��ͼ
*/

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

#include<iostream>
#include<exception>
using namespace std;

void MirrorRecursively(BinaryTreeNode* pNode)
{
	// �ݴ��ж�
	if (pNode == nullptr)
		return;
	if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
		return;

	// �ڵ㽻��
	BinaryTreeNode* pTemp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTemp;

	// ��ڵ�����������ת��ڵ�
	if (pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);
	// �ҽڵ�����������ת�ҽڵ�
	if (pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);
}

int main(int argc, char* argv)
{

}