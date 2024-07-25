#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
ll m1 = 1e18, m2 = -1;

#define pii pair<ll, ll>
pair<ll, pair<ll, ll>> rec(ll node, vector<vector<pair<ll, ll>>> &adj, vector<pair<ll, pair<ll, ll>>> &dp, ll x,  vector<ll> &dis)
{
    if (node == 1 && x == 0 )
    {
        return {1, {0, 0}};
    }
    else if (x < 0)
        return {0, {1e18, -1e9}};
    if (dp[node].first != -1)
        return dp[node];
    ll k = 0;
    ll a = 1e18, b = -1e9;

    for (auto it : adj[node])
    {
        pair<ll, pair<ll, ll>> temp={0,{1e18,-1e9}};
        if(x-it.second==dis[it.first])
        temp = rec(it.first, adj, dp, x - it.second,dis);
        k = (k % mod + (temp.first) % mod) % mod;
        a = min(a, 1 + temp.second.first);
        b = max(b, 1 + temp.second.second);
    }
    return dp[node] = {k, {a, b}};
}
ll dikstra(ll n, vector<vector<pii>> &adj,vector<ll> &dis)
{

    dis[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll curdis = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if (curdis > dis[node])
            continue;
        for (auto it : adj[node])
        {
            ll newnode = it.first;
            ll extra = it.second;
            ll newdis = curdis + extra;
            if (dis[newnode] > newdis)
            {
                dis[newnode] = newdis;
                pq.push({newdis, newnode});
            }
        }
    }
    return dis[n];
}
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1), adj2(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[b].push_back({a, c});
        adj2[a].push_back({b, c});
    }
    vector<ll> dis(n + 1, 1e18);
    ll x = dikstra(n, adj2,dis);
    vector<pair<ll, pair<ll, ll>>> dp(n + 1, {-1, {-1, -1}});
    pair<ll, pair<ll, ll>> temp = rec(n, adj, dp, x,dis);
    cout << x << " ";
    cout << temp.first << " " << temp.second.first << " " << temp.second.second << endl;
}