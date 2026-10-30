
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define false 0
#define true 1

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
    int flag;
};

/*------堆栈的定义-------*/
typedef Position SElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
    SElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* 裁判实现，细节不表 */
Stack CreateStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty( Stack S )
{
    return S->Next == NULL;
}

bool Push( Stack S, SElementType X )
{
    PtrToSNode newNode = (PtrToSNode)malloc(sizeof(struct SNode));
    if (!newNode) return false;
    newNode->Data = X;
    newNode->Next = S->Next;
    S->Next = newNode;
    return true;
}

SElementType Pop( Stack S )
{
    PtrToSNode tmp;
    SElementType val;
    tmp = S->Next;
    val = tmp->Data;
    S->Next = tmp->Next;
    free(tmp);
    return val;
}

SElementType Peek( Stack S )
{
    return S->Next->Data;
}

/*----堆栈的定义结束-----*/

BinTree CreateBinTree(); /* 裁判实现，细节不表 */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreateBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    return 0;
}
void InorderTraversal( BinTree BT )
{
	Stack st=CreateStack();
	SElementType p=BT;
	while(p&&isIsEmpty(st))
	{
		while(p)
		{
			
			push(st,p);
			p=p->Left;
		}
		p=pop(st);
		printf("%c ",p->Data);
		p=p->Right;
	}
	
}
void PreorderTraversal( BinTree BT )
{
	Stack st=CreateStack();
	SElementType p=BT;
	while(p&&isIsEmpty(st))
	{
		while(p)
		{   printf("%c ",p->Data);
		    push(st,p);
			p=p->Left;
		}
		p=pop(st);
		p=p->Right;
	}
	return ;
}
void PostorderTraversal( BinTree BT )
{
	Stack st=CreateStack();
	SElementType p=BT;
	while(p&&isIsEmpty(st))
	{
		re
		while(p)
		{   
		    p->flag=0;
		    push(st,p);
			p=p->Left;
		}
		p=peek(st);
		if(p->flag==0)
		{
			p->flag=1;
			p=p->Right;
		}
		else
		{   printf("%c ",p->Data);
		    pop(st);
		    p=NULL;
		}
	}
	return ;
}
