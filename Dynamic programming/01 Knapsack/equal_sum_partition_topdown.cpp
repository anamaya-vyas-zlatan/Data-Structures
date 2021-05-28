#include<bits/stdc++.h>
using namespace std;

int main()
{
      int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum = sum+arr[i];
    }
        int temp;
        temp = sum;
       sum =sum/2;
       int t[n+1][sum+1];
    if(temp%2 != 0)
    {
        cout<<"Not possible"<<endl;
    }
    else{
         //initialization
         for(int i=0;i<=sum;i++)
            t[0][i] = 1;
         for(int i=1;i<=n;i++)
            t[i][0] = 0;

         //choice diagram
         for(int i=1;i<n+1;i++)
         {
             for(int j=1;j<sum+1;j++)
             {
                 if(j<arr[i-1])
                    t[i][j] = t[i-1][j];
                 else
                    t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
             }
         }
         int q =t[n][sum];
         if(q == 1)
            cout<<"Possible";
         else
            cout<<"Not possible";
    }
}
