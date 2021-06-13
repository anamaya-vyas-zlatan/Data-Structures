#include<bits/stdc++.h>
using namespace std;

int sumcalc(int arr[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum +=arr[i];
    }
    return sum;
}



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
    int range = sumcalc(arr,n);

    int t[n+1][range+1];

    // dp


    //initialization
    for(int i=1;i<=range;i++)
        t[0][i] = 0;
    for(int i=0;i<=n;i++)
        t[i][0]=1;

    //logic
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=range;j++)
        {
            if(j<arr[i-1])
            {
                t[i][j] = t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
            }
        }
    }
    vector<int> a;
    for(int i=0;i<=range/2;i++)
        if(t[n][i] == 1)
        {
            a.push_back(i);
        }
    int mini = INT_MAX;
    for(auto& it : a)
    {
        int l;
        l = range - 2*it;
        mini = min(mini, l);
    }
    cout<<mini<<endl;;
   for(int i=0;i<n;i++)
        {for(int j=0;j<range;j++)
    {
        cout<<t[i][j]<<" ";
    }
       cout<<"\n"; }
}
