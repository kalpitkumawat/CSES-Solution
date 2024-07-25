#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
        // adj[b].push_back({a,c});
        // Fuck it , Assumed it bidirectional :( 
    }
    vector<vector<ll>> dp(n+1 , vector<ll> (2,1e18));
    dp[1][0]=0 ;
    dp[1][1]=0;
    priority_queue< pair<pair<ll,ll>, ll> , vector<pair<pair<ll,ll>, ll>> , greater<pair<pair<ll,ll>, ll>> > pq;
    pq.push({{ 0,1 },0 });
    while(!pq.empty())
    {
        ll curdis=pq.top().first.first;
        ll node=pq.top().first.second;
        ll taken=pq.top().second;
        pq.pop();
        if(  taken==0 && curdis> dp[node][taken])
        continue;
        else if( taken==1 && curdis>dp[node][taken])
        continue;
        for( auto it : adj[node] )
        {
            ll exdis=it.second;
            ll newnode=it.first;
            if(curdis+exdis < dp[newnode][taken])
            {
                dp[newnode][taken]=curdis+exdis;
                pq.push({{curdis+exdis, newnode},taken});
 
            }
            if( !taken && curdis+exdis/2 < dp[newnode][1] )
            {
                dp[newnode][1]=curdis+exdis/2;
                pq.push({{curdis+exdis/2, newnode},1});
            }
        }
    }
    cout<<dp[n][1]<<endl;
}