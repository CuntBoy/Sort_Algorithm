#include <iostream>
#include "heap.h"

int main()
{
	// test data 
	int data[6] = { 1,8,5,3,4,9};

	// �������� -- �ȼ������� Ȼ�������������� 
	auto max_heap = new MaxHeap(data, 6,100);

	// ��ʾ���� 
	max_heap->printData();

	return 0;

}