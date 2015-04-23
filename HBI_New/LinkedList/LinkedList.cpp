#include <stdio.h>
#include "fatal.h"
#include "linkedlist.h"
/*
**链表封装,包含表头（哑结点)
*/



struct Node{
	ElementType Element;
	Position Next;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////

//清空链表
List MakeEmpty(List L)
{
	if (L != NULL)
	{
		DeleteList(L);
	}
	L = (List)malloc(sizeof(struct  Node));
	if (L == NULL)
		FatalError("Out of memory!");
	L->Next = NULL;
	return L;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//初始化链表
List InitList()
{
	List L;
	L = (List)malloc(sizeof(struct  Node));//申请节点空间
	if (L == NULL)//判断是否有足够的内存空间
		FatalError("Out of memory!");
	L->Next = NULL;//将Next设置为null 初始为只包含头结点的链表
	return L;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//头插法建立单链表
List CreateListByHead()
{
	List L;
	Position P;
	L = InitList();
	ElementType ch;
	while (scanf_s("%d", &ch) != EOF)
	{
		P = (Position)malloc(sizeof(struct  Node));//申请节点空间
		if (P == NULL)//判断是否有足够的内存空间
			FatalError("Out of memory!");
		P->Element = ch;
		P->Next = L->Next;
		L->Next = P;
	}
	return L;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//尾插法建立单链表
List CreateListByTail()
{
	List L;
	Position P, Temp;
	L = InitList();
	Temp = L;
	ElementType ch;
	while (scanf_s("%d", &ch) != EOF)
	{
		P = (Position)malloc(sizeof(struct  Node));//申请节点空间
		if (P == NULL)//判断是否有足够的内存空间
			FatalError("Out of memory!");
		P->Element = ch;
		P->Next = NULL;
		Temp->Next = P;
		Temp = P;
	}
	return L;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//打印单链表
void PrintList(List L)
{
	if (L == NULL)
		FatalError("The List is NULL");
	L = L->Next;
	while (L != NULL)
	{
		printf("%d ", L->Element);
		L = L->Next;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//计算链表的长度（包括头结点）
int ListLength(List L)
{
	if (L == NULL)
		FatalError("The List is NULL");
	int len;

	len = 0;
	while (L != NULL)
	{
		L = L->Next;
		len++;
	}
	return len;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//单链表的转置——非递归
List ReverseList(List L)
{
	//异常判断
	if (L == NULL || L->Next == NULL)
	{
		FatalError("The List is Null");
	}
	Position P, Next, Pre;
	P = L->Next;
	Pre = L;
	while (P != NULL)
	{
		Next = P->Next;
		P->Next = Pre;
		Pre = P;
		P = Next;
	}
	P = L->Next;
	P->Next = NULL;
	L->Next = Pre;
	return L;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//单链表的转置——递归算法——未完成
List ReverseListByRecursion(List L)
{

	return L;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//判断链表是否是空表
int IsEmpty(List L)
{
	if (L == NULL)
		FatalError("NULL parameter!");
	return L->Next == NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//判断链表是否存在环,如果包含，找出环的入口
//思想 ：设定两个指针，均指向head结点，然后一个指针（p1）步长为1，一个步长(p2)为2向后移动，如果p1与p2相遇，说明存在环
//为什么要设置步长一个为1 一个为2呢？
//假设一个步长为x，一个为y，设环的入口点距头结点距离为a，设环的入口结点为b，设相遇结点为c，设环的长度为r，设经过t步相遇
//则p1经过xt,p2经过yt，那么在相遇点c,yt-xt=nr(n=1,2,3...),可求得t=nr/(y-x);则(y-x)需要整除所有nr,因此y-x=1;
//又因为两个指针共经过(x+y)t步，也就是(x+y)t=(x+y)*nr/(y-x),若使经过的步数最少，则x+y最小，也就是x=1;y=2;
//是否一定能相遇呢？
//是，因为假设两个都到环里了，一个跑的快，一个跑的慢，两个总会有相遇的时候，而且是在慢的那个刚进环里还没跑半圈的时候，就被追上了

//判断链表是否存在环
int HasCircle(List L, Position &MeetPoint)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	Position P1, P2;
	P1 = P2 = L;
	while (P2 != NULL && P2->Next != NULL)
	{
		P2 = P2->Next->Next;
		P1 = P1->Next;
		if (P1 == P2) {
			MeetPoint = P1;
			break;
		}
	}
	return !(P2 == NULL || P2->Next == NULL);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////

//如果存在环，则找到环的入口结点，由上面已知p1和p2步长分别为1和2，在c点相遇,此时p1 P2均指向c，我们由上面知道t=ab+bc;2t=ab+bc+nr；因此t=nr;
//此时令p1指向head结点，p2仍指向相遇结点，但是p2的步长也变为1，那么下次p1与p2相遇一定在环的入口节点，也就是结点b,
//因为ab=t-bc=nr-bc=(n-1)r+r-bc=(n-1)r+cb，也就是说p1从头结点走到环入口结点b,等于p2从第一次相遇的结点c经过(n-1)个环长，再加cb到达b点刚好与P1相遇
//因此下次相遇一定在环入口结点b

//找到环的入口点
Position FindLoopPort(List L)
{

	if (L == NULL)
		FatalError("The list is NULL!");
	Position P1, P2;
	P1 = P2 = L;
	//先判断是否存在环
	while (P2 != NULL && P2->Next != NULL)
	{
		P2 = P2->Next->Next;
		P1 = P1->Next;
		if (P1 == P2) break;
	}
	if (P1 != P2)//如果不存在
		return NULL;
	P1 = L;//将P1重新指向头结点
	//再次相遇时，一定是环的入口节点
	while (P1 != P2)
	{
		P1 = P1->Next;
		P2 = P2->Next;
	}
	return P1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//判断两个链表是否相交
int IsIntersec(List L1, List L2)
{
	Position MeetPoint1, MeetPoint2 = NULL, P;
	if (L1 == NULL || L2 == NULL)
		FatalError("The list is NULL!");
	//如果两个链表中一个包含环一个不包含环，那么这两个链表一定不相交
	if ((HasCircle(L1, MeetPoint1) && !HasCircle(L2, MeetPoint2)) || (!HasCircle(L1, MeetPoint1) && HasCircle(L2, MeetPoint2)))
		return 0;
	//如果都不包含环,如果两个链表相交，也就是说，两个链表至少有一个公共结点（尾节点）,因此只需要判断尾指针是否相同即可
	if (!HasCircle(L1, MeetPoint1) && !HasCircle(L2, MeetPoint2))
	{
		while (L1->Next != NULL)
			L1 = L1->Next;//遍历到尾节点
		while (L2->Next != NULL)
			L2 = L2->Next;
		return L1 == L2;
	}
	//如果包括环，则链表1的相遇点与链表2的相遇点一定在环中
	else{
		P = MeetPoint2->Next;
		while (P != MeetPoint2)
		{
			if (P == MeetPoint1)//判断该环中某个结点是否是链表1中的相遇结点，如果是则说明相交
				return 1;
			else
				P = P->Next;
		}
		return P == MeetPoint1;//上述循环未比较MeetPoint1与MeetPoint2,因此这里补充
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//采用对齐的思想。计算两个链表的长度 L1, L2，分别用两个指针 p1, p2 指向两个链表的头，
///然后将较长链表的 p1（假设为 p1）向后移动L2 - L1个节点，然后再同时向后移动p1, p2，直到 p1 = p2。相遇的点就是相交的第一个节点。

//找到两链表相交的第一个公共结点假设无环
Position findIntersectNode(Position L1, Position L2)
{
	int len1 = ListLength(L1);          //求链表长度
	int len2 = ListLength(L2);
	//对齐两个链表
	if (len1 > len2)
	{
		for (int i = 0; i<len1 - len2; i++)
			L1 = L1->Next;
	}
	else
	{
		for (int i = 0; i<len2 - len1; i++)
			L2 = L2->Next;
	}

	while (L1 != NULL)
	{
		if (L1 == L2)
			return L1;
		L1 = L1->Next;
		L2 = L2->Next;
	}
	return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//测试当前的元素是否是表的最后一个元素
int IsLast(Position P, List L)
{
	if (L == NULL || P == NULL)
		FatalError("NULL parameter!");
	Position Temp;
	Temp = Find(P->Element, L);
	return Temp == NULL ? 0 : (Temp->Next == NULL);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//查找某个元素在表中的位置
Position Find(ElementType X, List L)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
	{
		P = P->Next;
	}
	return P;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//删除链表中的某个元素，如果出现多次，则仅删除第一次出现的X，如果没有则什么都不做
void Delete(ElementType X, List L)
{
	if (L == NULL)
		FatalError("NULL parameter!");
	Position P, Temp;
	P = FindPrevious(X, L);
	//如果找到前驱
	if (P != NULL)
	{
		Temp = P->Next;
		P->Next = Temp->Next;
		free(Temp);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//删除某个结点
void DeleteNode(Position P)
{
	if (P == NULL)
		FatalError("The node is null");
	if (P->Next == NULL)
		FatalError("Not useful for the last node");
	Position Next;
	Next = P->Next;
	P->Element = Next->Element;
	P->Next = Next->Next;
	free(Next);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//找到链表结点的前驱
Position FindPrevious(ElementType X, List L)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	}
	//说明找到了最后一个元素也没有找到X，则返回NULL
	if (P->Next == NULL)
		return NULL;
	//如果找到，则返回P
	else
		return P;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////

//在P后插入一个元素X
void Insert(ElementType X, List L, Position P)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	Position Temp, InsertElement;
	//找到P结点所在位置
	Temp = Find(P->Element, L);
	//没有找到
	if (Temp == NULL)
		FatalError("Node Not Found!");
	InsertElement = (Position)malloc(sizeof(struct  Node));
	if (InsertElement == NULL)
	{
		FatalError("Out of Memory!");
	}
	InsertElement->Element = X;
	InsertElement->Next = Temp->Next;
	Temp->Next = InsertElement;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//在某个位置插入一个元素,第0个位置假设为头结点
void InsertAt(ElementType X, List L, int index)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	if (index <= 0)//这里假设只能从大于等于1的位置插入
		FatalError("index is less than 0");
	int i;
	Position Pre, Temp;

	i = 0;
	Pre = L;
	//找到要插入位置的前驱结点
	while (i < index - 1)
	{
		Pre = Pre->Next;
		i++;
	}

	Temp = (Position)malloc(sizeof(struct Node));//申请节点空间
	if (Temp == NULL)
		FatalError("Out of Memory!");
	Temp->Element = X;
	Temp->Next = Pre->Next;
	Pre->Next = Temp;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//删除列表
void DeleteList(List L)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	Position P, Temp;
	P = L->Next;
	L->Next = NULL;
	while (P != NULL)
	{
		Temp = P->Next;
		free(P);
		P = Temp;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//获取链表的头结点
Position Header(List L)
{
	return L;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//获取链表的第一个元素
Position Fisrt(List L)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	return L->Next;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//获取链表的第k个元素
Position TheKthNode(List L, ElementType k)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	if (k < 0)
		FatalError("The index of the list should be bigger than 0!");
	int i;
	for (i = 0; i < k; i++)
	{
		if (L == NULL)
			break;
		L = L->Next;
	}
	if (i == k)
		return L;
	else
		return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//获取链表的倒数第k个元素
//初始设两个指针p1，p2都指向头结点（第0个结点），之后p2向后移动k个结点，再之后p1 p2均向后移，直到p2指向最后一个结点
Position TheLastKthNode(List L, ElementType k)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	if (k < 0)
		FatalError("The index of the list should be bigger than 0!");
	int i;
	Position P1, P2;
	P1 = P2 = L;

	for (i = 0; i < k; i++)
	{
		P2 = P2->Next;
	}
	if (i < k)
		FatalError("The length of the list is smaller than k");
	while (P2->Next != NULL)
	{
		P1 = P1->Next;
		P2 = P2->Next;
	}
	return P1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//求链表的中间结点
//思想与上面的一样，设定两个指针p1、p2,p1移动一步，p2移动两步，当p2移动到链表尾时，则p1移动到链表的中间结点
Position TheMiddleNode(List L)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	Position P1, P2;
	P2 = P1 = L;

	while (P2 != NULL && P2->Next != NULL)
	{
		P1 = P1->Next;
		P2 = P2->Next->Next;
	}
	return P1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//获取P的后继结点
Position Advance(Position P)
{

	if (P == NULL)
		FatalError("The node is NULL!");

	return P->Next;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//获取结点的值
ElementType Retrieve(Position P)
{
	if (P == NULL)
		FatalError("NULL parameter!");
	return P->Element;
}


int main(void)
{
	List L = CreateListByTail();
	PrintList(L);
	printf("\n");
	L = ReverseList(NULL);
	PrintList(L);
	system("pause");
	return 0;
}