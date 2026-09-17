#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput();
void PrintList( List L );
List Delete( List L, ElementType minD, ElementType maxD );

List ReadInput()
{
    List L = (List)malloc(sizeof(struct LNode));
    int n;
    scanf("%d", &n);
    L->Last = n - 1;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &L->Data[i]);
    }
    return L;
}

void PrintList( List L )
{
    for(Position i = 0; i <= L->Last; i++)
    {
        if(i>0) printf(" ");
        printf("%d", L->Data[i]);
    }
    printf("\n");
}

int main()
{
    List L;
    ElementType minD, maxD;
    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );
    return 0;
}

/* ==========在这里写你的Delete函数========== */
List Delete( List L, ElementType minD, ElementType maxD )
{
	int last=L->Last;
	while(L->Data[last]>minD&&L->Data[last]<maxD)
	{
		last--;
	 } 
	 for(int i=0;i<last;i++)
	 {
	 	if(L->Data[i]>minD&&L->Data[i]<maxD)
	 	 {
	 	 	for(int j=i;j<last;j++)
	 	 	 {	L->Data[j]=L->Data[j+1];
			   }
			last--;
			i--;
		  }
	 }
	 L->Last=last;
	 return L;
}
