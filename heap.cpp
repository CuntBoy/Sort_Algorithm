#include "heap.h"
#include <iostream>

MaxHeap::MaxHeap(const int* data, const int size,const int capacity)
{
	capacity_ = capacity;				// ���öѵĴ�С
	size_ = size;						// ��ʼ����ǰ���� Ϊ 0
	elements_ = new int[capacity_+1];      // ��ʼ������
	memset(elements_, 0, sizeof(int) * capacity_);
	memcpy(elements_ + 1, data, sizeof(int) * size_);   // �������� ��һ�����ݴ洢�����ڱ� ����Խ��һ���ڵ� 
	elements_[0] = 1000;

	//  ��������
	createMaxHeap();

}

// ����ʱ�临�Ӷ��½��� ���� 
void MaxHeap::createMaxHeap() const
{
	// �����һ��������ʼ����
	const int last_tree_index = size_ / 2;
	for(int index = last_tree_index; index >0; index--)
	{
		// ������ǰ�������ݹ�ϵ
		int parent = index;
		int child;
		int temp = elements_[index];
		for(;parent * 2 <= size_; parent = child)
		{
			child = 2 * parent;
			if(child != size_ && (elements_[child] < elements_[child+1])) // ���Һ��� ��������С���Һ���
			{
				child++;
			}

			// ��ǰ���ĸ��ڵ���ڵ�ǰ���ĺ��ӽڵ� 
			if(temp > elements_[child])
			{
				break;  //����ѭ��
			}
			else
			{
				// ��ʹ��ѡ����������ĺ��ӽڵ���Ϊ�µĸ��ڵ�  -- ���ױ����ǵĸ��ڵ㽫�ŵ�child�ڵ��λ�� 
				elements_[parent] = elements_[child];
			}
		}
		elements_[parent] = temp;
	}

}

// ����ѵ�������
void MaxHeap::printSize() const
{
	std::cout << capacity_ << std::endl;
}

// �����ǰ���ѵ����� 
void MaxHeap::printData() const
{
	for(int index = 1;index < size_+1 ;index++)
	{
		std::cout << *(elements_ + index) << " ";
		std::cout<< std::endl;
	}
}
