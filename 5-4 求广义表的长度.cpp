#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{   char str[10001];
scanf("%s",str);
if(strcmp(str,"()")==0) 
{
	printf("0");
	return 0;
}
int len=strlen(str);
str[len]='\0';
	int stack[1001];
	int top=0;
	int num=0;
	int i=0;
	for(i=0;i<len;i++)
	{   
		if(str[i]=='(')
		{
			stack[top++];
		}
		else if(str[i]==')')
		{
			top--;
		}
		else if(str[i]==','&&top==0)
		 num++;
	}
	printf("%d",num);
}
