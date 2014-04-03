#include<iostream>
#include<algorithm>
#include<string.h>
#define R 1
#define D 1
#define I 1
using namespace std;

int edit(const string& a,const string& b)
{
	if(a.size()==0)
		return b.size();
	else if(b.size()==0)
		return a.size();
	else if(*a.rbegin() == *b.rbegin())
		return (edit(a.substr(0,a.size()-1),b.substr(0,b.size()-1)));
	else
	{
		int temp= min(edit(a.substr(0,a.size()-1),b.substr(0,b.size()-1))+R ,edit(a.substr(0,a.size()-1),b.substr(0,b.size()))+I);
		return min(temp,edit(a.substr(0,a.size()),b.substr(0,b.size()-1))+D);
	}

}
int main()
{
	string a,b;
	cin>>a>>b;
	cout<<edit(a,b)<<endl;
}
