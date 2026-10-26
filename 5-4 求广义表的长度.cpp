#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{   char str[10001],no[10001];
scanf("%s",str);
int len=strlen(str);
str[len]='\0';
int j=0,p=0;
for(;j<len;j++)
{   if(str[j]!='\n')
	if(str[j]!=' ')
	no[p++]=str[j];
}
printf("%s",no);
  if(strcmp(no,"()")==0) 
   { 
	printf("0");
	return 0;
   }
	int dep=0;
	int num=0;
	int i=0;
	int lens=strlen(no);
	for(i=1;i<lens-1;i++)
	{   char ch=no[i];
		if(ch=='(')
		{ dep++;
		}
		else if(ch==')')
		{
			dep--;
		}
		else if(ch==','&&dep==0)
		 num++;
	}
	printf("%d",num);
}
