#include<iostream>

using namespace std;

int main()
{
    int stack,count,k=0;
    string str;
    while(1)
    {
        k++;
        cin>>str;
        if(str[0]=='-')
            break;
        stack=0,count=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='{')
                stack++;
            else if(str[i]=='}')
                stack--;
            if(stack==-1)
            {
                stack=1;
                count++;
            }
        }
        count+=(stack/2);
        cout<<k<<". "<<count<<endl;
    }
    return 0;
}
