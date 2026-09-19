#include <stdio.h>
#include <stdlib.h>
struct node
{ int data;
 struct node *next;
};

int main()
{ int n,m;
scanf("%d%d",&n,&m);
struct node *head=NULL,*p1,*p2=NULL;
for(int i=1;i<=n;i++)
{
	p1=(struct node *)malloc(sizeof(struct node));
	p1->data=i;
	if(head==NULL) head=p1;
	else p2->next=p1;
	p2=p1;
}
if(p2!=NULL) p2->next=head;
struct node *pre=p2,*cur=head;
int cnt=0;
while(pre!=cur)
{
	cnt++;
	if(cnt==m) 
	{
		printf("%d ",cur->data);
		struct node *p=cur;
		pre->next=cur->next;
		cur=cur->next;
		free(p);
		cnt=0;
	}
	else
	{pre=cur;
	cur=cur->next; 
	}
}
printf("%d",pre->data);
pre=cur=NULL;
free(pre);
free(cur);
return 0;	
} 
