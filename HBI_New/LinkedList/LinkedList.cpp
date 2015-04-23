#include <stdio.h>
#include "fatal.h"
#include "linkedlist.h"
/*
**�����װ,������ͷ���ƽ��)
*/



struct Node{
	ElementType Element;
	Position Next;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////

//�������
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

//��ʼ������
List InitList()
{
	List L;
	L = (List)malloc(sizeof(struct  Node));//����ڵ�ռ�
	if (L == NULL)//�ж��Ƿ����㹻���ڴ�ռ�
		FatalError("Out of memory!");
	L->Next = NULL;//��Next����Ϊnull ��ʼΪֻ����ͷ��������
	return L;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//ͷ�巨����������
List CreateListByHead()
{
	List L;
	Position P;
	L = InitList();
	ElementType ch;
	while (scanf_s("%d", &ch) != EOF)
	{
		P = (Position)malloc(sizeof(struct  Node));//����ڵ�ռ�
		if (P == NULL)//�ж��Ƿ����㹻���ڴ�ռ�
			FatalError("Out of memory!");
		P->Element = ch;
		P->Next = L->Next;
		L->Next = P;
	}
	return L;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//β�巨����������
List CreateListByTail()
{
	List L;
	Position P, Temp;
	L = InitList();
	Temp = L;
	ElementType ch;
	while (scanf_s("%d", &ch) != EOF)
	{
		P = (Position)malloc(sizeof(struct  Node));//����ڵ�ռ�
		if (P == NULL)//�ж��Ƿ����㹻���ڴ�ռ�
			FatalError("Out of memory!");
		P->Element = ch;
		P->Next = NULL;
		Temp->Next = P;
		Temp = P;
	}
	return L;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//��ӡ������
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

//��������ĳ��ȣ�����ͷ��㣩
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

//�������ת�á����ǵݹ�
List ReverseList(List L)
{
	//�쳣�ж�
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

//�������ת�á����ݹ��㷨����δ���
List ReverseListByRecursion(List L)
{

	return L;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//�ж������Ƿ��ǿձ�
int IsEmpty(List L)
{
	if (L == NULL)
		FatalError("NULL parameter!");
	return L->Next == NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//�ж������Ƿ���ڻ�,����������ҳ��������
//˼�� ���趨����ָ�룬��ָ��head��㣬Ȼ��һ��ָ�루p1������Ϊ1��һ������(p2)Ϊ2����ƶ������p1��p2������˵�����ڻ�
//ΪʲôҪ���ò���һ��Ϊ1 һ��Ϊ2�أ�
//����һ������Ϊx��һ��Ϊy���軷����ڵ��ͷ������Ϊa���軷����ڽ��Ϊb�����������Ϊc���軷�ĳ���Ϊr���辭��t������
//��p1����xt,p2����yt����ô��������c,yt-xt=nr(n=1,2,3...),�����t=nr/(y-x);��(y-x)��Ҫ��������nr,���y-x=1;
//����Ϊ����ָ�빲����(x+y)t����Ҳ����(x+y)t=(x+y)*nr/(y-x),��ʹ�����Ĳ������٣���x+y��С��Ҳ����x=1;y=2;
//�Ƿ�һ���������أ�
//�ǣ���Ϊ�����������������ˣ�һ���ܵĿ죬һ���ܵ����������ܻ���������ʱ�򣬶������������Ǹ��ս����ﻹû�ܰ�Ȧ��ʱ�򣬾ͱ�׷����

//�ж������Ƿ���ڻ�
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

//������ڻ������ҵ�������ڽ�㣬��������֪p1��p2�����ֱ�Ϊ1��2����c������,��ʱp1 P2��ָ��c������������֪��t=ab+bc;2t=ab+bc+nr�����t=nr;
//��ʱ��p1ָ��head��㣬p2��ָ��������㣬����p2�Ĳ���Ҳ��Ϊ1����ô�´�p1��p2����һ���ڻ�����ڽڵ㣬Ҳ���ǽ��b,
//��Ϊab=t-bc=nr-bc=(n-1)r+r-bc=(n-1)r+cb��Ҳ����˵p1��ͷ����ߵ�����ڽ��b,����p2�ӵ�һ�������Ľ��c����(n-1)���������ټ�cb����b��պ���P1����
//����´�����һ���ڻ���ڽ��b

//�ҵ�������ڵ�
Position FindLoopPort(List L)
{

	if (L == NULL)
		FatalError("The list is NULL!");
	Position P1, P2;
	P1 = P2 = L;
	//���ж��Ƿ���ڻ�
	while (P2 != NULL && P2->Next != NULL)
	{
		P2 = P2->Next->Next;
		P1 = P1->Next;
		if (P1 == P2) break;
	}
	if (P1 != P2)//���������
		return NULL;
	P1 = L;//��P1����ָ��ͷ���
	//�ٴ�����ʱ��һ���ǻ�����ڽڵ�
	while (P1 != P2)
	{
		P1 = P1->Next;
		P2 = P2->Next;
	}
	return P1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//�ж����������Ƿ��ཻ
int IsIntersec(List L1, List L2)
{
	Position MeetPoint1, MeetPoint2 = NULL, P;
	if (L1 == NULL || L2 == NULL)
		FatalError("The list is NULL!");
	//�������������һ��������һ��������������ô����������һ�����ཻ
	if ((HasCircle(L1, MeetPoint1) && !HasCircle(L2, MeetPoint2)) || (!HasCircle(L1, MeetPoint1) && HasCircle(L2, MeetPoint2)))
		return 0;
	//�������������,������������ཻ��Ҳ����˵����������������һ��������㣨β�ڵ㣩,���ֻ��Ҫ�ж�βָ���Ƿ���ͬ����
	if (!HasCircle(L1, MeetPoint1) && !HasCircle(L2, MeetPoint2))
	{
		while (L1->Next != NULL)
			L1 = L1->Next;//������β�ڵ�
		while (L2->Next != NULL)
			L2 = L2->Next;
		return L1 == L2;
	}
	//�����������������1��������������2��������һ���ڻ���
	else{
		P = MeetPoint2->Next;
		while (P != MeetPoint2)
		{
			if (P == MeetPoint1)//�жϸû���ĳ������Ƿ�������1�е�������㣬�������˵���ཻ
				return 1;
			else
				P = P->Next;
		}
		return P == MeetPoint1;//����ѭ��δ�Ƚ�MeetPoint1��MeetPoint2,������ﲹ��
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

//���ö����˼�롣������������ĳ��� L1, L2���ֱ�������ָ�� p1, p2 ָ�����������ͷ��
///Ȼ�󽫽ϳ������ p1������Ϊ p1������ƶ�L2 - L1���ڵ㣬Ȼ����ͬʱ����ƶ�p1, p2��ֱ�� p1 = p2�������ĵ�����ཻ�ĵ�һ���ڵ㡣

//�ҵ��������ཻ�ĵ�һ�������������޻�
Position findIntersectNode(Position L1, Position L2)
{
	int len1 = ListLength(L1);          //��������
	int len2 = ListLength(L2);
	//������������
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

//���Ե�ǰ��Ԫ���Ƿ��Ǳ�����һ��Ԫ��
int IsLast(Position P, List L)
{
	if (L == NULL || P == NULL)
		FatalError("NULL parameter!");
	Position Temp;
	Temp = Find(P->Element, L);
	return Temp == NULL ? 0 : (Temp->Next == NULL);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//����ĳ��Ԫ���ڱ��е�λ��
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

//ɾ�������е�ĳ��Ԫ�أ�������ֶ�Σ����ɾ����һ�γ��ֵ�X�����û����ʲô������
void Delete(ElementType X, List L)
{
	if (L == NULL)
		FatalError("NULL parameter!");
	Position P, Temp;
	P = FindPrevious(X, L);
	//����ҵ�ǰ��
	if (P != NULL)
	{
		Temp = P->Next;
		P->Next = Temp->Next;
		free(Temp);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//ɾ��ĳ�����
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

//�ҵ��������ǰ��
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
	//˵���ҵ������һ��Ԫ��Ҳû���ҵ�X���򷵻�NULL
	if (P->Next == NULL)
		return NULL;
	//����ҵ����򷵻�P
	else
		return P;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////

//��P�����һ��Ԫ��X
void Insert(ElementType X, List L, Position P)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	Position Temp, InsertElement;
	//�ҵ�P�������λ��
	Temp = Find(P->Element, L);
	//û���ҵ�
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

//��ĳ��λ�ò���һ��Ԫ��,��0��λ�ü���Ϊͷ���
void InsertAt(ElementType X, List L, int index)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	if (index <= 0)//�������ֻ�ܴӴ��ڵ���1��λ�ò���
		FatalError("index is less than 0");
	int i;
	Position Pre, Temp;

	i = 0;
	Pre = L;
	//�ҵ�Ҫ����λ�õ�ǰ�����
	while (i < index - 1)
	{
		Pre = Pre->Next;
		i++;
	}

	Temp = (Position)malloc(sizeof(struct Node));//����ڵ�ռ�
	if (Temp == NULL)
		FatalError("Out of Memory!");
	Temp->Element = X;
	Temp->Next = Pre->Next;
	Pre->Next = Temp;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//ɾ���б�
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

//��ȡ�����ͷ���
Position Header(List L)
{
	return L;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//��ȡ����ĵ�һ��Ԫ��
Position Fisrt(List L)
{
	if (L == NULL)
		FatalError("The list is NULL!");
	return L->Next;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//��ȡ����ĵ�k��Ԫ��
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

//��ȡ����ĵ�����k��Ԫ��
//��ʼ������ָ��p1��p2��ָ��ͷ��㣨��0����㣩��֮��p2����ƶ�k����㣬��֮��p1 p2������ƣ�ֱ��p2ָ�����һ�����
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

//��������м���
//˼���������һ�����趨����ָ��p1��p2,p1�ƶ�һ����p2�ƶ���������p2�ƶ�������βʱ����p1�ƶ���������м���
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

//��ȡP�ĺ�̽��
Position Advance(Position P)
{

	if (P == NULL)
		FatalError("The node is NULL!");

	return P->Next;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//��ȡ����ֵ
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