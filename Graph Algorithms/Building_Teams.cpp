#include<bits/stdc++.h>
using namespace std;
bool dfs( int node,vector<vector<int>> &adj ,vector<int> &vis, int col,int prev  )
{
    vis[node]=col;
    for( auto it : adj[node])
    {
        if(!vis[it] )
        {
            if(!dfs(it,adj,vis,3-col,node)) return false;
        }
        else if( it!=prev && vis[it]==col)
        return false;
    }
    return true;

}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for( int i=0 ; i< m ;i++ )
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n+1);
    bool ans=true;
    for( int i=1 ; i<=n ;i++ )
    {
        if(!vis[i])
        if(!dfs(i,adj,vis,1,-1)) ans=false;
    }
    if( !ans )
    {
        cout<<"IMPOSSIBLE\n";
    }
    else {
        for( int i=1 ; i<= n ; i ++ )
        cout<<vis[i]<<" ";
    }
}