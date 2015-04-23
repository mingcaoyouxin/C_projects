#ifndef DLIST_H
struct DNode;
typedef int ElementType;
typedef struct DNode * PtrToDNode;
typedef PtrToDNode Position;
typedef PtrToDNode DList;


Position MakeNode(ElementType i);//����ֵΪi�Ľڵ㣬�����ؽڵ��ַ
void FreeNode(Position p); //�ͷ�p��ָ�Ľڵ�
DList* InitList();//����һ���յ�˫������
void DestroyList(DList list);//�ݻ�һ��˫������
void ClearList(DList list);//��һ��������Ϊ�ձ��ͷ�ԭ����ڵ�ռ�
Position GetHead(DList list);//����ͷ�ڵ��ַ
Position GetTail(DList list);//����β�ڵ��ַ
int GetSize(DList list);//���������С
Position GetNext(Position p);//����p��ֱ�Ӻ��λ��
Position GetPrevious(Position p);//����p��ֱ��ǰ��λ��
Position InsFirst(DList list, Position pnode);//��pnode��ָ�ڵ�����һ���ڵ�֮ǰ
Position DelFirst(DList list);//�������һ���ڵ�ɾ�����������ַ
ElementType GetItem(Position p);//��ýڵ��������
void SetItem(Position p, ElementType i);//���ýڵ��������
Position Remove(DList *plist);//ɾ�������е�β�ڵ㲢�������ַ���ı������βָ��ָ���µ�β�ڵ�
Position InsBefore(DList *plist, Position p, Position s);//��������pλ��֮ǰ�����½ڵ�S
Position InsAfter(DList *plist, Position p, Position s);//��������pλ��֮������½ڵ�s
Position LocatePos(DList *plist, int i);//�����������е�i���ڵ��λ��
void ListTraverse(DList *plist, void(*visit)());//���ζ�������ÿ��Ԫ�ص��ú���visit()
#endif