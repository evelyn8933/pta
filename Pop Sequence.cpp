#include <stdio.h>
#include <stdlib.h>
void search(int num[],int n,int m)
{	
	int stack[10001];	
	int top=0;	// top：栈中元素数量，top=0空栈
	int index=1;	// 准备入栈的数字，从1开始
	int t;	
	for( t=0;t<n;t++)	
	{  
		int x=num[t];	 
		// 栈顶不是目标，并且还有数字可以入栈，就持续入栈
		while( (top==0 || stack[top-1]!=x) && index<=n )
		{
		    // 入栈前  检查：栈已经满了，不能再压
			if(top >= m)
			{
				printf("NO\n");
				return ;
			}
			stack[top++]=index++;	     
		}
		// 退出循环，看栈顶是否等于x
		if(top ==0 || stack[top-1]!=x)  //栈为空的时候 
		{
			printf("NO\n");
			return;
		}
		else 
		{
			top--;  // 弹出栈顶
		}        
	}    
	printf("YES\n");    
	return ;
}
int main()
{	
	int m,n,k;	
	scanf("%d%d%d",&m,&n,&k);	
	for(int i=0;i<k;i++)	
	{   
		int num[1001];	    
		for(int j=0;j<n;j++)	     
			scanf("%d",&num[j]);	    
		search(num,n,m);    					
	}	
	return 0;
}

