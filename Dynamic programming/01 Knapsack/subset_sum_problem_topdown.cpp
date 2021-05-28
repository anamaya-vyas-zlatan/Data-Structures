#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter sum: ";
    cin>>sum;
    int arr[n];
    cout<<"Enter array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int t[n+1][sum+1];

    //initiallization
    for(int i=1;i<=sum;i++)
    {
        t[0][i] = 0;
    }
    for(int i=0;i<=n;i++)
    {
        t[i][0] = 1;
    }

    //choice
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<arr[i-1])
            {
                t[i][j] = t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            }
        }
    }
    int x;
    x = t[n][sum];
    cout<<x;
    /*if(x == 1)
    {
        cout<<"Possible";
    }
    else{
        cout<<"Not possible";
    }*/
}
