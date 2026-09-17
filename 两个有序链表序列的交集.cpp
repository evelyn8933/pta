#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int num;
	struct node *next;
}node;
 void set(node**head) // head 是二级指针：存的是main中head1这个一级指针的地址
{ int current;
  node *p1,*p2=NULL;//不然无法判断 
  scanf("%d",&current);/ //*head 等价于：去head保存的地址，修改那个一级指针变量的值
while(current!=-1)
	{   
		p1=(node *)malloc(sizeof(node));
		p1->num=current;
		if(*head==NULL)
		 {*head=p1;
		 }
		else p2->next=p1;
	    p2=p1;
	    scanf("%d",&current);
	
	}
	if(p2!=NULL) //提前判断访问防止垃圾值 
	p2->next=NULL;
	return ;
}
int main()
{
	node *head1=NULL,*head2=NULL;
	set(&head1);
    set(&head2);//传指针的地址  
	node *p1=head1,*p2=head2;	
node *p3,*p4,*head=NULL;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->num <p2->num) 
		{p1=p1->next;
		}
		else if(p1->num==p2->num)
		{ p3=(node *)malloc(sizeof(node));
		  p3->num=p1->num;
		  if(head==NULL) head=p3;
		  else p4->next=p3;
		  p4=p3;
		  p1=p1->next;
		  p2=p2->next;
		}
		else p2=p2->next;
	}
	if(p4!=NULL)
	  p4->next=NULL;
	if(head==NULL) printf("NULL");
	else 
{	while(head!=NULL)
	{
	printf("%d",head->num);
	if(head->next!=NULL) 
	  printf(" ");
	head=head->next;
	}
}
return 0;
}
