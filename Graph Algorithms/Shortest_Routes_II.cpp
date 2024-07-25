#include<bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll> 
#define ll long long
int main()
{
     ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<pii>> adj(n+1);
    vector<vector<ll>> dis(n+1,vector<ll> (n+1,1e15));
    for( ll i=0 ; i< m ;i++ )
    {
        ll x,y,z;
        cin>>x>>y>>z;
        dis[x][y]=min(dis[x][y],z);
        dis[y][x]=min(dis[y][x],z);
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    for( int i=1 ; i<n+1 ; i++ )
    dis[i][i]=0;
    for( int k=1 ; k<= n ; k++ )
    {
        for( int i=1 ; i<=n ; i++ )
        {
            for( int j=1 ; j<=n ; j++ )
            {
                ll ok=dis[i][k]+dis[k][j];
                if(ok<dis[i][j])
                dis[i][j]=ok;
            }
        }
    }

    for( ll i=0; i< q; i++ )
    {
        ll x,y;
        cin>>x>>y;
        ll ko=dis[x][y]==1e15  ? -1 : dis[x][y];
        cout<<ko<<endl;
    }

}