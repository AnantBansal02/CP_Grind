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
ll extendedGCD(ll a, ll b, ll *x, ll *y)
{
    if (b == 0){
        *x = 1;
        *y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extendedGCD(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

ll modInverseGCD(ll a, ll m)
{
    // return square_and_multiply(a, m-2, m);
    ll x, y;
    ll gcd = extendedGCD(a, m, &x, &y);
    if (gcd != 1){
        return -1;
    }
    return (x % m + m) % m;
}
void solve()
{
    cout<<modInverseGCD(13, 1e9+8)<<"\n";
    cout<<modInverse(13, 1e9+8)<<"\n";
    ll mod = 1e9 + 8;
    cout<<(modInverseGCD(13, 1e9+8)*13)%mod<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}