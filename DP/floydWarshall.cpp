#include<algorithm>
#include<vector>
#include<iostream>

#define INF 9999;
using namespace std;
int mat[100][100];
int dist[100][100];
void floydWarshall(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(mat[i][j] > mat[i][k]+mat[k][j])
                    mat[i][j]=mat[i][k]+mat[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    floydWarshall(n);
    return 0;
}
