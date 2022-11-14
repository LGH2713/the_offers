/*
*	题目：输入两颗二叉树A和B，判断B是不是A的子结构。
*/

struct BinaryTreeNode
{
	double m_dbValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

// 双精度浮点数相等判断
bool Equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

bool DoseTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot2 == nullptr)
		return true;
	if (pRoot1 == nullptr)
		return false;

	if (!Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
		return false;

	// 向左右子树判断
	return DoseTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft)
		&& DoseTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;

	// 从根节点判断
	if (pRoot1 != nullptr && pRoot2 != nullptr)
		result = DoseTree1HaveTree2(pRoot1, pRoot2);
	// 根节点判断不出则走到子节点判断
	if (!result)
		result = HasSubtree(pRoot1->m_pLeft, pRoot2);
	// 左节点判断不出则走到右节点判断
	if (!result)
		result = HasSubtree(pRoot1->m_pRight, pRoot2);

	return result;
}

int main(int argc, char* argv)
{

}