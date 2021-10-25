#include "heap.h"
#include <iostream>

MaxHeap::MaxHeap(const int* data, int size, int capacity)
{
	capacity_ = capacity;				// 设置堆的大小
	size_ = size;						// 初始化当前个数 为 0
	elements_ = new int[capacity_];      // 初始化数组
	memset(elements_, 0, sizeof(int) * capacity_);
	memcpy(elements_ + 1, data, sizeof(int) * size_);   // 拷贝数据 第一个数据存储的是哨兵 所以越过一个节点 
	elements_[0] = 1000;


	// show data
	printData();

	//  建立最大堆
	createMaxHeap();

}

void MaxHeap::createMaxHeap()
{
	// 处理最后一颗树
	int last_tree_index = size_ / 2;
	for(int index = last_tree_index; index >0; index--)
	{
		// 调整当前树的数据关系
		int parent = index;
		int child;
		int temp = elements_[index];
		for(;parent * 2 <= size_; parent = child)
		{
			child = 2 * parent;
			if(child != size_ && (elements_[child] < elements_[child+1])) // 有右孩子 并且左孩子小于右孩子
			{
				child++;
			}

			// 当前树的根节点大于当前最大的孩子节点 
			if(temp > elements_[child])
			{
				break;  //结束循环
			}
			else
			{
				// 将使用选择出来的最大的孩子节点作为新的根节点  -- 当亲被覆盖的父节点将放到child节点的位置 
				elements_[parent] = elements_[child];
			}
		}
		elements_[parent] = temp;
	}

}

void MaxHeap::printSize() const
{
	std::cout << capacity_ << std::endl;
}

void MaxHeap::printData() const
{
	for(int index = 1;index < size_+1 ;index++)
	{
		std::cout << *(elements_+index) << std::endl;
	}
}
