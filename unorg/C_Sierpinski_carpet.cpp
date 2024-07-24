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
    ll n; cin >> n;
    vector<vector<char>> ans(power(3, n, INF), vector<char>(power(3, n, INF)));
    function<void(ll, ll, ll)> fun = [&] (ll k, ll i, ll j) {
        if(k == 0){
            ans[i][j] = '#';
            return;
        }
        ll val = power(3, k-1, INF);
        for(ll row = i + val; row < i + 2 * val; row++){
            for(ll col = j + val; col < j + 2 * val; col++){
                ans[row][col] = '.';
            }
        }
        fun(k-1, i, j);
        fun(k-1, i+val, j);
        fun(k-1, i+2*val, j);
        fun(k-1, i, j+val);
        fun(k-1, i, j+2*val);
        fun(k-1, i+val, j+2*val);
        fun(k-1, i+2*val, j+2*val);
        fun(k-1, i+2*val, j+val);
    };
    fun(n, 0, 0);
    for(auto it : ans){
        for(auto i : it){
            cout << i;
        }
        cout << "\n";
    }
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