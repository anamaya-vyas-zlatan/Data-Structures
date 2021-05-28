#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,W;
    cout<<"Enter max Weight of napsack: ";
    cin>>W;
    cout<<"Enter total entries: ";
    cin>>n;
    int t[n+1][W+1];
    memset(t, -1, sizeof(t));

    //initiallize
    for(int i=0;i<n+1;i++)
        for(int j=0;j<W+1;j++)
    {
        if(i==0 || j==0)
            t[i][j]=0;
    }
    int val[n],wt[n];
    cout<<"Enter the weights: ";
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    cout<<"Enter their respective prices: ";
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    for(int i=1;i<n+1;i++)
    for(int j=1;j<W+1;j++)
    {
        if(t[i-1][j]<=j)
        {
            t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
        }
        else
            t[i][j] = t[i-1][j];
    }
    cout<<"The max profit = ";
    cout<<t[n][W];
    return 0;
}
