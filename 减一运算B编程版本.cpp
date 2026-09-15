#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num[1001];
	int i=0;
	while(scanf("%d",&num[i])!=EOF) 
	  { i++;
	  }
	int borrow=1;
	for(int j=i-1;j>=0;j--)
	 {if(num[j]!=0||borrow==0)
	   { num[j]=num[j]-borrow; 
	     borrow=0;
	   }
	  else 
	  {num[j]=num[j]-borrow+9;
	   borrow=1;
	  }
	 }
	 int t=0;
	 while(num[t]==0)
	    t++;
	for(;t<i;t++)
	  {  printf("%d",num[t]);
	  if(t<i-1) printf(" ");
	   } 
	return 0;
 } 
