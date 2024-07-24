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
    ll n,m,c;cin>>n>>m>>c;
    vector<vector<ll>> tree(n);
    for(ll i=0;i<m;i++){
        ll u,v;cin>>u>>v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<ll> sub(n, 0);
    ll ans = LLONG_MAX;
    function<void(ll,ll)> dfs = [&] (ll node, ll par) {
        sub[node]++;
        for(auto it : tree[node]){
            if(it == par){
                continue;
            }
            dfs(it, node);
            sub[node] += sub[it];
        }
        ans = min(ans, sub[node]*sub[node] + (n-sub[node]) * (n-sub[node]));
    };
    dfs(0, -1);
    cout<<ans<<"\n";
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