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
}
int pop()
{
	int c=num[front];
	front++;
	return c;
}
int main()
{   int n;
    int ancestor;
   scanf("%d",&n);
   struct TT family[100001];
   int h;
   for(h = 1; h<=n; h++) //注意下标对齐 
{
    family[h].child = NULL; //因为在连接孩子节点的时候要判断头指针是不是为空 
    family[h].karry = 0;//为了防止垃圾值需要对所有链表初始化 
}
   int i=1;
   while(i<=n)
   { int cur;
     scanf("%d",&cur); //如果从0开始下标对不上 
     family[i].parent=cur;//赋值和==区别开 
     if(cur==-1) 
	 {
	 ancestor=i;
	 family[i].karry=1;
     }
     else 
     {  struct node *p1=(struct node*)malloc(sizeof(struct node));
        p1->index=i;
        p1->next=NULL;
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
   while(rear!=front )
   {  
   	  int p=pop();
   	  int nowk=family[p].karry ;
   	  struct node *kid=family[p].child;
	  while(kid!=NULL)
	  {  
	  	 int s=kid->index;
	  	 family[s].karry=nowk+1;
	  	 if(nowk+1>maxkarry) maxkarry=nowk+1;//跟孩子的Karry比较 
	  	 push(s);
	  	 kid=kid->next;
	  } 
   }
   printf("%d\n",maxkarry);
   int j=1;
   int flag=0;
   while(j<=n)
   {  if(family[j].karry ==maxkarry) 
       {  if(flag) printf(" ");
       	  printf("%d",j);
       	  flag++;
	   }
   	j++;
   }
	return 0;
}
