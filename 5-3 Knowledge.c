#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char trix[101][101];//用字符数组 
int m,n,ans=0;
bool vis[101][101]={0};
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void dfs(int x,int y)
{  vis[x][y]=true;
  int k=0;
  for(;k<4;k++)
  {
  	int nextx=x+dx[k];
  	int nexty=y+dy[k];
  	if(nextx>=0&&nexty>=0&&nextx<m&&nexty<n&&trix[nextx][nexty]!='0'&&vis[nextx][nexty]==0)
  	{
  		dfs(nextx,nexty);
	}
  }	
}
int main()
{ scanf("%d %d",&m,&n);
getchar();// 吃掉m,n后面的换行！重点！
int i,j;
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
		scanf("%c",&trix[i][j]);
	}
	getchar();// 读完一行吃掉行尾换行
}
int p,q;
   for(p=0;p<m;p++)
   {
	for(q=0;q<n;q++)
	  {
	  	if(trix[p][q]!='0'&&vis[p][q]==0)
	  	 {
	  	 	ans++;
	  	 	dfs(p,q);
		   }
	  }
	}
printf("%d",ans);
return 0;	
}
