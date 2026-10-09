#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int priority(char ch)
{
	if(ch=='(') return 0;
	else if(ch=='+'||ch=='-') return 1;
	else return 2;
}
int main()
{
	char str[50];
	gets(str);
	int len=strlen(str);
	char stack[50];
	int top=0;
	for(int i=0;i<len;)
	{  
		char ch=str[i];
		char cur;	
		char token[50];
		  int index=1;
		  token[0]=ch;
		  if((ch>='0'&&ch<='9')||ch=='-')
		  {
		    i++; 
		    for(index=1;i<len&&str[i]>='0'&&str[i]<='9';i++) 
		    {   token[index++]=str[i];		  	
		    }
	      }
	      i--;
		  token[index]='\0';
		  if(index==1&&(ch>'9'||ch<'0')) 
		  {  if(ch=='(')
		    { 
			stack[top++]='(';			
	     	} 
		    else if(ch==')')
		    {   
			cur =stack[top-1];
			while(cur!='(')
			{ 
				printf("%c ",cur);
				top--;
				cur=stack[top-1];			
			}
			top--; //µ¯³ö×óÀ¨ºÅ£¬²»Êä³ö
		    }
		    else //+-*/
		   {  
			while(top>0 && priority(ch) <= priority(stack[top-1]))
			{
				cur = stack[top-1];
				printf("%c ", cur);
				top--;
			}
			stack[top++] = ch;
		   } 	
		  }
		  else
		  {  for(int j=0;j<index;j++)
		  	printf("%c ",token[j]);
		  }		
		
	}
	while(top>0)
	{  printf("%c",stack[top-1]);
		top--; 
	}
	return 0;
}

