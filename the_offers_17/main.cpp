/*
*	��Ŀ����������n����˳���ӡ����1������nλʮ����������������3�����ӡ��1��2��3һֱ��������λ��999
* 
*	tips: ���ַ�����ģ�����ּӷ�
*/

#include<iostream>
#include<exception>
#include "solution_1.h"
#include "solution_2.h"
using namespace std;


int main(int argc, char* argv)
{
	Solution_1 *solution_1 = new Solution_1();
	solution_1->Print1ToMaxOfNDigits(2);
	Solution_2* solution_2 = new Solution_2();
	solution_2->Print1ToMaxOfDigits(2);
}