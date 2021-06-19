#include<bits/stdc++.h>
#include<string>
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

    //base condition or initialization
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j] = 0;
            }
            else if(x[i-1]==y[j-1]){
                t[i][j] = 1+t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    int i=n; int j= m;
    string s = "";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1])
        {
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j])
            {
                j--;
            }
            else{
                i--;
            }
        }
    }
    int len = s.length();
    for(int i=len-1;i>=0;i--)
    {
        cout<<s[i];
    }


}
