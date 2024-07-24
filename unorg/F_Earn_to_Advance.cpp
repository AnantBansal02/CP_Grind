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
#define v(T) vector<T>
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

ll dist[85][85][85][85], best[85][85], rem[85][85];
void solve()
{
    ll N;cin>>N;
    vector<vector<ll>>P(N, vector<ll>(N, 0));
    set<ll> st;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            cin>>P[i][j];
        }
    }
    vector<vector<ll>>R(N, vector<ll>(N-1, 0));
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N-1;j++){
            cin>>R[i][j];
        }
    }
    vector<vector<ll>>D(N-1, vector<ll>(N, 0));
    for(ll i=0;i<N-1;i++){
        for(ll j=0;j<N;j++){
            cin>>D[i][j];
        }
    }
    for(ll i1=0;i1<N;i1++){
        for(ll j1=0;j1<N;j1++){
            for(ll i2=i1;i2<N;i2++){
                for(ll j2=j1;j2<N;j2++){
                    dist[i1][j1][i2][j2] = INF;
                    if(i1 == i2 and j1 == j2){
                        dist[i1][j1][i2][j2] = 0;
                    }
                    if(i2 - 1 >= i1)
                        dist[i1][j1][i2][j2] = min(dist[i1][j1][i2][j2], dist[i1][j1][i2-1][j2] + D[i2-1][j2]);
                    if(j2 -1 >= j1){
                        dist[i1][j1][i2][j2] = min(dist[i1][j1][i2][j2], dist[i1][j1][i2][j2-1] + R[i2][j2-1]);
                    }
                    // printf("%llu %llu %llu %llu %llu\n", i1, j1, i2, j2, dist[i1][j1][i2][j2]);
                }
            }
        }
    }
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            best[i][j] = INF;
            rem[i][j] = -INF;
        }
    }
    rem[0][0] = 0;
    best[0][0] = 0;
    for(ll i1=0;i1<N;i1++){
        for(ll j1=0;j1<N;j1++){
            for(ll i2=i1;i2<N;i2++){
                for(ll j2=j1;j2<N;j2++){
                    ll cost = dist[i1][j1][i2][j2];
                    ll d = i2 - i1 + j2 - j1;
                    ll need = max(0LL, (cost - rem[i1][j1] + P[i1][j1] - 1)/P[i1][j1]);
                    ll nb = best[i1][j1] + need + d;
                    ll nr = rem[i1][j1] + (need*P[i1][j1]) - cost;
                    if(nb == best[i2][j2]){
                        rem[i2][j2] = max(rem[i2][j2], nr);
                    }
                    else if(nb < best[i2][j2]){
                        best[i2][j2] = nb;
                        rem[i2][j2] = nr;
                    }
                    // printf("%llu %llu %llu %llu %llu %llu\n", i1, j1, i2, j2, best[i2][j2], cost);
                }
            }
        }
    }
    printf("%llu\n",best[N-1][N-1]);
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