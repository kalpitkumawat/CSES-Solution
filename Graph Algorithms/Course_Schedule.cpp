#include<bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll> 
#define ll long long
void dfs(int node, vector<vector<int>> &adj ,vector<int > &vis, stack<int> &st)
{
    vis[node]=2;
    for( auto &it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,st);
        }
        else if( vis[it]==2)
        return;
    }
    vis[node]=1;
    st.push(node);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for( int i=0  ;i<  m ; i++ )
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int> vis(n+1);
    stack<int> st;
    for( int i=1 ;i<= n ;i++ )
    {
        if(!vis[i])
        dfs(i,adj,vis,st);
    }
    if(st.size()==n)
    {
        while(!st.empty())
        {
            cout<<st.top()<<" "; st.pop();
        }
    }
    else cout<<"IMPOSSIBLE\n";

}