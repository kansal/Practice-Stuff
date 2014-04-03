#include<algorithm>
#include<iostream>
#include<set>

using namespace std;

int main()
{
    set <int> S;
    S.insert(1);
    S.insert(2);
    S.insert(3);
    S.insert(4);
    S.insert(5);
    set<int >:: iterator it=S.find(3);
    set<int >:: iterator it1 = it;
    set<int >:: iterator it2 = it;
    it1--;
    it2++;
    int a=*it1;
    int b=*it2;
    cout<<a<<" "<<b<<" "<<endl;
}
