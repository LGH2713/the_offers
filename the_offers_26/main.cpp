/*
*	��Ŀ���������Ŷ�����A��B���ж�B�ǲ���A���ӽṹ��
*/

struct BinaryTreeNode
{
	double m_dbValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

// ˫���ȸ���������ж�
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

	// �����������ж�
	return DoseTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft)
		&& DoseTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;

	// �Ӹ��ڵ��ж�
	if (pRoot1 != nullptr && pRoot2 != nullptr)
		result = DoseTree1HaveTree2(pRoot1, pRoot2);
	// ���ڵ��жϲ������ߵ��ӽڵ��ж�
	if (!result)
		result = HasSubtree(pRoot1->m_pLeft, pRoot2);
	// ��ڵ��жϲ������ߵ��ҽڵ��ж�
	if (!result)
		result = HasSubtree(pRoot1->m_pRight, pRoot2);

	return result;
}

int main(int argc, char* argv)
{

}