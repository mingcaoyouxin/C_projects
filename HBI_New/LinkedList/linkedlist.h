typedef int ElementType;

#ifndef _LIST_H

struct Node;//声明一个结构体Node
typedef struct Node *PtrToNode;//指定Node类型的指针别名
typedef PtrToNode List;//声明一个指向Node的指针List
typedef PtrToNode Position;

List MakeEmpty(List L);//清空链表
List InitList();//初始化链表
List CreateListByHead();//头插法建立单链表
List CreateListByTail();//尾插法建立单链表
void PrintList(List L);//打印单链表
int ListLength(List L);//计算链表的长度（包括头结点）
List ReverseList(List L);//单链表的转置——非递归
int HasCircle(List L, Position &MeetPoint);//判断链表是否存在环
Position FindLoopPort(List L);//找到环的入口点
int IsIntersec(List L1, List L2);//判断两个链表是否相交
Position findIntersectNode(Position L1, Position L2);//找到两链表相交的第一个公共结点假设无环
int IsEmpty(List L);//判断链表是否为空链表
int IsLast(Position P, List L);//判断节点P是否是尾节点
Position Find(ElementType X, List L);//判断链表L中是否包含元素X
void Delete(ElementType X, List L);//删除链表中的某个元素X
void DeleteNode(Position P);//删除某个结点
Position FindPrevious(ElementType X, List L);//查找元素X的前一个元素
void Insert(ElementType X, List L, Position P);//将元素X插入到P之后
void InsertAt(ElementType X, List L, int index);//在某个位置插入一个元素,第0个位置假设为头结点
void DeleteList(List L);//删除链表L
Position Header(List L);//获取链表的头结点
Position Fisrt(List L);//获取链表的第一个元素
Position TheKthNode(List L, ElementType k);//获取链表的第k个元素
Position TheLastKthNode(List L, ElementType k);//获取链表的倒数第k个元素
Position TheMiddleNode(List L);//求链表的中间结点
Position Advance(Position P);//获取P的后继结点
ElementType Retrieve(Position P);//获取结点的值

#endif