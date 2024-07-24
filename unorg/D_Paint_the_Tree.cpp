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

void solve()
{
    ll n;cin>>n;
    ll a, b;cin>>a>>b;a--;b--;
    vector<vector<ll>> tree(n);
    for(ll i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        u--;v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    vector<ll> parent(n);
    function<void(ll, ll, ll, ll&)> dfs = [&] (ll node, ll par, ll val, ll& d) {
        parent[node] = par;
        d = max(d, val);
        for(auto it : tree[node]){
            if(it == par) continue;
            dfs(it, node, val+1, d);
        }
    };
    ll d = 0;
    dfs(a, -1, 0, d);
    vector<ll> temp;
    while(1){
        temp.pb(b);
        if(a == b){
            break;
        }
        b = parent[b];
    }
    ll meet = temp[(temp.size())/2];
    d = 0;
    dfs(meet, -1, 0, d);
    cout<<2*n - 2 - d + (ll)temp.size()/2<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}