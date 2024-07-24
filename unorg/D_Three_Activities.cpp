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
vector<ll> primes;
void seive(ll n){
    bool prime[n + 1];memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {for (int i = p * p; i <= n; i += p)prime[i] = false;}
    }
    for (int p = 2; p <= n; p++)if(prime[p])primes.push_back(p);
}
ll getNoOfFactors(ll num) {
    if( num < 2 ) { return 0;}ll cnt = 0;
    for ( auto x : primes ) {while( num % x == 0 ) {cnt++;num /= x ;}}
    if( num > 1){cnt++;}
    return cnt;
}
ll f(ll idx, vector<ll>&a, vector<ll>&b, vector<ll>&c, ll mask, vector<vector<ll>>& dp){
    if(idx >= a.size()){
        return 0;
    }
    if(dp[idx][mask] != -1){
        return dp[idx][mask];
    }
    ll ans = 0;
    if(!(mask & 1)){
        ll nmask = mask ^ 1;
        ans = max(ans, a[idx] + f(idx+1, a, b, c, nmask, dp));
    }
    if(!(mask & 2)){
        ll nmask = mask ^ 2;
        ans = max(ans, b[idx] + f(idx+1, a, b, c, nmask, dp));
    }
    if(!(mask & 4)){
        ll nmask = mask ^ 4;
        ans = max(ans, c[idx] + f(idx+1, a, b, c, nmask, dp));
    }
    ans = max(ans, f(idx+1, a, b, c, mask, dp));
    return dp[idx][mask] = ans;
}
void solve()
{
    ll n;cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    for(auto &it : a){
        cin>>it;
    }
    for(auto &it : b){
        cin>>it;
    }
    for(auto &it : c){
        cin>>it;
    }
    vector<vector<ll>> dp(n, vector<ll>(8, -1));
    cout<<f(0, a, b, c, 0, dp)<<"\n";
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