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

void solve()
{
    ll mod = 998244353;
    ll num; cin >> num;
    ll temp = num;
    ll d = 0;
    while(temp){
        temp /= 10;
        d++;
    }
    vector<ll> arr(61, num % mod);
    for (ll i = 1; i < 61; ++i) {
        arr[i] = (arr[i - 1] * power(10, d * (1LL << (i - 1)), mod)) % mod;
        arr[i] = (arr[i] + arr[i - 1]) % mod;
    }

    ll result = 0;
    for (ll bit = 60; bit >= 0; --bit) {
        if (num & (1LL << bit)) {
            num ^= (1LL << bit);
            result = (result + (arr[bit] * power(10, d * num, mod)) % mod) % mod;
        }
    }

    cout << result << '\n';
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
