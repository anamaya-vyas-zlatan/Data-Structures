#include<bits/stdc++.h>
using namespace std;

static int t[1001][1001];

int LCS(string x, string y, int n, int m)
{
    //base condition
    if(n==0 || m==0)
        return 0;

    //return type
    if(t[n][m] != -1)
        return t[n][m];

    if(x[n-1] == y[m-1])
    {
        return t[n][m] = 1+ LCS(x,y,n-1,m-1);
    }
    else{
        return t[n][m] = max(LCS(x,y,n-1,m), LCS(x,y,n,m-1));
    }
}


int main()
{
    memset(t, -1, sizeof(t));
    string x,y;
    cout<<"Enter string a: ";
    cin>>x;
    cout<<"Enter string b: ";
    cin>>y;
    int n, m;
    n = x.length();
    m = y.length();
    int ans = LCS(x,y,n,m);
    cout<<ans;
    return 0;
}
