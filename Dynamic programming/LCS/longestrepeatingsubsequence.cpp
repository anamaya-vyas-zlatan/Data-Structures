#include<bits/stdc++.h>
using namespace std;
int main()
{
    string x,y;
    cout<<"Enter string a: ";
    cin>>x;y=x;
    int n, m;
    n = x.length();
    m =n;
    int t[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j] =0;
            }
            else if((x[i-1]==y[j-1]) && (i!=j))
            {
                t[i][j] = 1+t[i-1][j-1];
            }
            else{
                t[i][j]= max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    int ans = t[n][m];
    cout<<ans;
}
