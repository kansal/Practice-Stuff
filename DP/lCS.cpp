#include<algorithm>
#include<vector>
#include<cstring>
#include<string.h>
#include<iostream>

using namespace std;

int table[1000][1000];

int lcs(const string& a,const string& b)
{
    if(a.size()== 0 || b.size() == 0)
        table[a.size()][b.size()]=0;
    else
    {
        if(*a.rbegin()==*b.rbegin())
            table[a.size()][b.size()]=1+lcs(a.substr(0,a.size()-1),b.substr(0,b.size()-1));
        else
            table[a.size()][b.size()]=max(lcs(a.substr(0,a.size()),b.substr(0,b.size()-1)),lcs(a.substr(0,a.size()-1),b.substr(0,b.size())));

    }
    return table[a.size()][b.size()];
}
int main()
{
    int n;
    memset(table,-1,sizeof(table));
    string a,b;
    cin>>a>>b;
    lcs(a,b);
    cout<<table[a.size()][b.size()];
}
