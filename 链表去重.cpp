#include <stdio.h>
#include <stdbool.h>
#include <math.h>
typedef struct node 
{int data;
int next;
} node;
node origin[100000];
bool record[100001]={0};
int main()
{  int remain[100001];
int del[100001];
int first,n;
scanf("%d%d",&first,&n);
for(int i=0;i<n;i++)
{
	int cur;
	scanf("%d",&cur);
	scanf("%d%d",&origin[cur].data,&origin[cur].next); 
}
int position=first; 
int recnt=0,delcnt=0;
while(position!=-1)
{   int nxt=origin[position].next;
    int ab=origin[position].data;
    if(record[abs(ab)]==false)
     { record[abs(ab)]=true;
       remain[recnt++]=position;	
     }
     else 
     {del[delcnt++]=position;
	 }
     position=nxt;
}
for(int i=0;i<recnt;i++)
{   int cur=remain[i];
	printf("%05d %d ",cur,origin[cur].data); 
	if(i<recnt-1) printf("%05d\n",remain[i+1]);
	else printf("-1\n");
}
for(int j=0;j<delcnt;j++)
{
	int cur=del[j];
	printf("%05d %d ",del[j],origin[cur].data);
	if(j<delcnt-1) printf("%05d\n",del[j+1]);
	else printf("-1\n");
}
return 0;
 } 
