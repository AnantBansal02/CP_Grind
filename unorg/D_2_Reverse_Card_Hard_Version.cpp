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
vector<ll> spf;
void sieve(ll MAXN)
{
    bool prime[MAXN + 1];memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= MAXN; p++) {
        if (prime[p] == true) {for (int i = p * p; i <= MAXN; i += p)prime[i] = false;}
    }
    for (int p = 2; p <= MAXN; p++)if(prime[p])primes.push_back(p);
    spf.resize(MAXN);
    spf[1] = 1;
    for (ll i = 2; i < MAXN; i++)spf[i] = i;
    for (ll i = 4; i < MAXN; i += 2)spf[i] = 2;
 
    for (ll i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < MAXN; j += i)if (spf[j] == j)spf[j] = i;
        }
    }
}
vector<ll> getFactorization(ll x)
{
    vector<ll> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
ll getNoOfFactors(ll num) {
    return getFactorization(num).size();
}

void solve()
{
    ll n,m;cin>>n>>m;
    ll ans = 0;
    // vector<ll> dp(m+1, 0);
    for(ll i=2;i<=m;i++){
        for(ll j=1;j<i;j++){
            if(i * (__gcd(i, j)) % (i + j) == 0 and j <= n){
                if(i % j != 0){
                    cout<<j<<" "<<i<<"\n";
                }
                ans++;
            }
        }
        for(ll j=i;j<=min(n,i*i);j+=i){
            if((i * i) % (i + j) == 0){
                // cout<<j<<" "<<i<<"\n";
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    sieve(1e6);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}