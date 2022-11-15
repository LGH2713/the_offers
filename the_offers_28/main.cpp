/*
*	题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和他的镜像一样，那么它是对称的
* 
*	思路：使用两种遍历方式（镜像）判断节点是否相等
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
	// 节点一和节点二都不存在说明相等，返回真
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;

	// 节点一和节点二任意一个为空，返回假
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	// 节点一和节点二值不相同，返回假
	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;

	// 继续向下判断。
	return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}

int main(int argc, char* argv)
{

}