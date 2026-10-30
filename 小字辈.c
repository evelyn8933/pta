#include <stdio.h>
#define MAXN 100001

int parent[MAXN];
int depth[MAXN];

int get_depth(int x)
{
    if(depth[x] != 0)
        return depth[x];
    int path[MAXN];
    int cnt = 0;
    int cur = x;
    // 向上爬，收集路径，直到找到已经算好深度的点
    while(cur != -1 && depth[cur] == 0)
    {
        path[cnt++] = cur;
        cur = parent[cur];
    }
    int d = depth[cur];
    // 回填路径上所有点的深度
    for(int i = cnt - 1; i >= 0; i--)
    {
        d++;
        depth[path[i]] = d;
    }
    return depth[x];
}

int cmp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int n,root=-1;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&parent[i]);
        if(parent[i]==-1)
        {
            root = i;
            depth[i]=1;
        }
    }
    int maxd = 1;
    for(int i = 1; i <= n; i++)
    {
        get_depth(i);
        if(depth[i] > maxd)
            maxd = depth[i];
    }
    int ans[MAXN],k=0;
    for(int i=1;i<=n;i++)
    {
        if(depth[i]==maxd)
            ans[k++]=i;
    }
    qsort(ans,k,sizeof(int),cmp);
    printf("%d\n",maxd);
    for(int i=0;i<k;i++)
    {
        if(i>0) printf(" ");
        printf("%d",ans[i]);
    }
    return 0;
}

