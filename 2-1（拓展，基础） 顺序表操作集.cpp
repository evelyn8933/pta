#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
#define ERROR -1

// 删掉原来的enum bool，改用宏定义，避开VS报错
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
#define bool int
#define true 1
#define false 0

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */
List MakeEmpty()
{
    List empty = (List)malloc(sizeof(struct LNode));
    empty->Last = -1;//初始化
    return empty;
}
Position Find(List L, ElementType X)
{
    for (int i = 0; i <= L->Last; i++)
        if (L->Data[i] == X)
            return i;
    return ERROR;
}
bool Insert(List L, ElementType X, Position P)
{
    if (L->Last==MAXSIZE-1)
    {
        printf("FULL");
        return false;
    }
    if (P<0 || P>L->Last+1) //在表的末尾之后也可以 只能连着插入 
    {
        printf("ILLEGAL POSITION");
        return false;
    }
    if (P ==L->Last + 1)
    {
        L->Data[P] = X;
        (L->Last)++; //插入之后要更新总数 
        return true;
    }
    for (int i = L->Last; i >= P; i--)
    {
        L->Data[i + 1] = L->Data[i];

    }
    L->Data[P] = X;
    (L->Last)++;
    return true;
}
bool Delete(List L, Position P)
{
    if (P<0 || P>(L->Last))
    {
        printf("POSITION %d EMPTY", P);
        return false;
    }
    if (P == L->Last) L->Data[P] = 0;
    for (int i = P; i < L->Last; i++)
    {
        L->Data[i] = L->Data[i + 1];
    }
    (L->Last)--;
    return true;
}

