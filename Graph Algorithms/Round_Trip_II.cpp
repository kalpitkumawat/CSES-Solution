#include<bits/stdc++.h>
using namespace std;
bool dfs( int node ,vector<vector<int>> &adj , vector<int> &vis , vector<int> &hash , int prev ,int &start)
{
    vis[node]=2;
    for( auto it: adj[node])
    {
        if(!vis[it])
        {
            hash[it]=node;
            if(dfs(it,adj,vis,hash,node,start)) return true;
        }
        else if ( vis[it]==2 )
        {   
            hash[it]=node;
            start=it;
            return true;
        }
    }
    vis[node]=1;
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for( int i=0 ; i< m ; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> vis(n+1),hash(n+1);
    vector<int> ans;
    bool found=false;
    for( int i=1 ; i<= n ; i++ )
    {
        if(!vis[i])
        {   int start=0;
            if(dfs(i,adj,vis,hash,-1,start))
            {
                int j=start;
                ans.push_back(start);
                while( hash[j]!=start)
                {
                    ans.push_back(hash[j]);
                    j=hash[j];
                }
                found=true;
                ans.push_back(start);
                break;
            }
        }
    }
    if( found)
    {
        cout<<ans.size()<<"\n";
        for( int i=ans.size()-1 ; i>= 0 ; i--)
        {
            cout<<ans[i]<<" ";
        }
    }
    else cout<<"IMPOSSIBLE\n";



}