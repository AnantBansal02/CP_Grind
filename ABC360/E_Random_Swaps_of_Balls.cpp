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
vector<ll> fac;
void factorial(int n, int MOD){
    fac.resize(n + 1);fac[0] = 1;for (int i = 1; i < n; i++){fac[i] = fac[i - 1] * i % MOD;}
}
ll ncrmod(ll n, ll r, ll p){
    if (n < r)return 0;
    if (r == 0)return 1;
    return (((fac[n] * modInverse(fac[r], p)) % p) * modInverse(fac[n - r], p)) % p;
}

void solve()
{
    ll mod = 998244353;
    ll n, k; cin >> n >> k;
    ll p1 = 1LL, px = 0LL;
    ll x = modInverse(n, mod);
    ll y = (x * x) % mod;
    ll z = ((n - 1) * (n - 1)) % mod;
    for(ll i = 0; i < k; i++){
        ll p1_ = ((((p1 * z)%mod * y)%mod + (p1 * y)%mod)%mod + ((2LL * px * (n - 1))%mod * y)%mod)%mod;
        ll px_ = (((px * y)%mod + ((px * z)%mod * y)%mod)%mod + ((2LL * px * (n - 2))%mod * y)%mod)%mod;
        (px_ += ((2LL * p1)%mod * y)%mod) %= mod;
        p1 = p1_;
        px = px_;
        // dbg(p1);dbg(px);
    }
    ll ans = p1;
    ll sum = ((n * (n + 1))%mod * modInverse(2, mod))%mod;
    sum = (sum - 1LL + mod) % mod;
    // for(ll i = 2; i <= n; i++){
    //     (ans += (i * px) % mod) %= mod;
    // }
    (ans += (sum * px)%mod) %= mod;
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