#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    typedef  vector <int> int1D;
    typedef vector <int1D> int2D;
    typedef vector <int2D > int3D;
    int3D a (10,int2D(10, int1D(10)));
    cout<<a.size()<<endl;
    return 0;
}
