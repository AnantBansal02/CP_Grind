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
vector<vector<ll>> dp;
ll f(ll i, ll j, string& a, string& b){
    if(i >= a.size()){
        return b.size() - j;
    }
    if(j >= b.size()){
        return a.size() - i;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    ll ans = INT_MAX;
    if(a[i] == b[j]){
        ans = min(ans, f(i+1, j+1, a, b));
    }
    ans = min(ans, 1 + f(i+1, j+1, a, b));
    ans = min(ans, 1 + f(i+1, j, a, b));
    ans = min(ans, 1 + f(i, j+1, a, b));
    return dp[i][j] = ans;
}
void solve()
{
    string a,b;cin>>a>>b;
    ll n = a.size();
    ll m = b.size();
    dp = vector<vector<ll>>(n+1, vector<ll>(m+1, INT_MAX));
    // cout<<f(0, 0, a, b)<<"\n";
    dp[0][0] = 0;
    for(int j=1;j<=m;j++){
        dp[0][j] = j;
    }
    for(int i=1;i<=n;i++){
        dp[i][0] = i;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
            dp[i][j] = min(dp[i][j], 1 + dp[i-1][j-1]);
            dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]);
            dp[i][j] = min(dp[i][j], 1 + dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}