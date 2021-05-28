#include<bits/stdc++.h>
using namespace std;
int t[102][1002];
//n,W matrix where n is number of elements in the array and W is the max Weight of the knasack

knapsack(int wt[], int val[], int W, int n)
{
    //base condition
    if(n==0 || W==0)
        return 0;
    // if the array entries i.e number of items are 0 profit is zero
    //also if the maximum capacity of the knapsack is 0 the profit is 0

    if(t[n][W] != -1)
        return t[n][W];
    //memoization of the function i.e if we have ccalculated knapsack for n,W
    //recursion will end with the ans, if we have stored it earlier we can use it.

    /*starting from last*/
    if(wt[n-1]<=W)
    {
        return t[n][W] = max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
        //if we select the n-1 value then it would be added to the knapsack profit,
        //so weight will be deducted from W and if we dont select it
        //weight wont be decucted
    }

    // if weight of the object is greater than W there is no need to add so we pass on to the next value
    if(wt[n-1]>W)
    {
        return t[n][W] = knapsack(wt, val,W,n-1);
    }
}
int main()
{
    //initialize the matrix with -1
    memset(t , -1, sizeof(t));
    int n,W;
    cout<<"Enter number of enteries: ";
    cin>>n;
    cout<<"Enter the maximum weight of the knapsack: ";
    cin>>W;
    int arr[n],brr[n];
    cout<<"Enter the weights: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter their respective prices: ";
    for(int i=0;i<n;i++)
    {
        cin>>brr[i];
    }
    int x = knapsack(arr,brr,W,n);
    cout<<"max profit = ";
    cout<<x;
    return 0;
}
