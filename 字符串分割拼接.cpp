#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{ string origin,s;
  char p;
  getline(cin,origin);
  cin>>p;
  cin.ignore();
  getline(cin,s);
  vector <string> sum;
  string cur;
  int index=0,len=origin.size();
  vector<int> pdex;
  for(int i=0;i<len;i++)
  {
  	char curcha;
  	curcha=origin[i];
  	if(curcha==p)
  	{ if(cur.size()!=0)
	   {
	   sum.push_back(cur);
	   index++;
	   }
	   pdex.push_back(index); 
	   cur.clear();
	}
	else
	{
		cur+=curcha;
	}
  }
if(origin[len-1]!=p) sum.push_back(cur);  
  cout<<"[";
int j=0;
	for(int i=0;i<sum.size();i++)
	{ if(i) cout<<' ';
	cout<<'"'<<sum[i]<<'"';
	if(i!=sum.size()-1) cout<<',';
	if(j<pdex.size()&&i+1==pdex[j++]) 
	 { if(j!=0) cout<<" ";
	   cout<<'"';
	   cout<<'"';
	   if(i!=sum.size()-1) cout<<',' ;
     }
	}
	cout<<"]"<<endl; 
	for(int i=0,j=0;i<sum.size();i++)
	{ if(i) cout<<' ';
	      cout<<sum[i];
	   if(j<pdex.size()&&i+1==pdex[j++]) 
	     { if(j!=0) cout<<' ';
	       if(i!=sum.size()-1) 
	       {cout<<s<<' '<<s;
		   }
	       else cout<<s;
         }
	}	
 } 
