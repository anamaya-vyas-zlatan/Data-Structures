#include<bits/stdc++.h>
using namespace std;
int t[1000][1000];
int esp(int sum,int n,int arr[])
{
    //initialization
    if(sum == 0)
        return 1;
    if(n==0)
        return 0;
    if(t[n-1][sum] != -1)
        return t[n-1][sum];

    if(sum<arr[n-1])
        return t[n-1][sum] = esp(sum,n-1,arr);
    else
        return t[n-1][sum] = esp(sum,n-1,arr)||esp(sum-arr[n-1],n-1,arr);
}
int main()
{
    memset(t, -1, sizeof(t));
     int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int s=0;
    for(int i=0;i<n;i++)
    {
        s = s+arr[i];
    }
    if(s%2 != 0)
    {
        cout<<"Not possible";
    }
    else{
            s= s/2;
        int x;
        x = esp(s,n,arr);
        if(x == 1)
            cout<<"Possible";
        else
            cout<<"Not possible";

    }
}
