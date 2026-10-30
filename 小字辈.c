#include <stdio.h>
#include <stdlib.h>
struct node
{  int index;
   struct node * next;
};
struct TT
{   int karry;
	int parent;
	struct node *child;
};
	int num[100001];
	int rear=0,front=0;
void push(int a)
{
	num[rear++]=a;
	printf("%d",a);
}
int pop()
{
	int c=num[front];
	front=front+1;
	return c;
}
int main()
{   int n;
    int ancestor;
   scanf("%d",&n);
   struct TT family[100001];
   int i=0;
   while(i<n)
   { int cur;
     scanf("%d",&cur);
     family[i].parent=cur;
     if(cur==-1) 
	 {
	 ancestor=i;
	 family[i].karry=1;
     }
     else 
     {  struct node *p1=(struct node*)malloc(sizeof(struct node));
        p1->index==i;
        p1->next==NULL;
     	if(family[cur].child==NULL)
     	  {
     	  	family[cur].child=p1;
		  }
		else
		  {  p1->next=family[cur].child;
		     family[cur].child=p1;    
		  }
     	  
	 }
   	 i++;
   }
   push(ancestor);
   int maxkarry=1;
   while(rear ==front )
   {
   	  int p=pop();
   	  printf("%d",p);
   	  int nowk=family[p].karry ;
   	  struct node *kid=family[p].child;
	  while(kid!=NULL)
	  {  
	  	 int s=kid->index;
	  	  printf("%d",s);
	  	 family[s].karry=nowk+1;
	  	 push(s);
	  	 kid=kid->next;
	  }
	   if(nowk>maxkarry) maxkarry=nowk; 
   }
   printf("%d\n",maxkarry);
   int j=0;
   int flag=0;
   while(j<n)
   {  if(family[j].karry ==maxkarry) 
       {  if(flag) printf(" ");
       	  printf("%d",j);
	   }
   	j++;
   }
	return 0;
}
