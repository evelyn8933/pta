#include <stdio.h>
#include <stdlib.h>
struct node 
{   int data;
	int next;
};
struct node st[100001];
int main()
{
	int head,n;
	scanf("%d%d",&head,&n);
	for(int t=0;t<n;t++)
	{ int cur;
	scanf("%d",&cur);
	scanf("%d%d",&st[cur].data,&st[cur].next ); //可能存在无效节点 
	}
	int a[100001],z[100001];
	int current=head;
	int index; 
	for( index=0;current!=-1;) //只记录有效节点 
	{
		a[index++]=current;
		current=st[current].next;
	} //index已经加1了 
	int pl,pr;
	int left,right;
	for( left=0,right=index-1;left<right;left++,right--)//right从index-1开始取 
	{  pl=a[left];
	pr=a[right];
	printf("%05d %d %05d\n",pr,st[pr].data,a[left]);
	if(left+1>right-1)
	printf("%05d %d -1\n",pl,st[pl].data );	
	else printf("%05d %d %05d\n",pl,st[pl].data,a[right-1] );	
	}
	pl=a[left];
	if(left==right) printf("%05d %d -1\n",pl,st[pl].data );
	return 0;
}
