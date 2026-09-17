#include <stdio.h>
int num1[100001];
int num2[100001];
int num[200006];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num1[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num2[i]);
    }
    int index = 0;
    int i = 0, j = 0;
    while(i < n && j < n)
    {
        if(num1[i] < num2[j])
        {
            num[index++] = num1[i];
            // 跳过num1所有和当前值相等的重复元素
            int val = num1[i];
            while(i < n && num1[i] == val)
                i++;
        }
        else if(num1[i] > num2[j])
        {
            num[index++] = num2[j];
            int val = num2[j];
            while(j < n && num2[j] == val)
                j++;
        }
        else // num1[i]==num2[j]
        {
            num[index++] = num1[i];
            int val = num1[i];
            //两边都跳过所有相同值
            while(i < n && num1[i] == val)
                i++;
            while(j < n && num2[j] == val)
                j++;
        }
    }
    //处理剩下的num1，继续去重
    while(i < n)
    {
        int val = num1[i];
        num[index++] = val;
        while(i < n && num1[i] == val)
            i++;
    }
    //处理剩下的num2，继续去重
    while(j < n)
    {
        int val = num2[j];
        num[index++] = val;
        while(j < n && num2[j] == val)
            j++;
    }
    // index等于并集总长度L
    index--;
    printf("%d", num[index / 2]);
    return 0;
}

