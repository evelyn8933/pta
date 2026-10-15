#include <iostream>
#include <string>
using namespace std;
int check(string str,string index)
{
	int len1=str.size(),len2=index.size();
	int max= len1>len2?len2:len1;
	while(max>0)
	{
		string cur1,cur2;
		cur1=str.substr(len1-max,max);
		cur2=index.substr(0,max);
		if(cur1.compare(cur2)==0) return max;
		max--;
	}
	return 0;
}
int main()
{
	string pass,s1,s2;
	cin>>pass>>s1>>s2;
	int ss1=check(pass,s1);
	int ss2=check(pass,s2);
	cout<<ss1<<' '<<ss2;
	
 } 
