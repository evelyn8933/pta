#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	int num[1002];
	scanf("%d",&n);
	int t;
	for(t=1;t<=n;t++)
	{
		scanf("%d",&num[t]);
	}
	int i,j;
	scanf("%d%d",&i,&j);
	if(num[i]==0) printf("ERROR: T[%d] is NULL",i);
	else if(num[j]==0) printf("ERROR: T[%d] is NULL",j);
	else
	{
		while(i>0&&j>0&&i!=j)
		{ if(i<j) j=j/2;
		  else i=i/2;
		}
		printf("%d %d",i,num[i]);//ÔÚelseÀ¨ºÅÄÚ 
	}
	return 0;
}
