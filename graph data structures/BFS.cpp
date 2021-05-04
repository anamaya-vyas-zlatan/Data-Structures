#include <bits/stdc++.h>

using namespace std;

void BFS(vector<int>adj[],int s,int n)
{
    bool visited[n]={false};

    queue<int> q;
    visited[s]=true;
    q.push(s);

    while(!q.empty()){
        int t=q.front();
        q.pop();

        cout<<t<<" ";

        for(int i=0;i<adj[t].size();i++){
            if(!visited[adj[t][i]]){
                visited[adj[t][i]]=true;
                q.push(adj[t][i]);
            }
        }
    }

}

int main()
{
    int n;
    cout<<"Enter number of vertices: ";
    cin>>n;
    vector<int> adj[n];
    int e;
    cout<<"Enter number of edges: ";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        a:int temp1,temp2;
        cout<<"Enter source and destination: ";
        cin>>temp1>>temp2;
        if(temp1>=n || temp2>=n){
            cout<<"Error"<<endl;
            goto a;
        }
        adj[temp1].push_back(temp2);
    }
    cout<<"Enter source: ";
    int q;
    cin>>q;
    cout<<"BFS: "<<endl;
    BFS(adj,q,n);

    return 0;
}
