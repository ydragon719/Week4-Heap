#ifndef _BINARY_HEAP
#define _BINARY_HEAP

struct HeapStruct;
typedef HeapStruct * PriorityQueue;
typedef int ElementType;


PriorityQueue Initialize(int MaxElements);
void Destory(PriorityQueue H);
void makeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int isEmpty(PriorityQueue H);
int isFull(PriorityQueue H);

/*打印二叉堆，利用递归打印，输出结果与二叉树相似*/
void printBHeap(PriorityQueue H, int depth, int Index);
#endif

struct HeapStruct
{
	int capacity;
	int size;
	ElementType * Elements;
};
