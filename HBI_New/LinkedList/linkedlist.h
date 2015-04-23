typedef int ElementType;

#ifndef _LIST_H

struct Node;//����һ���ṹ��Node
typedef struct Node *PtrToNode;//ָ��Node���͵�ָ�����
typedef PtrToNode List;//����һ��ָ��Node��ָ��List
typedef PtrToNode Position;

List MakeEmpty(List L);//�������
List InitList();//��ʼ������
List CreateListByHead();//ͷ�巨����������
List CreateListByTail();//β�巨����������
void PrintList(List L);//��ӡ������
int ListLength(List L);//��������ĳ��ȣ�����ͷ��㣩
List ReverseList(List L);//�������ת�á����ǵݹ�
int HasCircle(List L, Position &MeetPoint);//�ж������Ƿ���ڻ�
Position FindLoopPort(List L);//�ҵ�������ڵ�
int IsIntersec(List L1, List L2);//�ж����������Ƿ��ཻ
Position findIntersectNode(Position L1, Position L2);//�ҵ��������ཻ�ĵ�һ�������������޻�
int IsEmpty(List L);//�ж������Ƿ�Ϊ������
int IsLast(Position P, List L);//�жϽڵ�P�Ƿ���β�ڵ�
Position Find(ElementType X, List L);//�ж�����L���Ƿ����Ԫ��X
void Delete(ElementType X, List L);//ɾ�������е�ĳ��Ԫ��X
void DeleteNode(Position P);//ɾ��ĳ�����
Position FindPrevious(ElementType X, List L);//����Ԫ��X��ǰһ��Ԫ��
void Insert(ElementType X, List L, Position P);//��Ԫ��X���뵽P֮��
void InsertAt(ElementType X, List L, int index);//��ĳ��λ�ò���һ��Ԫ��,��0��λ�ü���Ϊͷ���
void DeleteList(List L);//ɾ������L
Position Header(List L);//��ȡ�����ͷ���
Position Fisrt(List L);//��ȡ����ĵ�һ��Ԫ��
Position TheKthNode(List L, ElementType k);//��ȡ����ĵ�k��Ԫ��
Position TheLastKthNode(List L, ElementType k);//��ȡ����ĵ�����k��Ԫ��
Position TheMiddleNode(List L);//��������м���
Position Advance(Position P);//��ȡP�ĺ�̽��
ElementType Retrieve(Position P);//��ȡ����ֵ

#endif