#include <bits/stdc++.h>

using namespace std;

bool visited[10000]={false};

void DFS(vector<int> adj[], int s){


       visited[s]=true;

       cout<<s<<" ";


       for(int i=0;i<adj[s].size();i++){
        if(!visited[adj[s][i]])
            DFS(adj,adj[s][i]);
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
    cout<<"DFS: "<<endl;
    DFS(adj, q);
    return 0;
}
