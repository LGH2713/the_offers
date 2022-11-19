/*
*	��Ŀ�����д��ϵ��´�ӡ������
*		  ���ϵ��°����ӡ��������ͬһ��Ľڵ㰴�����ҵ�˳���ӡ��ÿһ���ӡһ�С�
* 
*	tips���ö��б���Ҫ��ӡ�Ľڵ�
* 
*	�����ǹ�����ȱ���һ������ͼ����һ�Ŷ���������Ҫ�ö��С����Ȱ���ʼ�ڵ�(���������Ǹ��ڵ�)������С�
*	������ÿ�δӶ��е�ͷ��ȡ��һ���ڵ㣬��������ڵ�֮������ܵ���Ľڵ㣨�����������ӽڵ㣩�����η�����С�
*	�ظ�����������̣�ֱ�������еĽڵ㱻ȫ������Ϊֹ
*/
#include<queue>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void Print(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	std::queue<BinaryTreeNode*> nodes;
	nodes.push(pRoot);
	int nextLevel = 0;
	int toBePrinted = 1;
	while (!nodes.empty())
	{
		BinaryTreeNode* pNode = nodes.front();
		printf("%d ", pNode->m_nValue);

		if (pNode->m_pLeft != nullptr)
		{
			nodes.push(pNode->m_pLeft);
			++nextLevel;
		}
		if (pNode->m_pRight != nullptr)
		{
			nodes.push(pNode->m_pRight);
			++nextLevel;
		}

		nodes.pop();
		--toBePrinted;
		if (toBePrinted == 0)
		{
			printf("\n");
			toBePrinted = nextLevel;
			nextLevel = 0;
		}
	}
}

int main(int argc, char* argv)
{
	return 0;
}

