/*
*	题目：分行从上到下打印二叉树
*		  从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印一行。
* 
*	tips：用队列保存要打印的节点
* 
*	不管是广度优先遍历一幅有向图还是一颗二叉树，都要用队列。首先把起始节点(对树而言是根节点)放入队列。
*	接下来每次从队列的头部取出一个节点，遍历这个节点之后把他能到达的节点（对树而言是子节点）都依次放入队列。
*	重复这个遍历过程，直到队列中的节点被全部遍历为止
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

