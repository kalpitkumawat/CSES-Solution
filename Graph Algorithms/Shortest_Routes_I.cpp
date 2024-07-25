#include<bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll> 
#define ll long long
int main()
{
     ll n,m;
    cin>>n>>m;
    vector<vector<pii>> adj(n+1);
    for( ll i=0 ; i< m ;i++ )
    {
        ll x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
    }
    vector<ll> dis(n+1,1e18);
    dis[1]=0;
    priority_queue< pii , vector<pii> , greater<pii> > pq;
    pq.push({0,1});
    while (!pq.empty())
    {
        ll curdis=pq.top().first;
        ll node=pq.top().second;
        pq.pop();
        if (curdis > dis[node]) continue;
        for( auto it: adj[node])
        {
            ll newnode=it.first;
            ll extra=it.second;
            ll newdis=curdis+extra;
            if(dis[newnode]>newdis)
            {
                dis[newnode]=newdis;
                pq.push({newdis,newnode});
            }
        }
    }
    for( ll i=1  ; i<= n ; i++ )
    {
        cout<<dis[i]<<" ";
    }
    
}