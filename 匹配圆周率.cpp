#include <iostream>
#include <string>
using namespace std;
void get_next(string pat, int next[])
{    
    int m = pat.size();    // m：模式串pat总长度
    next[0] = -1;          // next[0]固定为-1，标记需要主串i右移
    int i = 0, j = -1;     // i:后缀指针，j:前缀指针
    while(i < m - 1)       // i最多到 m-2，因为循环里会i++，最后填next[m-1]
    {            
        if(j == -1 || pat[i] == pat[j])             
        {                     
            i++;                     
            j++;                     
            next[i] = j;  // next[i]表示pat[0~i-1]的最长相等前后缀长度
        }            
        else            
        {                  
            j = next[j]; // 不匹配，j回退，KMP核心
        }    
    }
}

int kmp(string mains,string son)
{ 
    int len=mains.size(),m=son.size();
	int *next=new int[m];
	get_next(son,next); 
	int start=0;
	int i=0,j=0; 
	while(i<len&&j<m)
	{ if(j==-1||mains[i]==son[j])
	     { i++;
	       j++;
		 }
	  else 
	  {
	  j=next[j];//更新是怎么更新的 
	  start=i;
      }  
	}
	delete []next; 
	if(j==m) return start;
	else return -1;
}
int main()
{ string s,t;
  cin>>s>>t; 
  int a=kmp(s,t);
  cout<<a+1;	
}
