#ifndef HEAP_H_
#define HEAP_h_

// 大顶堆的类 -- 基于大顶堆的实现
#include <memory>

class MaxHeap
{
public:
	// 数据 当前数据的个数 堆的大小(存储的元素的个数的上限)
	MaxHeap(const int * data,int size,int capacity);

	void createMaxHeap();

	// test function
	void printSize() const;
	void printData() const;

protected:
	int* elements_;   // 存储元素的数组
	int size_;     // 当前元素的个数
	int capacity_; // 堆的最大容量


};




#endif // !HEAP_H_
