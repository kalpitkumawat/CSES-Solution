#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for( ll i=0 ; i< m ;i++ )
    {
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    priority_queue< pii , vector<pii> , greater<pii> > pq;
    pq.push({0,1});
    vector<ll> vis(n+1,0);
    ll ans=0;
    while (!pq.empty())
    {
        ll d=pq.top().first;
        ll node=pq.top().second;
        pq.pop();
        if(vis[node]==1)
        continue;
        vis[node]=1;
        ans+=d;
        for( auto &it : adj[ node ])
        {
            if(!vis[it.first])
            {
                pq.push({it.second,it.first});
            }
        }
    }
    bool found=true;
    for( ll i=1 ; i<= n ; i++ )
    {
        if(!vis[i]) found=false;
    }
    if(found)
    cout<<ans<<endl;
    else cout<<"IMPOSSIBLE\n";
    
}