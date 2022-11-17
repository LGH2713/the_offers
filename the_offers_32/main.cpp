/*
*	��Ŀ�������д��ϵ��´�ӡ������
*		  ���ϵ��´�ӡ����������ÿ���ڵ㣬ÿһ��Ľڵ㰴�մ����ҵ�˳���ӡ��
* 
*	tips������������ı����㷨��ʹ�ö���
*/
#include<deque>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
	if (!pTreeRoot)
		return;

	std::deque<BinaryTreeNode*> dequeTreeNode; // ʹ��˫�˶���

	dequeTreeNode.push_back(pTreeRoot); // ��ӵ�ǰ�ڵ�

	while (dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.front(); // ȡ�õ�ǰ�ڵ�
		dequeTreeNode.pop_front(); // ��ǰ�ڵ����

		printf("%d", pNode->m_nValue); // ��ӡ��ǰ�ڵ�

		if (pNode->m_pLeft)
			dequeTreeNode.push_back(pNode->m_pLeft); // �����ڵ�

		if (pNode->m_pRight)
			dequeTreeNode.push_back(pNode->m_pRight); // ����ҽڵ�
	}
}

int main(int argc, char* argv)
{

}