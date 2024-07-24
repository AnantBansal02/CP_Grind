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
    ll mod = 1e9 + 7;
    ll n, k;
    cin >> n >> k;
    vector<ll> ans(n+1, 0);
    for(ll diff = -n+3, mul = 1; diff <= 1; diff++, mul++){
        ll val = (ncrmod(2*n - 4 - mul + 1, k - 2, mod) * mul) % mod;
        (ans[0] += val) %= mod;
    }
    for(ll diff = 2; diff <= n; diff++){
        ll val = (ncrmod(n - diff - 1, k - 2, mod) * (n - diff)) % mod;
        (val += 2LL * (ncrmod(n - diff, k - 1, mod))) %= mod;
        (ans[diff-1] += val) %= mod;
    }
    for(auto it : ans){
        cout << it << " ";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    factorial(5e5+10,1e9+7);
    // sieve(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

// import java.util.*

// const val MOD = 1000000007L
// val fac = mutableListOf<Long>()

// fun power(x: Long, y: Long, p: Long): Long {
//     var res = 1L
//     var base = x % p
//     var exp = y
//     while (exp > 0) {
//         if (exp and 1L == 1L) res = (res * base) % p
//         base = (base * base) % p
//         exp = exp shr 1
//     }
//     return res
// }

// fun modInverse(n: Long, p: Long): Long {
//     return power(n, p - 2, p)
// }

// fun factorial(n: Int, mod: Long) {
//     fac.clear()
//     fac.add(1)
//     for (i in 1..n) {
//         fac.add(fac[i - 1] * i % mod)
//     }
// }

// fun ncrmod(n: Long, r: Long, p: Long): Long {
//     if (n < r) return 0
//     if (r == 0L) return 1
//     return ((fac[n.toInt()] * modInverse(fac[r.toInt()], p) % p) * modInverse(fac[(n - r).toInt()], p) % p) % p
// }

// fun solve() {
//     val scanner = Scanner(System.`in`)
//     val n = scanner.nextLong()
//     val k = scanner.nextLong()
//     val ans = LongArray(n.toInt() + 1)
    
//     for (diff in -n + 3 until 2) {
//         val mul = diff + n - 3
//         val val1 = (ncrmod(2 * n - 4 - mul + 1, k - 2, MOD) * mul) % MOD
//         ans[0] = (ans[0] + val1) % MOD
//     }

//     for (diff in 2..n) {
//         var val = (ncrmod(n - diff - 1, k - 2, MOD) * (n - diff)) % MOD
//         val = (val + 2 * ncrmod(n - diff, k - 1, MOD)) % MOD
//         ans[diff.toInt() - 1] = (ans[diff.toInt() - 1] + val) % MOD
//     }

//     for (value in ans) {
//         print("$value ")
//     }
//     println()
// }

// fun main() {
//     factorial(200000 + 10, MOD)
//     var t = 1
//     // Uncomment the following line if you want to read the number of test cases
//     // t = Scanner(System.`in`).nextLong().toInt()
//     while (t-- > 0) {
//         solve()
//     }
// }
