#include<bits/stdc++.h>
using namespace std;

int main()
{
    string x,y;
    cout<<"Enter string a: ";
    cin>>x;
    cout<<"Enter string b: ";
    cin>>y;
    int n, m;
    n = x.length();
    m = y.length();
    int t[n+1][m+1];

    // base condition or initialization
    for(int i=0;i<=m;i++)
        t[0][i] =0;
    for(int i=0;i<=n;i++)
        t[i][0] = 0;

    //code
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
                t[i][j] = 1+ t[i-1][j-1];
            else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }
    int ans = t[n][m];
    cout<<ans;
}
