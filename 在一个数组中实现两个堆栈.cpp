#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
#define true 1
#define false 0
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;
Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );
Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Tag ); /* details omitted */
int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
            break;
        case pop:
            scanf("%d", &Tag);
            X = Pop(S, Tag);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
Stack CreateStack( int MaxSize )
{
	Stack tank=( struct SNode*)malloc(sizeof(SNode));//纯C要加struct 
	tank->Data =(ElementType*)malloc(MaxSize*sizeof(int));	
	tank->Top1=-1;
	tank->Top2=MaxSize;
	tank->MaxSize=MaxSize;
	return tank;	 
}
bool Push( Stack S, ElementType X, int Tag )
{
	if((S->Top1)+1==S->Top2) 
	{printf("Stack Full\n");
	return false;}
	if(Tag==1) 
	{ (S->Top1)++;
	  S->Data[S->Top1]=X;
	}
	else
	{(S->Top2)--;
	 S->Data[S->Top2]=X;
	}
	return true;
}
ElementType Pop( Stack S, int Tag )
{
	if(Tag==1)
	{
		if(S->Top1==-1)
		{printf("Stack %d Empty\n",Tag);
		
		return ERROR;}
		
		return S->Data[(S->Top1)--];//更新指针 
	}
	else
	{   if(S->Top2==S->MaxSize)
	{printf("Stack %d Empty\n",Tag);
	
		return ERROR;}
		return S->Data[(S->Top2)++];//更新指针		
	}	
}
Operation GetOp()
{
    char op[10];
    scanf("%s", op);
    if(op[0] == 'P' && op[1] == 'u') return push;
    if(op[0] == 'P' && op[1] == 'o') return pop;
    return end;
}

void PrintStack( Stack S, int Tag )
{
    if(Tag == 1)
    {
        printf("Pop from Stack 1:");
        for(int i = S->Top1; i >= 0; i--)
        {
            printf(" %d", S->Data[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Pop from Stack 2:");
        for(int i = S->Top2; i < S->MaxSize; i++)
        {
            printf(" %d", S->Data[i]);
        }
        printf("\n");
    }
}
