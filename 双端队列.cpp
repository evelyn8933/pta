#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define ERROR -1
#define false 0
#define true 1
typedef int ElementType;
typedef enum { push, pop, inject, eject, end } Operation;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;      /* 存储元素的数组   */
    Position Front, Rear;   /* 队列的头、尾指针 */
    int MaxSize;            /* 队列最大容量     */
};
typedef PtrToQNode Deque; 

Deque CreateDeque( int MaxSize )
{   /* 注意：为区分空队列和满队列，需要多开辟一个空间 */
    Deque D = (Deque)malloc(sizeof(struct QNode));
    MaxSize++;
    D->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    D->Front = D->Rear = 0;
    D->MaxSize = MaxSize;
    return D;
}

bool Push( ElementType X, Deque D );
ElementType Pop( Deque D );
bool Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* 裁判实现，细节不表 */
void PrintDeque( Deque D ); /* 裁判实现，细节不表 */

int main()
{
    ElementType X;
    Deque D;
    int N, done = 0;

    scanf("%d", &N);
    D = CreateDeque(N);
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Deque is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            else printf("%d is out\n", X);
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Deque is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            else printf("%d is out\n", X);
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
bool Push( ElementType X, Deque D )
{ int re=D->Rear,fr=D->Front;
  if((re +1)%D->MaxSize==fr ) return 0;//注意判断 满的 条件 
  else 
  { fr=D->Front=(fr-1+D->MaxSize)%D->MaxSize; //对所有减一的要防止出现负数下标 
  	D->Data[fr]=X;
  	return 1;
  }
}
ElementType Pop( Deque D )
{ int re=D->Rear,fr=D->Front;
if(re==fr) return ERROR;
ElementType t=D->Data[fr];
D->Front=(fr+1)%D->MaxSize;
return t;	
}
bool Inject( ElementType X, Deque D )
{int re=D->Rear,fr=D->Front;
  if((re +1)%D->MaxSize==fr ) return 0;
  D->Data[re]=X;
  D->Rear=(re+1)%D->MaxSize;
  return 1;
}
ElementType Eject( Deque D )
{
	int re=D->Rear,fr=D->Front;
	if(re==fr) return ERROR;
	re=D->Rear=(re-1+D->MaxSize)%D->MaxSize;
	return D->Data [re];
}
Operation GetOp()
{
    char op[20];
    scanf("%s", op);
    if( (op[0] == 'p' || op[0] == 'P') && op[1] == 'u' )
        return push;
    else if( (op[0] == 'p' || op[0] == 'P') && op[1] == 'o' )
        return pop;
    else if( op[0] == 'i' || op[0] == 'I' )
        return inject;
    else if( (op[0] == 'e' || op[0] == 'E') && op[1] == 'j' )
        return eject;
    else if( (op[0] == 'e' || op[0] == 'E') && op[1] == 'n' )
        return end;
    return end;
}

void PrintDeque( Deque D )
{
    printf("Inside Deque:");
    Position p = D->Front;
    while(p != D->Rear)
    {
        printf(" %d", D->Data[p]);
        p = (p + 1) % D->MaxSize;
    }
    printf("\n");
}

