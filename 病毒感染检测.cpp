#include <iostream>
#include <string>
#include <vector>
using namespace std;
void get_next(string pat, int next[])
{    
int m = pat.size();    
next[0] = -1;    
int i = 0, j = -1;    
while(i < m - 1)    
{        
    if(j == -1 || pat[i] == pat[j])        
     {            
         i++;            
         j++;            
         next[i] = j;        
     }        
    else        
    {            
      j = next[j];        
    }    
}
}
bool kmp(string mainstr,string second) 
{  int len1=mainstr.size(),len2=second.size();
   int *next=new int[len2];// 模式串长度 
   get_next(second, next);
	for(int i=0,j=0;i<len1;)
	 {  
	 	if(j==-1||mainstr[i]==second[j])
	 	 {
	 	 	i++;
	 	 	j++;
	 	 	if(j==len2) 
	 	 	return true;
		  }
		else 
		{ j=next[j];
		}
	 }
	 delete[]next; 
	 return false;
}
int main()
{  int n;
   cin>>n;
   for(int k=0;k<n;k++)
   { 
   string virus,person;
   cin>>virus>>person;
   int len=virus.size();
   virus+=virus;
   string cur;
   bool ok=false;
   for(int i=0;i<len;i++)//i到len就可以 防止溢出 
   {
   	cur=virus.substr(i,len); 
   	if(kmp(person,cur)) 
   	{  ok=true; 
   		break;
	}
   }
   if(ok==0) cout<<"NO"<<endl;
   else cout<<"YES"<<endl;
   virus.clear();
   person.clear();
   cur.clear();
  }
	return 0;
}
