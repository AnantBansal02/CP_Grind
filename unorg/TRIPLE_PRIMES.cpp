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


vector<ll> primes;
vector<ll> spf;
void sieve(ll MAXN)
{
    bool prime[MAXN + 1];memset(prime, true, sizeof(prime));
    for (ll p = 2; p * p <= MAXN; p++) {
        if (prime[p] == true) {for (ll i = p * p; i <= MAXN; i += p)prime[i] = false;}
    }
    for (ll p = 2; p <= MAXN; p++)if(prime[p])primes.push_back(p*p);
    // spf.resize(MAXN);
    // spf[1] = 1;
    // for (ll i = 2; i < MAXN; i++)spf[i] = i;
    // for (ll i = 4; i < MAXN; i += 2)spf[i] = 2;
 
    // for (ll i = 3; i * i < MAXN; i++) {
    //     if (spf[i] == i) {
    //         for (ll j = i * i; j < MAXN; j += i)if (spf[j] == j)spf[j] = i;
    //     }
    // }
}
vector<ll> getFactorization(ll x)
{
    // vector<ll> ret;
    // while (x != 1) {
    //     ret.push_back(spf[x]);
    //     x = x / spf[x];
    // }
    // return ret;
}
ll getNoOfFactors(ll num) {
    return getFactorization(num).size();
}


map<ll,ll> mp;

void solve()
{   
    ll N; cin >> N;
    ll sz = primes.size();
    for(ll i=0;i<sz;i++){
        ll val = N - primes[i] - 4;
        if(val < 0) break;
        if(mp.count(val) != 0 and val != primes[i]){
            cout << "Yes" << "\n";
            return;
        }
        
    }
    cout << "No" << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    sieve(1e5 + 10);
    for(auto it : primes){
        mp[it]++;
    }
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}