/*
*	��Ŀ����ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ����һ�ö����������ľ���һ������ô���ǶԳƵ�
* 
*	˼·��ʹ�����ֱ�����ʽ�������жϽڵ��Ƿ����
*/

#include<iostream>
#include<exception>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
bool isSymmetrical(BinaryTreeNode* pRoot);
bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

bool isSymmetrical(BinaryTreeNode* pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	// �ڵ�һ�ͽڵ����������˵����ȣ�������
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;

	// �ڵ�һ�ͽڵ������һ��Ϊ�գ����ؼ�
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	// �ڵ�һ�ͽڵ��ֵ����ͬ�����ؼ�
	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;

	// ���������жϡ�
	return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}

int main(int argc, char* argv)
{

}