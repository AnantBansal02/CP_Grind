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
    ll mod = 1e9 + 7;
    ll m,n;cin>>m>>n;
    vector<ll> s(m), l(m);
    for(auto &it : s){
        cin>>it;
    }
    for(auto &it : l){
        cin>>it;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(m, 0));
    dp[0][0] = 1;
    for(ll i=1;i<=n;i++){
        for(ll k=0;k<m;k++){
            for(ll j=0;j<m;j++){
                (dp[i][j] += dp[i-1][k]*(s[k]*(s[j] + l[j]) + l[k]*(s[j]))) %= mod;
            }
        }
    }
    ll ans = 0;
    for(ll i=0;i<m;i++){
        (ans += dp[n][i]) %= mod;
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
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}