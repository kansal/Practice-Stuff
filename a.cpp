#include<iostream>
#include<vector>
using namespace std;
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
int main()
{
    vector <int> a(10,1);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    if(a.empty())
        cout<<"hello"<<endl;
    else
        cout<<"bye"<<a.size()<<endl;
    vector < vector <int> > mat(10,vector<int>(10,-1));
    mat[0].push_back(1);
    cout<<mat[0].size();
    int data[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 }; 
    vector<int> primes(data, data+(sizeof(data) / sizeof(data[0]))); 
    cout<<"---"<<primes.size()<<endl;
    cout<<primes[0]<<endl;
    cout<<primes[1]<<endl;
    cout<<primes[2]<<endl;
    cout<<primes[3]<<endl;
    cout<<*primes.rend()+1;
    string str;
    str="kshitij";
    cout<<endl<<str.size()<<"-------"<<endl;
    return 0;

}
