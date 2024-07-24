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

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

ll fac[MAX], inv[MAX];

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void precomputeFactorialsAndInverses(int n, int MOD) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[n] = power(fac[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

ll ncrmod(ll n, ll r, ll p) {
    if (r == 0) return 1;
    if (n < r) return 0;
    return (fac[n] * inv[r] % p) * inv[n - r] % p;
}

void solve() {
    ll mod = 1e9 + 7;
    ll n; cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= 2 * n; i++){
        for(ll mis = 1; mis <= min(n, i); mis++){
            ll mini = i - mis;
            if(mini > mis - 1){
                continue;
            }
            ll val = ncrmod(min(i - 1, n), mini, mod);
            if(mis - 1 == mini){
                (ans += i * val) %= mod;
            }
            else{
                if(n - i >= mis - 1 - mini){
                    (val *= ncrmod(n - i, mis - 1 - mini, mod)) %= mod;
                    (ans += i * val) %= mod;
                }
            }
        }
    }
    (ans += 2*n + 1) %= mod;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomputeFactorialsAndInverses(1e5, 1e9 + 7);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
