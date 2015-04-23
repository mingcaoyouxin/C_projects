#include "binheap.h"
#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>

#define MinPQSize (10)
#define MinData (-32767)

struct  HeapStruct
{
	int Capacity;//����
	int Size;//��С
	ElementType *Elements;//����Ԫ��
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//��ʼ��һ�����ȶ���
//��������ѵĽڵ���
PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	if (MaxElements < MinPQSize)//�������Ԫ������С����С�����ȶ��д�С���˴��������������10��Ԫ��
		Error("Priority queue size is too small");
	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));//����һ�������
	if (H == NULL)
		FatalError("Out of space!!!");
	H->Elements = (ElementType *)malloc(sizeof(ElementType)*(MaxElements + 1));//����MaxElements+1���ڴ棬��Ϊ����ĵ�0��Ԫ�ؽ�����һ����С��ֵ
	if (H->Elements == NULL)
		FatalError("Out of space!!!");
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;

	return H;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//����һ��Ԫ��
void Insert(ElementType X, PriorityQueue H)
{
	int i;
	if (H == NULL)
		FatalError("The priority queue is null!!!");
	if (IsFull(H))
	{
		FatalError("The priority queue is full!!!");
		return;
	}

	//��H->Elements[i/2]<=X������forѭ������ʱ����Խ�Ԫ�ز���i��λ�ã���Ϊi�ĸ��ױ�iС�����������
	//��i=1ʱ��i/2=0,H->Elements[0]��MinData����˱ض�С��X���϶�����ѭ�������λ��0����һ����С������ԭ��������
	for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
		H->Elements[i] = H->Elements[i / 2];//���ﲻ��Ҫ�Ƚ�X���뵽���У����븸�ױȽ�Ȼ���ٽ��н�����ֻ��Ҫһ�θ�ֵ�Ϳ�����
	H->Elements[i] = X;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ɾ����СԪ
ElementType DeleteMin(PriorityQueue H)
{
	if (H == NULL)
		FatalError("The priority queue is null!!!");

}