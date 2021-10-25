#include <iostream>
#include "heap.h"

int main()
{
	// test data 
	int data[6] = { 1,8,5,3,4,9};

	// 创建最大堆 -- 先加载数据 然后将数据重新排序 
	auto max_heap = new MaxHeap(data, 6,100);
	// 显示数据 
	max_heap->printData();

	// insert 
	max_heap->insertElement(20);
	// 显示数据 
	max_heap->printData();

	//delete 
	max_heap->deleteMax();
	// 显示数据 
	max_heap->printData();


	return 0;

}