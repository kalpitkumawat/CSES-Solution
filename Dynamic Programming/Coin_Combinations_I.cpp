#include <bits/stdc++.h>
 
using namespace std;
using namespace chrono;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds; 
 
 
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define pneg cout << "-1" << endl
 
#define MOD 998244353
#define INF 1e18
#define N 100005
#define prDouble(x, y) cout << fixed << setprecision(y) << x
#define bitcount(x) __builtin_popcount(x)
#define ll long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define eb emplace_back
#define forw(i, j, n) for (ll i = j; i < n; i++)
#define bac(i, j, n) for (ll i = j - 1; i >= n; i--)
#define all(x) x.begin(), x.end()
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define sz(x) ((int)(x).size())
#define in(arr, n) forw(i , 0 , n) cin >> arr[i];
#define out(arr,n) forw(i,0,n) cout<<arr[i]<<" "; cout<<endl; 
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvld;
typedef vector<pll> vpll;
typedef priority_queue<ll> mxpq;
typedef priority_queue<ll, vll, greater<ll>> mnpq;
#define mii map<int,int>
#define mll map<ll,ll>
// typedef __int128 lll;
 
#define MPI 3.14159265358979323846
#define F first
#define S second
 
//#define ordered_set tree<ll, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//typedef tree<pair<ll,ll>, null_type,  less<pair<ll,ll>>, rb_tree_tag,  tree_order_statistics_node_update> ordered_set_pair; 
 
ll mod = 1e9 + 7;
vll facvec(ll n) 
{  // RETURNS VECTOR OF ALL THE FACTORS
    vll v;
    // Note that this loop runs till square root 
    for (ll i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                v.pb(i); 
  
            else // Otherwise print both 
                {   v.pb(i);  v.pb(n/i); } 
        } 
    } 
sort(all(v)); 
    return v;
} 
 
void pfarr(int n, mll &factorization) 
{
 // Prime factorisation of complete array 

    // Instead of cout, update the map with the prime factors
    while (n % 2 == 0) 
    { 
        factorization[2]++;
        n = n/2; 
    }

    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while (n % i == 0) 
        { 
            factorization[i]++;
            n = n/i; 
        } 
    } 

    if (n > 2) 
        factorization[n]++;
}
vector<ll> dtb(ll n) 
{ 
        vll v;
    // Size of an lleger is assumed to be 32 bits 
    for (ll i = 31; i >= 0; i--) { 
        ll k = n >> i;
        if (k & 1) 
            v.pb(1); 
        else
            v.pb(0); 
    } 
    return v;
}  
 
ll bs_sqrt(ll x) {
  ll left = 0, right = 2000000123;
  while (right > left) {
      ll mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
} 
#define ll long long
ll dp[1000001];
void solve()
{
 
   ll n,m;
   ll mod=1e9+7;
   cin>>n>>m;
   ll a[n];
   in(a,n);
   sort(a,a+n);
   dp[0]=1;
   for( ll i=1 ; i<= m ; i++ )
   {
    
    for( ll j=0 ; j<n ; j++ )
    {   if(i-a[j]<0) break;
        dp[i]+=dp[i-a[j]];
    }
    dp[i]%=mod;
   }
   cout<<dp[m];    
}
 

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("Error.txt", "w", stderr);
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    // init();
    fastio();
     solve();
    return 0;
}