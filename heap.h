#ifndef HEAP_H_
#define HEAP_h_

// �󶥶ѵ��� -- ���ڴ󶥶ѵ�ʵ��
#include <memory>

class MaxHeap
{
public:
	// ���� ��ǰ���ݵĸ��� �ѵĴ�С(�洢��Ԫ�صĸ���������)
	MaxHeap(const int * data,int size,int capacity);

	void createMaxHeap();

	// test function
	void printSize() const;
	void printData() const;

protected:
	int* elements_;   // �洢Ԫ�ص�����
	int size_;     // ��ǰԪ�صĸ���
	int capacity_; // �ѵ��������


};




#endif // !HEAP_H_
