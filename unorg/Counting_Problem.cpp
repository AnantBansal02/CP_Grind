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
void solve()
{
    ll N,M,K;cin>>N>>M>>K;
    ll ans = 0;
    ll MOD = 1e9 + 7;
    // if(K >= N){
    //     ans = power(M, N, MOD);
    //     ans = (ans - power(M-1, N, MOD) + MOD)%MOD;
    //     cout<<ans<<"\n";
    //     return;
    // }
    if(K == 1){
        ans = power(M, N - 1, MOD);
        cout<<ans<<"\n";
        return;
    }
    for(ll i=0;i<N;i++){
        if(i >= K){
            // (ans += power(K - 1, i, MOD)) %= MOD;
            // (ans += power(M, N - i - 1, MOD)) %= MOD;
            for(ll j=0;j<K;j++){
                ll curr = 1;
                (curr *= ncrmod(i, j, MOD)) %= MOD;
                (curr *= power(M - K, j, MOD)) %= MOD;
                (curr *= power(K - 1, i - j, MOD)) %= MOD;
                (curr *= power(M, N - i - 1, MOD)) %= MOD;
                (ans += curr) %= MOD;
            }
        }   
        else{
            (ans += power(M - 1, i, MOD)*power(M, N - 1 - i, MOD)) %= MOD;
        }
    }
    cout<<ans<<"\n";   
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    factorial(2e5 + 10,1e9+7);
    // seive(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}