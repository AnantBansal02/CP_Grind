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
    ll n,m;cin>>n>>m;
    vector<vector<ll>> arr(n, vector<ll>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    queue<vector<ll>> q;
    q.push({0, 0});
    ll level = 0;
    vector<vector<ll>> vis(n, vector<ll>(m, 1e9));
    vis[0][0] = 0;
    while(!q.empty()){
        level++;
        ll sz = q.size();
        while(sz--){
            auto it = q.front();
            q.pop();
            ll i = it[0];
            ll j = it[1];
            // down
            if(arr[(i+1)%n][j] != 1 and arr[(i+2)%n][j] != 1 and vis[(i+2)%n][j] > level){
                vis[(i+2)%n][j] = level;
                q.push({(i+2)%n, j});
            }
            // right
            if(j + 1 < m  and arr[(i+1)%n][j+1] != 1 and vis[(i+1)%n][j+1] > level){
                vis[(i+1)%n][j+1] = level;
                q.push({(i+1)%n, j+1});
            }
        }
    }
    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<m;j++){
    //         if(vis[i][j] != 1e9){
    //             printf("%d ", vis[i][j]);
    //         }
    //         else{
    //             printf("-1 ");
    //         }
    //     }
    //     printf("\n");
    // }
    ll ans = 1e9;
    for(ll i=0;i<n;i++){
        if(vis[i][m-1] != 1e9){
            ll npos = (vis[i][m-1] - m + 1)%n;
            ans = min(ans, vis[i][m-1] + n - 1 - npos);
            ans = min(ans, vis[i][m-1] + npos + 1);
        }
    }
    if(ans >= 1e9){
        cout<<-1<<"\n";
    }
    else{
        cout<<ans<<"\n";
    }
    // printf("-1\n");
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