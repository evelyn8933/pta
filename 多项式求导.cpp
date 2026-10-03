#include <stdio.h>
#include <stdlib.h>
struct node
{
	int xishu;
	int cishu;
 } ;
int main()
{ struct node st[1001];
int index=0;
int cx,cc;
 while(scanf("%d %d",&cx,&cc)!=EOF)
 {
 	   st[index].xishu =cx;
		st[index].cishu=cc;
		index++;
 }
 for(int i=0;i<index;i++)
 {
 	int cx=st[i].xishu*st[i].cishu;
 	int cc=st[i].cishu-1;
 	if(cx!=0) 
 	{if(i!=0) printf(" ");
	 printf("%d %d",cx,cc);
	 }
	 else
	 {
	 	if(index==1)
	 	printf("0 0",cc);//没有别的非零项的话 
	  } 
 }
return 0;
 } 
