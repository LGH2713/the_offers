/*
*	题目：请完成一个函数，输入一棵二叉树，该函数输出它的镜像。
* 
*	tips: 画图
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
	// 容错判断
	if (pNode == nullptr)
		return;
	if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
		return;

	// 节点交换
	BinaryTreeNode* pTemp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTemp;

	// 左节点存在则继续反转左节点
	if (pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);
	// 右节点存在则继续反转右节点
	if (pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);
}

int main(int argc, char* argv)
{

}