#include <stdio.h>
#include <stdlib.h>
typedef char ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

PtrToNode Suffix( List L1, List L2 );

// 【本地测试用：打印子链表，从StartP开始输出】
void PrintSublist( PtrToNode StartP )
{
    PtrToNode p = StartP;
    if(!p){
        printf("NULL\n");
        return;
    }
    while(p){
        printf("%c", p->Data);
        p = p->Next;
    }
    printf("\n");
}

// 【本地测试用：构造样例 loading 和 being，共享 i n g】
void ReadInput( List L1, List L2 )
{
    // 公共后缀结点 i -> n -> g
    PtrToNode g = (PtrToNode)malloc(sizeof(struct Node)); g->Data='g'; g->Next=NULL;
    PtrToNode n = (PtrToNode)malloc(sizeof(struct Node)); n->Data='n'; n->Next = g;
    PtrToNode i = (PtrToNode)malloc(sizeof(struct Node)); i->Data='i'; i->Next = n;

    // loading: l o a d -> i
    PtrToNode d = (PtrToNode)malloc(sizeof(struct Node)); d->Data='d'; d->Next = i;
    PtrToNode a = (PtrToNode)malloc(sizeof(struct Node)); a->Data='a'; a->Next = d;
    PtrToNode o = (PtrToNode)malloc(sizeof(struct Node)); o->Data='o'; o->Next = a;
    PtrToNode l = (PtrToNode)malloc(sizeof(struct Node)); l->Data='l'; l->Next = o;
    L1->Next = l;

    // being: b e -> i
    PtrToNode e = (PtrToNode)malloc(sizeof(struct Node)); e->Data='e'; e->Next = i;
    PtrToNode b = (PtrToNode)malloc(sizeof(struct Node)); b->Data='b'; b->Next = e;
    L2->Next = b;
}

int main()
{
    List L1, L2;
    PtrToNode P;
    L1 = (List)malloc(sizeof(struct Node));
    L2 = (List)malloc(sizeof(struct Node));
    L1->Next = L2->Next = NULL;
    ReadInput( L1, L2 );
    P = Suffix( L1, L2 );
    PrintSublist( P );
    return 0;
}

PtrToNode Suffix( List L1, List L2 ) 
{
	List p1=L1->Next ,p2=L2->Next ; //有头结点 
	int len1=0,len2=0;
	for(;p1!=NULL;p1=p1->Next)  len1++; //长链表前面多出来的结点不可能是公共后缀的一部分
	for(;p2!=NULL;p2=p2->Next)  len2++; //让两个指针走到「离末尾距离相等」的位置 然后两个指针同步往后走
	p1=L1->Next;
	p2=L2->Next;
	if(len1>len2)
	{ for(int i=0;i<len1-len2;i++)
	   {p1=p1->Next;
	   }
	}
	else
	{ for(int i=0;i<len2-len1;i++)
	   {p2=p2->Next;
	   }
	} 
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1==p2) return p1;
		p1=p1->Next;
		p2=p2->Next; 
	}	 
	return NULL;
}
/* 你的代码将被嵌在这里 */
