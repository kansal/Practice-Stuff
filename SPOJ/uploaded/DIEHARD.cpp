#include<iostream>
#include<string.h>
using namespace std;
int table[2001][2001][3];
int func(int H, int A, int ch)
{
    if(ch==0)
    {
        H+=3;A+=2;
        if(H<=0||A<=0)
            return 0;
        if(table[H][A][ch]!=-1)
            return table[H][A][ch];
        else
        {
            table[H][A][ch]= max(func(H,A,1),func(H,A,2))+1;
            return table[H][A][ch];
        }
    }
    if(ch==1)
    {
        H-=5;A-=10;
        if(H<=0||A<=0)
            return 0;
        if(table[H][A][ch]!=-1)
            return table[H][A][ch];
        else
        {
            table[H][A][ch]= max(func(H,A,0),func(H,A,2))+1;
            return table[H][A][ch];
        }
    }
    if(ch==2)
    {
        H-=20;A+=5;
        if(H<=0||A<=0)
            return 0;
        if(table[H][A][ch]!=-1)
            return table[H][A][ch];
        else
        {
            table[H][A][ch]= max(func(H,A,0),func(H,A,1))+1;
            return table[H][A][ch];
        }
    }

}

int main()
{
    int tc,H,A;
    cin>>tc;
    while(tc)
    {
        memset(table,-1,sizeof(table));
        cin>>H>>A;
        int a=max(func(H,A,0),max(func(H,A,1),func(H,A,2)));
        cout<<a<<endl;
        tc--;
    }
    return 0;
}
