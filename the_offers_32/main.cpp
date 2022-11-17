/*
*	题目：不分行从上到下打印二叉树
*		  从上到下打印出二叉树的每个节点，每一层的节点按照从左到右的顺序打印。
* 
*	tips：考察二叉树的遍历算法。使用队列
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

	std::deque<BinaryTreeNode*> dequeTreeNode; // 使用双端队列

	dequeTreeNode.push_back(pTreeRoot); // 入队当前节点

	while (dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.front(); // 取得当前节点
		dequeTreeNode.pop_front(); // 当前节点出队

		printf("%d", pNode->m_nValue); // 打印当前节点

		if (pNode->m_pLeft)
			dequeTreeNode.push_back(pNode->m_pLeft); // 入队左节点

		if (pNode->m_pRight)
			dequeTreeNode.push_back(pNode->m_pRight); // 入队右节点
	}
}

int main(int argc, char* argv)
{

}