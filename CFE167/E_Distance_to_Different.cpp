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


ll mod = 998244353;
void solve()
{
    ll n, k; cin >> n >> k;
    ll dp[n+1][k+1];
    memset(dp, 0, sizeof(dp));
    vector<ll> sum(k+1, 0);
    dp[0][0] = 1;
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[2][1] = 1;

    sum[0] = 1;
    sum[1] = 2;
    sum[2] = 1;

    for(ll i = 3; i <= n; i++){
        for(ll j = k; j >= 1; j--){
            (dp[i][j] += sum[j - 1] - dp[i - 2][j - 1] + mod) %= mod;
            if(j == k){
                (dp[i][j] += sum[k] - dp[i - 2][k] + mod) %= mod;
            }
            (sum[j] += dp[i][j]) %= mod;
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        (ans += dp[n - i][k]) %= mod;
        (ans += dp[n - i][k - 1]) %= mod;
    }
    cout << ans << "\n";
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