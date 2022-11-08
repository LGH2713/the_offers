/*
	题目：给定一颗二叉树和其中的一个节点，如何找出中序遍历序列的下一个节点？书中的节点除了有两个分别指向
	左右节点的指针，还有一个指向父节点的指针

	简化：找到依照中序序列的下一个节点
*/

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	// 初始判断
	if (pNode == nullptr) 
		return nullptr;

	BinaryTreeNode* pNext = nullptr; // 设置返回值，置空

	// 情况一：该节点有右节点，则该节点的右节点最左的左节点就是他在中序中的下一个节点
	if (pNode->m_pRight != nullptr)
	{
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr)
			pRight = pRight->m_pLeft;

		pNext = pRight;
	}
	// 情况二：该节点没有右子树，同时该节点是其父节点的右节点
	else if (pNode->m_pParent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;

		// 从当前节点开始向上搜寻，直到找到一个祖先节点要么没有父节点（根据节点），要么找到一个祖先节点有右节点
		while (pParent != nullptr && pCurrent == pParent->m_pRight)
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		pNext = pParent;
	}

	return pNext;
}

int main(int argc, char* argv)
{
	return 0;
}