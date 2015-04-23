#include "binheap.h"
#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>

#define MinPQSize (10)
#define MinData (-32767)

struct  HeapStruct
{
	int Capacity;//容量
	int Size;//大小
	ElementType *Elements;//堆中元素
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//初始化一个优先队列
//参数二叉堆的节点数
PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	if (MaxElements < MinPQSize)//如果堆中元素数，小于最小的优先队列大小，此处定义堆中至少有10个元素
		Error("Priority queue size is too small");
	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));//申请一个二叉堆
	if (H == NULL)
		FatalError("Out of space!!!");
	H->Elements = (ElementType *)malloc(sizeof(ElementType)*(MaxElements + 1));//申请MaxElements+1的内存，因为数组的第0个元素将放置一个很小的值
	if (H->Elements == NULL)
		FatalError("Out of space!!!");
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;

	return H;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//插入一个元素
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

	//当H->Elements[i/2]<=X，跳出for循环，此时便可以将元素插在i的位置，因为i的父亲比i小，满足堆序性
	//当i=1时，i/2=0,H->Elements[0]是MinData，因此必定小于X，肯定跳出循环，因此位置0放置一个很小的数的原因就在这里。
	for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
		H->Elements[i] = H->Elements[i / 2];//这里不需要先将X插入到堆中，再与父亲比较然后再进行交换，只需要一次赋值就可以了
	H->Elements[i] = X;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//删除最小元
ElementType DeleteMin(PriorityQueue H)
{
	if (H == NULL)
		FatalError("The priority queue is null!!!");

}