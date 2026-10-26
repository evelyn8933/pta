#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int fa[100001],mo[100001];
bool vis[100001]={0};
char sex[100001];
void dfs(int curid,int dep)
{ if(curid==-1||dep>=5) return ;
  vis[curid]=1;
  dfs(fa[curid],dep+1);
  dfs(mo[curid],dep+1);
  return ;
}
bool check(int x,int dep)
{  if(x==-1||dep>=5) return 1;
   if(vis[x]) return 0;
   else vis[x]=1;
   if(check(fa[x],dep+1)&&check(mo[x],dep+1)) 
     return 1;
    else return 0;
	
}
int main()
{ int n;
scanf("%d",&n);
int i=0;
for(i=0;i<n;i++)
{
	int id,f,m;
	char gender; 
	scanf("%d %c%d%d",&id,&gender,&f,&m);
	fa[id]=f;
	mo[id]=m;
	sex[id]=gender;
	if(f!=-1) sex[f]='M';
	if(m!=-1) sex[m]='F';
}
int k;
scanf("%d",&k);
int j=0;
  for(;j<k;j++)
  { memset(vis,0,sizeof(vis));
	int id1,id2;
	scanf("%d%d",&id1,&id2);
	if(sex[id1]==sex[id2]) printf("Never Mind\n");
	else 
	{ dfs(id1,0);
	  if(check(id2,0)) printf("Yes\n");
	  else printf("No\n");
	}	
  }	
  return 0;
}
