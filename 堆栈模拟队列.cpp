#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Stack
{
	int *data;
	int top;
	int max;
}in,out;

Stack &create(int m)
{
    Stack *mp = new Stack;
	mp->data =(int *)malloc(sizeof(int)*m);
	mp->max=m;
	mp->top=0;
	return *mp;
}
int IsFull(Stack S)
{
	if(S.top==S.max) return 1;
	return 0;
}
int IsEmpty (Stack S )
{
	if(S.top==0) return 1;
	return 0;
}
void Push(Stack &S, ElementType item )
{
	int topp=S.top;
	S.data[topp]=item;
	S.top=S.top+1;
	return;
}
ElementType Pop(Stack &S )
{
	S.top-=1;
	return(S.data[S.top]);
}

void AddQ(ElementType item)
{
	if(IsFull(in))
	{
		if(!IsEmpty(out))
		{
			printf("ERROR:Full\n");
			return ;
		}
		while(!IsEmpty(in))
		{
			Push(out,Pop(in));
		}
	}
	Push(in,item);
	return;
}
ElementType DeleteQ() 
{
	if(IsEmpty(out))
	{
		if(IsEmpty(in))
		{
			printf("ERROR:Empty\n");
			return 0;
		}
		while(!IsEmpty(in))
		{
			Push(out,Pop(in));
		}
	}
	printf("%d\n",Pop(out)) ;
	return 0;
}

int main()
{
	int n1,n2;
	scanf("%d %d",&n1,&n2);
	if(n1>n2)
	{
		in=create(n2);
		out=create(n1);
	}
	else
	{
		in=create(n1);
		out=create(n2);
	}
	char ch;
	while(1)
	{
		scanf(" %c",&ch);
		if(ch=='T') break;
		else if(ch=='A')
		{
			int cur;
			scanf("%d",&cur);
			AddQ(cur);
		}
		else if(ch=='D')
		{
		DeleteQ();
		}
	}
	free(in.data); //最后要释放 
	free(out.data);
	return 0;
}

