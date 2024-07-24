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
    ll N, Q;cin>>N>>Q;
    vector<vector<ll>> g(N);
    for(ll i=1;i<N;i++){
        ll u,v;cin>>u>>v;
        u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<ll> depth(N, 0);
    vector<ll> per(N, 0);
    vector<ll> distinct(N, 0);
    vector<set<ll>*> subtree(N);
    vector<set<ll>*> duplicate(N);
    function<void(ll, ll)> dfs = [&](ll node, ll par) -> void{
        ll largest = -1;
        vector<ll> children;
        depth[node]++;
        for(auto it : g[node]){
            if(it == par){
                continue;
            }
            depth[it] += depth[node];
            dfs(it, node);
            children.pb(it);
            if(largest == -1 || subtree[largest]->size() < subtree[it]->size()){
                largest = it;
            }
        }
        if(largest == -1){
            subtree[node] = new set<ll>;
            duplicate[node] = new set<ll>;
        }
        else{
            subtree[node] = subtree[largest];
            duplicate[node] = duplicate[largest];
        }
        for(ll child : children){
            if(child == largest){
                continue;
            }
            // subtree[node]->insert(subtree[child]->begin(), subtree[child]->end());
            for(auto it : *subtree[child]){
                if(subtree[node]->find(it) != subtree[node]->end()){
                    duplicate[node]->insert(it);
                }
                subtree[node]->insert(it);
            }
            duplicate[node]->insert(duplicate[child]->begin(), duplicate[child]->end());
        }
        distinct[node] = subtree[node]->size() - duplicate[node]->size();
        if(per[node]){
            subtree[node]->insert(depth[node]);
        }
    };
    dfs(0, -1);
    bool firstTime = false;
    map<ll,ll> mp;
    ll ans = 0;
    while(Q--){
        ll type;cin>>type;
        if(type == 1){
            ll v;cin>>v;v--;
            if(v == 0){
                cout<<ans<<"\n";
            }
            else{
                if(!firstTime){
                    dfs(0, -1);
                    firstTime = true;
                }
                cout<<distinct[v]<<"\n";
            }
        }
        else{
            ll v;cin>>v;v--;
            if(v == 0){
                per[v] = !per[v];
                continue;
            }
            if(per[v] == 0){
                per[v] = 1;
                if(mp[depth[v]] == 1){
                    ans--;
                }
                mp[depth[v]]++;
                if(mp[depth[v]] == 1){
                    ans++;
                }
            }
            else{
                per[v] = 0;
                if(mp[depth[v]] == 1){
                    ans--;
                }
                mp[depth[v]]--;
                if(mp[depth[v]] == 1){
                    ans++;
                }
            }
        }
    }
    // for(auto it : distinct){
    //     cout<<it<<" ";
    // }
    // cout<<"\n";
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