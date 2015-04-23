#ifndef DLIST_H
struct DNode;
typedef int ElementType;
typedef struct DNode * PtrToDNode;
typedef PtrToDNode Position;
typedef PtrToDNode DList;


Position MakeNode(ElementType i);//分配值为i的节点，并返回节点地址
void FreeNode(Position p); //释放p所指的节点
DList* InitList();//构造一个空的双向链表
void DestroyList(DList list);//摧毁一个双向链表
void ClearList(DList list);//将一个链表置为空表，释放原链表节点空间
Position GetHead(DList list);//返回头节点地址
Position GetTail(DList list);//返回尾节点地址
int GetSize(DList list);//返回链表大小
Position GetNext(Position p);//返回p的直接后继位置
Position GetPrevious(Position p);//返回p的直接前驱位置
Position InsFirst(DList list, Position pnode);//将pnode所指节点插入第一个节点之前
Position DelFirst(DList list);//将链表第一个节点删除并返回其地址
ElementType GetItem(Position p);//获得节点的数据项
void SetItem(Position p, ElementType i);//设置节点的数据项
Position Remove(DList *plist);//删除链表中的尾节点并返回其地址，改变链表的尾指针指向新的尾节点
Position InsBefore(DList *plist, Position p, Position s);//在链表中p位置之前插入新节点S
Position InsAfter(DList *plist, Position p, Position s);//在链表中p位置之后插入新节点s
Position LocatePos(DList *plist, int i);//返回在链表中第i个节点的位置
void ListTraverse(DList *plist, void(*visit)());//依次对链表中每个元素调用函数visit()
#endif