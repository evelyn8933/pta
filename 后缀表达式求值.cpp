#include <stdio.h>
#include <stdlib.h>
typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );
int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

/* Your function will be put here */
ElementType EvalPostfix( char *expr )
{  double stack[Max_Expr];
   int top=0;//整体栈和数组一起 没有写成结构体 
   for(int i=0;expr[i]!='\0';i++)
   {
   	while(expr[i]==' '&&expr[i]!='\0')
   	{i++;}
   	int start=i,last;
   	while(expr[i]!='\0'&&expr[i]!=' ')
   	{ i++;}
   	last=i-1;
   	int tokenlen=last-start+1;//来区分减号和负号 
   	if(tokenlen==1&&(expr[last]=='+'||expr[last]=='-'||expr[last]=='*'||expr[last]=='/'))
   	{
   		if(top<2) return Infinity;
   		double r=stack[--top];
   		double l=stack[--top];
   		switch(expr[last]) 
   		{
   			case '+': stack[top++]=r+l;break;
   			case '-': stack[top++]=l-r;break;
   			case '*': stack[top++]=l*r;break;
   			case '/': 
			   if(r!=0) 
			   {
			   stack[top++]=l/r;break;	       
			   }
			   else return Infinity;
			default:return Infinity;
		}
   		
   }
   else
   {
    char token[Max_Expr];
    int k,index=0;
    for( k=start;k<=last;k++)
    {
   	 token[index++]=expr[k];
    }
    token[index]='\0'; //手动加终止符号 
     stack[top++]=atof(token);
   }
   }
if(top==1) return stack[0];	
else return Infinity;
}
