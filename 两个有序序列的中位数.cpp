#include <stdio.h>
#include <stdlib.h>
int num1[100001];
int num2[100001];
int num[200006];
int main()
{  int n;
scanf("%d",&n);
for(int i=0;i<n;i++)
 { scanf("%d",&num1[i]);
 }
for(int i=0;i<n;i++)
 { scanf("%d",&num2[i]);
 }
int index=0;
int i=0,j=0;
for(;i<n&&j<n;)
{  
   if(num1[i]<num2[j])
     {
      num[index++]=num1[i++];
     }
	else if(num1[i]>num2[j])
	{
	 num[index++]=num2[j++];
	} 
	else
	{num[index++]=num1[i];
	i++;
	j++;
	}
}
while(i<n)
{num[index++]=num1[i++];
}
while(j<n)
{num[index++]=num2[j++];
}
index--;
printf("%d",num[(index)/2]);
return 0;
}
