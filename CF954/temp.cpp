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
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    ll ans = 0, mod = 1e9 + 7;
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, -1));
    function<ll(ll, ll)> fun = [&] (ll i, ll left) -> ll {
        if(left < 0){
            return 0;
        }
        if(left == 0){
            return power(2, n - i, mod);
        }
        if(i == n){
            return 0;
        }
        if(dp[i][left] != -1){
            return dp[i][left];
        }
        ll ans = 0;
        (ans += fun(i+1, left - arr[i])) %= mod;
        (ans += fun(i+1, left)) %= mod;

        return dp[i][left] = ans;

    };
    for(ll i = 0; i < n; i++){
        ll curr = 0;
        (curr += fun(i + 1, k - arr[i])) %= mod;
        (curr *= power(2, i, mod)) %= mod;
        (ans += curr) %= mod;
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
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}