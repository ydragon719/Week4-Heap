#include "LeftistHeap.h"
#include <stdlib.h>
#include <iostream>
PriorityQueue merge1(PriorityQueue H1, PriorityQueue H2);
void switchChildren(PriorityQueue H);

PriorityQueue merge(PriorityQueue H1, PriorityQueue H2)
{
	if(H1 == NULL)
		return H2;
	if(H2 == NULL)
		return H1;

	if(H1->Element < H2->Element)
		return merge1(H1, H2);
	else
		return merge1(H2, H1);
}

PriorityQueue merge1(PriorityQueue H1, PriorityQueue H2)
{
	if(H1->Left == NULL)
		H1->Left = H2;
	else
	{
		H1->Right = merge(H1->Right, H2);
		if(H1->Left->Npl < H1->Right->Npl)
			switchChildren(H1);

		H1->Npl = H1->Right->Npl +1;
	}

	return H1;
}

ElementType findMin(PriorityQueue H)
{
	return H->Element;
}

int isEmpty(PriorityQueue H)
{
	return H == NULL;
}

PriorityQueue deleteMin(PriorityQueue H)
{
	if(H == NULL)
		return H;
	PriorityQueue Leftchild, Rightchild;
	Leftchild = H->Left;
	Rightchild = H->Right;
	free(H);
	return merge(Leftchild, Rightchild);
}

PriorityQueue insert(ElementType X, PriorityQueue H)
{
	PriorityQueue newone = (PriorityQueue)malloc(sizeof(TreeNode));
	newone->Element = X;
	newone->Left = newone->Right = NULL;
	newone ->Npl =0;
	H = merge(H, newone);
	return H;
}



void switchChildren(PriorityQueue H)
{
	if(H == NULL)
		return;

	PriorityQueue temp;
	temp = H->Right;
	H->Right = H->Left;
	H->Left = temp;

}


void PrintDepth(ElementType A, int depth)
{
	while(depth !=0)
	{
		printf("	");
		depth --;
	}
	printf("%d\n", A);
}

void PrintTree(PriorityQueue T, int depth)
{
	if(T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if(T->Left != NULL)
		PrintTree(T->Left, depth+1);

	PrintDepth(T->Element, depth);
	if(T->Right !=NULL)
		PrintTree(T->Right, depth+1);
}

void PrintTree(PriorityQueue T)
{
	if(T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if(T->Left != NULL)
		PrintTree(T->Left);

	printf("%d\n",T->Element);
	if(T->Right !=NULL)
		PrintTree(T->Right);
}
int main()
{
	int i;
	PriorityQueue One;
	One = NULL;

	/*插入数据，先插入10，再分别按偶数奇数插入0-20*/
	insert(10, One);

	for(i = 0; i<10; i++)
	{
		One = insert(2*i, One);
	}

	for(i = 0; i<10; i++)
	{
		One = insert(2*i+1, One);
	}
	/*打印出树，每一级深度加一个4个空格，先打印左子树再打印右子数*/
	PrintTree(One,0);
	printf("\n\n\n\n");

	/*寻找5之后的树*/

	PrintTree(One,0);
	printf("\n\n\n\n");

	/*删除元素之后的树*/



	PrintTree(One,0);






	std::cout<<std::endl;
