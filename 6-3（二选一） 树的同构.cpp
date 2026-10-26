#include <stdio.h>
#include <stdlib.h>
int lchild1[1001],rchild1[1001];
int lchild2[1001],rchild2[1001];
char A1[1001],A2[1002];
void creat(int n,int lchild[1001],int rchild[1001],char A[1001])
{  int i;
   for(i=0;i<n;i++)
	{   scanf(" %c",&A[i]);
		char cl,cr;
		scanf(" %c",&cl);
		scanf(" %c",&cr);
		getchar();
		if(cl=='-') lchild[i]=-1;
		else lchild[i]=cl-'0';
		if(cr=='-') rchild[i]=-1;
		else rchild[i]=cr-'0';
	}
	return;
}
int root(int lchild[1001],int rchild[1001],int n)
{   int index=0;
    int flag=0;
    int s,m;
	for(s=0;s<n;s++)
	{   flag=0;
		for(m=0;m<n;m++)
		{
			if(rchild[m]==s||lchild[m]==s)
			{ flag=1;
			 break; 
			}
		}
		if(!flag) 
		{index=s;
		break;
		}
	}
   return index;		
}
int same(int root1,int root2)
{  if(A1[root1]!=A2[root2]) return 0;
   int l1=lchild1[root1],l2=lchild2[root2],r1=rchild1[root1],r2=rchild2[root2];
   if(A1[l1]==A2[l2])
   {   if(A1[r1]==A2[r2])
      {  if(same(l1,l2)&&same(r1,r2)) return 1;
         else return 0;
      }
      else return 0;
   }
   else if(A1[l1]==A2[r2])
   {  if(A1[r1]==A2[l2])
      {  if(same(l1,r2)&&same(r1,l2)) return 1;
         else return 0;
      }
      else return 0;  	  
   }
   else return 0;
}
int main()
{   int n1;
	scanf("%d",&n1);
	getchar();
	creat(n1,lchild1,rchild1,A1);
	int root1=root(lchild1,rchild1,n1);
	int n2;
	scanf("%d",&n2);
	getchar();
	creat(n2,lchild2,rchild2,A2);
	int root2=root(lchild2,rchild2,n2);
	if(same(root1,root2)) printf("YES");
	else printf("NO");
	return 0;
}
