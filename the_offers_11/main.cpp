/*
*	题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，
*		  输出旋转数组的最小元素。例如，数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1
* 
*	方法：使用二分查找
*/


#include <iostream>
#include <exception>

int Min(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		throw new std::exception("Invalid input");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;

		// 如果下标为index1、index2和indexMid指向三个数字相同
		// 则只能按照顺序查找
		if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
			return MinInOrder(numbers, index1, index2);

		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}
	return numbers[indexMid];
}

int MinInOrder(int* numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1; i < index2; ++i)
	{
		if (result > numbers[i])
			result = numbers[i];
	}
	return result;
}

int main(int argc, char* argv)
{
	int spinArray[5] = { 4, 5, 1, 2, 3 };
	std::cout << Min(spinArray, sizeof(spinArray) / sizeof(spinArray[0])) << std::endl;
	return 0;
}