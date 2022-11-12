/*
*	题目：输入数字n，按顺序打印出从1到最大的n位十进制数。比如输入3，则打印出1，2，3一直到最大的三位数999
* 
*	tips: 在字符串上模拟数字加法
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