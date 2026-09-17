#include <stdio.h>
#include <stdlib.h>
#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List; 
List Read();
void Print( List L );
ElementType Find( List L, int m );
int main()
{
    List L;
    int m;
    L = Read();
    Print(L);
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}

List Read()
{
    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    PtrToNode tail = head;

    ElementType val;
    scanf("%d", &val);
    while(val != -1)
    {
        PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
        p->Data = val;
        p->Next = NULL;
        tail->Next = p;
        tail = p;
        scanf("%d", &val);
    }
    return head;
}

void Print( List L )
{
    PtrToNode p = L->Next;
    while(p != NULL)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
}
/* 你的代码将被嵌在这里 */
ElementType Find( List L, int m )
{   if(L==NULL) return ERROR;
	List lp=L->Next; //注意有头结点 
	int sum=0;
	while(lp!=NULL)
	{sum++;
	lp=lp->Next;
	}
	if(m>sum) return ERROR;
	int i=0,outcome;
	lp=L->Next;
	while(lp!=NULL)
	{   i++;
	    if(i==sum+1-m) 
	    { 
	    return lp->next;
		}
		lp=lp->Next;
	}
}
