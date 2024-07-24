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


ll power(ll x, ll y, ll p){
    ll res = 1;x = x % p;while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;
}
ll modInverse(ll n, ll p){
    return power(n, p - 2, p);
}

ll mod = 998244353;
void solve()
{
    ll K; cin >> K;
    vector<ll> fre(27, 0);
    for(ll i=1;i<=26;i++){
        cin >> fre[i];
    }
    vector<ll> fac(K+1);
    fac[0] = 1;for (ll i = 1; i <= K; i++){fac[i] = fac[i - 1] * i % mod;}

    vector<ll> inv(K+1);
    inv[K] = modInverse(fac[K], mod);
    for (ll i = K-1; i >= 0; i--){inv[i] = (inv[i+1] * (i + 1)) % mod;}


    ll ans = 0;
    vector<vector<ll>> ncr(K + 1, vector<ll>(K + 1, 0));
    for (ll i = 0; i <= K; i++) {
        ncr[i][0] = 1;
        for (ll j = 1; j <= i; j++) {
            ncr[i][j] = (ncr[i][j-1] * fac[j-1]) % mod;
            (ncr[i][j] *= fac[i - j + 1]) %= mod;
            (ncr[i][j] *= inv[j]) %= mod;
            (ncr[i][j] *= inv[i-j]) %= mod;
        }
    }

    vector<vector<ll>> dp(27, vector<ll>(K + 1, 0));
    dp[0][0] = 1;
    for (ll i = 1; i <= 26; i++) {
        for (ll j = 0; j <= fre[i]; j++) {
            for (ll len = 0; len <= K - j; len++) {
                (dp[i][len+j] += dp[i-1][len] * ncr[len+j][j]) %= mod;
            }
        }
    }
    for(ll i=1;i<=K;i++){
        (ans += dp[26][i]) %= mod;
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // sieve(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}