#include <exception>
#include <cstdlib>
#include <iostream>
using namespace std;

// 生成索引随机数
int RandomInRange(int start, int end)
{
	return (rand() % (end - start + 1)) + start;
}


// 交换值函数
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


// 划分函数
int Partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
		throw exception("Invalid Parameters");

	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				Swap(&data[index], &data[small]);
		}
	}

	++small;
	Swap(&data[small], &data[end]);

	return small;
}


// 快排主体
void QuickSort(int data[], int length, int start, int end)
{
	if (start == end)
		return;

	int index = Partition(data, length, start, end);
	if (index > start)
		QuickSort(data, length, start, index - 1);
	if (index < end)
		QuickSort(data, length, index + 1, end);
}

int main(int argc, char* argv)
{
	int data[10] = { 1, 5, 2, 3, 7, 4, 9, 8, 6, 10 };
	int length = sizeof(data) / sizeof(data[0]);
	QuickSort(data, length, 0, length - 1);

	for (int i : data)
		cout << i << " ";

	return 0;
}