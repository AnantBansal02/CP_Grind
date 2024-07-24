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

ll mod = 1e9 + 7;

void solve()
{
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    ll alice = 0, bob = 0;
    ll ns = n - k;
    ll sum = 0;
    for(ll i = 0; i < k; i++){
        sum += arr[i];
    }
    (alice += (ns + 2)/2* sum) %= mod;
    (alice *= modInverse(ns + 1, mod)) %= mod;
    (bob += (ns + 1)/2* sum) %= mod;
    (bob *= modInverse(ns + 1, mod)) %= mod;
    sum = 0;
    for(ll i = k; i < n; i++){
        sum += arr[i];
    }
    ll a = 0, b = 0;
    (a += (ns + 1)/2* sum) %= mod;
    (a *= modInverse(ns, mod)) %= mod;
    (b += (ns)/2* sum) %= mod;
    (b *= modInverse(ns, mod)) %= mod;
    (alice += a) %= mod;
    (bob += b) %= mod;
    cout << alice << " " << bob << "\n";
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