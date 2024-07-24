#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout << #x << " = " << x << "\n"
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define all(x) (x).begin(), (x).end()
#define set_bits(x) __builtin_popcountll(x)

void solve()
{
    ll n,p,k;cin>>n>>p>>k;
    string s;cin>>s;
    vector<ll> dp(n+1, 0);
    for(ll i=n;i>=1;i--){
        if(s[i-1] == '0'){
            dp[i]++;
        }
        if(i + k <= n){
            dp[i] += dp[i+k];
        }
    }
    ll x,y;cin>>x>>y;
    ll ans = INF;
    for(ll i=p;i<=n;i++){
        ans = min(ans, (i - p) * y + (dp[i] * x));
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}