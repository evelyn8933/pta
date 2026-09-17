#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}
struct ListNode *createlist()
{
	struct ListNode *head=NULL,*p1,*p2=NULL;
	int current;
	scanf("%d",&current);
	while(current!=-1)
	{
		p1=(struct ListNode*)malloc(sizeof(struct ListNode));
		p1->data=current;
		if(head==NULL) head=p1;
		else p2->next=p1;
		p2=p1;
		scanf("%d",&current);
	}
	if(p2!=NULL) p2->next=NULL; 
	return head;
}
struct ListNode *deleteeven( struct ListNode *head )
{
    struct ListNode *deleteeven( struct ListNode *head )
{
    struct ListNode dummy;   // 虚拟头结点，简化头节点删除逻辑
    dummy.next = head;
    struct ListNode *p = &dummy;

    while(p->next != NULL)
    {
        struct ListNode *temp = p->next;
        if(temp->data % 2 == 0)
        {
            p->next = temp->next;
            free(temp);
        }
        else
        {
            p = p->next;
        }
    }
    return dummy.next;
}

}
/* 你的代码将被嵌在这里 */
