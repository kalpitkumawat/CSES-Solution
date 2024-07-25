#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int rec( int node ,vector<vector<int>> &adj ,vector<int> &dp )
{
    if(node==1)
    return 1;
    if(dp[node]!=-1)
    return dp[node];
    int k=0;
    for( auto it: adj[node])
    {
        k=(k%mod+rec(it,adj,dp)%mod)%mod;
    }
    return dp[node]=k;
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
        adj[b].push_back(a);
    }
    vector<int> dp(n+1,-1);
    int k=rec( n,adj,dp);
    cout<<k<<endl;


}