#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct three
{
	int i;
	int j;
	int elm;
};
int main()
{ int m,n;
  scanf("%d%d",&m,&n);
  struct three M1[100],M2[100],outcome[100];
    int n1;
  scanf("%d",&n1);
  int u1=0;
  for(u1=0;u1<n1;u1++)
   {
	scanf("%d%d%d",&M1[u1].i,&M1[u1].j,&M1[u1].elm);//输入m1 
   } 
  int n2;
  scanf("%d",&n2);
  int u2;
  for(u2=0;u2<n2;u2++)
  {  scanf("%d%d%d",&M2[u2].i,&M2[u2].j,&M2[u2].elm);//输入m2 
  }
  int l=0,t=0,q=0;
  while(l<n1&&t<n2)
  {  if(M1[l].i<M2[t].i ||(M1[l].i==M2[t].i &&M1[l].j<M2[t].j))
       {
       	 outcome[q++]=M1[l++];
	   }
	 if(M1[l].i>M2[t].i ||(M1[l].i==M2[t].i &&M1[l].j>M2[t].j))
	 { outcome[q++]=M2[t++];
	 }
	 if(M1[l].i==M2[t].i &&M1[l].j==M2[t].j)
	 {  if(M1[l].elm+M2[t].elm!=0) //和不为0再加入 
	 	{
		 outcome[q].i=M1[l].i;
	 	outcome[q].j=M1[l].j;
	 	outcome[q].elm=M1[l].elm +M2[t].elm ;
	 	q++; 
	    }
	 	l++; //即使和为0 指针也要继续前进 
	 	t++;
	 }
  }
  
  if(l<n1)
  {
  	while(l<n1) outcome[q++]=M1[l++];
  }
  else if(t<n2) 
  {
  	while(t<n2) outcome[q++]=M2[t++];
  }
  printf("%d\n",q);
  int s=0;
  for(s=0;s<q;s++)
  { if(abs(outcome[s].elm)>0.1)
  	printf("%d %d %d\n",outcome[s].i,outcome[s].j,outcome[s].elm);
  }
}
