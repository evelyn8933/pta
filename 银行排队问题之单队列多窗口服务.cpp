#include <stdio.h>
int main()
{   int n,arrive[1001],process[1001];
scanf("%d",&n);
for(int i=0;i<n;i++)
{
	scanf("%d %d",&arrive[i],&process[i]);
	if(process[i]>60) process[i]=60;
}
int k;
scanf("%d",&k);
double average;
int sumwait=0,maxwait=0,maxend=0;
int endtime[1001]={0},cnt[1001]={0};
for(int i=0;i<n;i++)
{   int flag=0;
	int t=arrive[i];
	int p=process[i];
	int mintime=endtime[0],mink=0;
	for(int j=0;j<k;j++)
	{ if(endtime[j]<=t) 
	    {  	endtime[j]=t+p;
	    	cnt[j]++;
	    	flag=1;
	    	break;
		}
	  if(endtime[j]<mintime)  
	  {
	  	mintime=endtime[j];
	  	mink=j;
	  }  
	}
	if(flag==0)
	{
		int waittime=mintime-t;
		sumwait+=waittime;
		if(waittime>maxwait) maxwait=waittime;
		endtime[mink]+=p;
		cnt[mink]++;
	}
}
for(int j=0;j<k;j++)
{
	if(endtime[j]>maxend) maxend=endtime[j];
 } 
average=((double)sumwait)/n;
printf("%.1lf %d %d\n",average,maxwait,maxend);
for(int i=0;i<k;i++)
{
	printf("%d",cnt[i]);
	if(i<k-1) printf(" ");
}
	return 0;
}
