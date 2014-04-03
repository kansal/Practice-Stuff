#include<iostream>
#include<vector>
#include<string.h>
#include<cstring>

using namespace std;

int main()
{
    vector<int>v(10);
    for(int i=0;i<10;i++)
        v[i]=i+1;
    for(int i=0;i<v.size();i++)
    {
        vector<int>t=v;
        v.erase(v.begin()+i);
        for(int j=0;j<v.size();j++)
            cout<<v[j]<<" ";
        v=t;
        cout<<endl;
    }

}
