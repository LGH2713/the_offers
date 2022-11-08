/*
	题目：根据前序遍历结果（{ 1,2,4,7,3,5,6,8 }）和中序遍历结果（{ 4,7,2,1,5,3,8,6 }）构建二叉树
*/


#include <iostream>
#include <exception>

static int preorderArr[] = { 1,2,4,7,3,5,6,8 };
static int inorderArr[] =  { 4,7,2,1,5,3,8,6 }; 


// 二叉树结构体
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

// 以先序为主要构建顺序
// 用中序来确定节点是左节点还是右节点

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	int rootValue = startPreorder[0]; // 获取当前子树根节点的值
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue; // 新建节点的值为当前子树的根节点的值
	root->m_pLeft = root->m_pRight = nullptr; // 左右节点置空

	// 判断当前序列是否只有根节点，只有根节点则返回
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input");
	}

	int* rootInorder = startInorder;
	// 在中序数组中找到当前子树的根节点
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;

	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input");

	// 计数用于判断是否有左节点
	int leftLength = rootInorder - startInorder; // 当前子树根节点距离前序序列开头的距离
	int* leftPreorderEnd = startPreorder + leftLength; // 根节点左边的第一个元素
	if (leftLength > 0)
	{
		// 构建左子树
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		// 构建右子树
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	// 返回新建节点
	return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

int main(int argc, char* argv)
{
	Construct(preorderArr, inorderArr, sizeof(preorderArr) / sizeof(preorderArr[0]));

	return 0;
}