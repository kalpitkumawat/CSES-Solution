#include<bits/stdc++.h>
using namespace std;
#define ll long long
void dfs( int node ,vector<vector<int>> &adj, vector<int> &vis )
{
    vis[node]=1;
    for( auto it: adj[node])
    {
        if(!vis[it])
        dfs(it,adj,vis);
    }
    
}
int main()
{
                       
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                    
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj1(n+1),adj2(n+1);
    for( int i=0 ; i< m ; i++)
    {
        int x,y;
        cin>>x>>y;
        adj1[x].push_back(y);
        adj2[y].push_back(x);
    }
    vector<int> vis1(n+1),vis2(n+1);
    dfs(1,adj1,vis1);
    dfs(1,adj2,vis2);
    int x=0,y=0;
    bool found=false;
    for( int i=1 ; i<= n ; i++ )
    {

        if(vis1[i]==0)
        {
            x=i;
        }
        if( vis2[i]==0)
        y=i;
        if(!(vis1[i]==vis2[i] && vis1[i]==1))
        {
            found=true;
            // cout<<"NO\n";
        }
    }
    if(!found)
    {
        cout<<"YES\n"; 
    }
    else {
    cout<<"NO\n";
    if(x!=0 )
    cout<<1<<" "<<x<<endl;
    else cout<<y<<" "<<1<<endl;
    }
}