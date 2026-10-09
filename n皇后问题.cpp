#include <stdio.h>
#include <stdlib.h>
int chess[11];
int n;
int index=0;
int check(int row,int line)
{  int flag=0;
	for(int r=1;r<row;r++)
	{ if(chess[r]==line||abs(chess[r]-line)==abs(r-row))
	    {flag=1;
	    return 0;
		}		
	}
	if(flag==0) return 1;
}
void queen(int row)
{   if(row>n)
    { index++;
        if(index>1) printf("\n");//每一组解之间有空行 因为无法判断是否是最后 
    	for(int r=1;r<=n;r++) //所以在每组解前输出 
    	{
    		for(int l=1;l<=n;l++)
    		 {
    		 	if(l==chess[r]) printf("Q");
    		 	else printf(".");
    		 	if(l!=n) printf(" ");//最后一个字符后没有解 
			 }
			 printf("\n");
		}
		
	}
	for(int line=1;line<=n;line++)
	{
		if(check(row,line)) 
		{
		chess[row]=line;
		queen(row+1);
	    }
	}
	return ;
}
int main()
{   scanf("%d",&n);
queen(1);
if(index==0) printf("None\n");
	return 0;
}
