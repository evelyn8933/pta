#include <stdio.h>
int main(void)
{
    int N, p;
    scanf("%d%d", &N, &p);
    int arr[3001];
    int i;
    for(i=1; i<=N; i++)
        arr[i] = i;

    int remain = N;   // 当前还剩多少人
    int pos = 0;      // 当前位置
    int first = 1;

    while(remain > 0)
    {
        // 数p个活着的人，找到要删除的位置
        int step;
        for(step = 0; step < p; )
        {
            pos = pos + 1;
            if(pos > N) pos = 1;
            if(arr[pos] != 0) // 这个人还活着
                step++;
        }
        // pos就是本次出圈的人
        if(!first) printf(" ");
        printf("%d", arr[pos]);
        first = 0;
        arr[pos] = 0; //标记已出局
        remain--;
    }
    return 0;
}

