#include "heap.h"
#include <iostream>

MaxHeap::MaxHeap(const int* data, const int size,const int capacity)
{
	capacity_ = capacity;				// 设置堆的大小
	size_ = size;						// 初始化当前个数 为 0
	elements_ = new int[capacity_+1];      // 初始化数组
	memset(elements_, 0, sizeof(int) * capacity_);
	memcpy(elements_ + 1, data, sizeof(int) * size_);   // 拷贝数据 第一个数据存储的是哨兵 所以越过一个节点 
	elements_[0] = 1000;

	//  建立最大堆
	createMaxHeap();

}

// 线性时间复杂度下建立 最大堆 
void MaxHeap::createMaxHeap() const
{
	// 从最后一颗子树开始处理
	const int last_tree_index = size_ / 2;
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

	//作为哨兵 只要比最大元素大就行
	elements_[0] = elements_[1] + 10;

}

void MaxHeap::insertElement(int num)
{
	// 将当前元素插入到 最后一个位置 
	// 判断是否已经满了
	if(isFull())
	{
		std::cout << "插入失败,没有额外的空间!" << std::endl;
	}

	// 重新修改哨兵 
	if(num > elements_[0])
	{
		elements_[0] = num+10;
	}
	// index 指向插入的新元素
	int index = ++size_;

	// 从当前index位置开始向上检索，更新树中数据的顺序 
	for(;elements_[index/2] < num;index = index / 2)
	{
		elements_[index] = elements_[index / 2];  // 将当前元素父节点的元素下移
	}
	elements_[index] = num;  // num 最终放在此位置

}

int MaxHeap::deleteMax()
{
	int parent, child;
	int max_child, temp;
	if(isEmpty())
	{
		std::cout << "堆为空" << std::endl;
		return -elements_[0];  // 返回此结果表示 当前删除失败 
	}

	max_child = elements_[1];
	temp = elements_[size_--];   // 取出最后一个元素

	for(parent = 1; parent * 2 < size_;parent = child)
	{
		child = 2 * parent;
		if((child != size_) && (elements_[child] < elements_ [child + 1]))
		{
			child++;
		}
		if(temp > elements_[child])
		{
			break;
		}
		else
		{
			elements_[parent] = elements_[child];  // 用更大的元素替换根元素
		}

	}
	elements_[parent] = temp;

	return max_child;
}

bool MaxHeap::isFull() const
{
	return size_ == capacity_;
}

bool MaxHeap::isEmpty() const
{
	return !size_;
}

// 输出堆的最大个数
void MaxHeap::printSize() const
{
	std::cout << capacity_ << std::endl;
}

// 输出当前最大堆的数据 
void MaxHeap::printData() const
{
	for(int index = 1;index < size_+1 ;index++)
	{
		std::cout << *(elements_ + index) << " ";
	}
	std::cout << std::endl;

}
