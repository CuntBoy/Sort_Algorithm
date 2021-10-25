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

	//��Ϊ�ڱ� ֻҪ�����Ԫ�ش����
	elements_[0] = elements_[1] + 10;

}

void MaxHeap::insertElement(int num)
{
	// ����ǰԪ�ز��뵽 ���һ��λ�� 
	// �ж��Ƿ��Ѿ�����
	if(isFull())
	{
		std::cout << "����ʧ��,û�ж���Ŀռ�!" << std::endl;
	}

	// �����޸��ڱ� 
	if(num > elements_[0])
	{
		elements_[0] = num+10;
	}
	// index ָ��������Ԫ��
	int index = ++size_;

	// �ӵ�ǰindexλ�ÿ�ʼ���ϼ����������������ݵ�˳�� 
	for(;elements_[index/2] < num;index = index / 2)
	{
		elements_[index] = elements_[index / 2];  // ����ǰԪ�ظ��ڵ��Ԫ������
	}
	elements_[index] = num;  // num ���շ��ڴ�λ��

}

int MaxHeap::deleteMax()
{
	int parent, child;
	int max_child, temp;
	if(isEmpty())
	{
		std::cout << "��Ϊ��" << std::endl;
		return -elements_[0];  // ���ش˽����ʾ ��ǰɾ��ʧ�� 
	}

	max_child = elements_[1];
	temp = elements_[size_--];   // ȡ�����һ��Ԫ��

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
			elements_[parent] = elements_[child];  // �ø����Ԫ���滻��Ԫ��
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
	}
	std::cout << std::endl;

}
