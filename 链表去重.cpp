#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
typedef struct node 
{int data;
int next;
} node;
node origin[100000];
node del[100000]; 
bool record[100000];
int main()
{  int first,n;
scanf("%d%d",&first,&n);
for(int i=0;i<n;i++)
{  int  cur;
	scanf("%d",&cur);
	scanf("%d%d",&origin[cur].data,&origin[cur].next);	
}

int last=-1,position=first;
int second=0;
int head=-1,flag=0;//防止sefist没有值使用崩溃 
while(position!=-1)
{  int ab= origin[position].data; //提前缓存 
   int cd=origin[position].next;//防止多次访问数组导致超时 
if(record[abs(ab)])
     {
     	if(flag==0)
     	 { 
     	   head=position; //记录新表头 
     	   flag=1;
		  }
		else
		{del[second].next=position;		
		}
		 second=position;
		 del[position].data=ab;
		 del[position].next=-1;		 
	 
       if(last!=-1)
        {
          origin[last].next= cd;	
        }
    }
   else 
     { record[abs(ab)]=true;
      last=position;
     }	
     position=cd;
}
origin[last].next=-1;
while(first!=-1)
{  int td=origin[first].next;
	printf("%05d %d ",first,origin[first].data);
	if(td!=-1)
	printf("%05d\n",td);
	else printf("%d\n",td);
	first=td;
}
while(head!=-1)
{  printf("%05d %d ",head,del[head].data);
int td=del[head].next;
if(td!=-1)
	printf("%05d\n",td);
	else printf("%d\n",td);
   head=td;	
}
return 0;
 } 
