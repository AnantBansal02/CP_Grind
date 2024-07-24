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
void sieve(ll MAXN)
{
    bool prime[MAXN + 1];memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= MAXN; p++) {
        if (prime[p] == true) {for (int i = p * p; i <= MAXN; i += p)prime[i] = false;}
    }
    for (int p = 2; p <= MAXN; p++)if(prime[p])primes.push_back(p);
}
void solve()
{
    ll n;cin>>n;
    
    auto check = [&] (ll num) {
        if(num & 1){
            return ((num) * (num + 1)) / 2 + 1;
        }
        else{
            ll remove = num/2 - 1;
            return ((num) * (num + 1)) / 2 - remove + 1;
        }

    };
    ll low = 1;
    ll high = 3e5;
    ll ans = INF;
    while(low <= high){
        ll mid = low + high >> 1;
        if(check(mid) >= n){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    } 
    if(ans == 1){
        cout<<"2 2"<<"\n";
        return;
    }
    vector<vector<ll>> adj(ans, vector<ll>(ans, 0));
    if(ans % 2 == 0){
        for(ll i=0;i<ans;i++){
            for(ll j=0;j<ans;j++){
                if(i != 0 and i%2 == 0 and j == i+1) continue;
                if(i != 1 and i%2 == 1 and j == i-1) continue;
                adj[i][j] = 1;
            }
        }
    }
    else{
        for(ll i=0;i<ans;i++){
            for(ll j=0;j<ans;j++){
                adj[i][j] = 1;
            }
        }
    }
    vector<ll> a;
    vector<ll> cur(ans);
    auto dfs = [&](auto &&self, ll x) -> void {
        for (ll &i = cur[x]; i < ans; i++) {
            if (adj[x][i]) {
                adj[x][i] = adj[i][x] = 0;
                self(self, i);
            }
        }
        a.push_back(primes[x]);
    };
    dfs(dfs, 0);
    a.resize(n);
    for(auto it : a){
        cout<<it<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    sieve(12000);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}






