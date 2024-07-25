#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
                       
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                    
    cout.tie(NULL);
    ll n, q; 
    cin>>n>> q;
    // ll a[n];
    ll dp[n][30];
    for( ll i=0 ; i< n ; i++ )
    { ll x; cin>>x;  dp[i][0]=x-1; }

    for( ll i= 1 ;i< 30 ; i++ )
    {
        for( ll node=0 ; node< n ;node++ )
        {
            ll par=dp[node][i-1];
            dp[node][i]=dp[par][i-1];
        }
    }
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        x--; 
        ll i=0;
        while(y)
        {
            if(y&1)
            x=dp[x][i];
            i++;
            y=(y>>1);
        }
        cout<<x+1<<endl;
    }

}