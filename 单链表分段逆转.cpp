#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */
List ReadInput();
void PrintList( List L );
void K_Reverse( List L, int K );

int main()
{
    List L;
    int K;
    L = ReadInput();
    scanf("%d", &K);
    K_Reverse( L, K );
    PrintList( L );
    return 0;
}

// ========== 你的提交代码 ==========
// ========== 适配PTA输入：第一行n，第二行n个数字 ==========
List ReadInput()
{
    int n;
    scanf("%d",&n);
    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    PtrToNode tail = head;
    ElementType x;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        PtrToNode p = (List)malloc(sizeof(struct Node));
        p->Data = x;
        p->Next = NULL;
        tail->Next = p;
        tail = p;
    }
    return head;
}

void PrintList( List L )
{
    PtrToNode p = L->Next;
    int first=1;
    while(p != NULL)
    {
        if(!first) printf(" ");
        first=0;
        printf("%d", p->Data);
        p = p->Next;
    }
    printf("\n");
}

void K_Reverse( List L, int K )
{  if(K <= 1) return;  //不然会死循环 
	//是带头结点的单链表 不然要自己创建一个头节点来方便手元节点的操作 
	List end=L,prehead=L;//prehead记录前一段（翻转后的）的最后一个节点 
	List cur,nex; //end 和prehead 必须放在循环之前定义 
	while(1)//注意 
	{ end=prehead;
	  for(int i=0;i<K;i++)
	    {   if(end==NULL) return; //如果不足K个就return 
	    	end=end->Next;//end 记录当前段的最后一个节点
		}
		List pre; //用pre 和cur 加一个辅助节点完成反转 
		if(end==NULL) return;
	    pre=prehead;  //指向当前节点的前一个节点 
	    cur=pre->Next;
	    List start=cur;//记录本段开始的节点 
	    List nextset=end->Next ;//记录下一段的头节点 
	    while(pre!=end)//是pre 不是end 
	    {
	    	nex=cur->Next; 记//录当前节点的下一个节点 
	    	cur->Next=pre; //修改指针方向 
	    	pre=cur; //pre cur继续往前走 
	    	cur=nex;
		}
	    prehead->Next=end;//前一段末尾指向这一段开头 
	    start->Next=nextset; //这一段末尾指向下一段开头 
	    prehead=start; 
	}
	return ;
}
/* 你的代码将被嵌在这里 */
