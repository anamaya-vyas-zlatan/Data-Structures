#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n, diff;
    cout<<"Enter difference: ";
    cin>>diff;
    cout<<"Enter number of terms: ";
    cin>>n;
    int arr[n];
    int sum=0;
    cout<<"Enter the array elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum = sum+arr[i];
    }
    int ans;
    ans = (sum + diff)/2;

    //count of no of subset sum problems with the given sum
        int t[n+1][ans+1];

    //initializtion
    for(int i=0;i<=n;i++)
        t[i][0] = 1;
    for(int i=1;i<=ans;i++)
        t[0][i] = 0;

    //choice diagram
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=ans;j++)
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
    cout<<t[n][ans];

}
