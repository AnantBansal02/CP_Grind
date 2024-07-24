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


class LCA{
    public:
    ll N, LOG=0, timer=0;
    vector<vector<ll>> up, tree;
    vector<ll> parent, depth, tin, tout;
    LCA(vector<vector<ll>> input){
        N = (ll)input.size();
        while((1 << LOG) <= N){
            LOG++;
        }
        up.assign(N, vector<ll>(LOG));parent.assign(N, 0);depth.assign(N, 0);
        tin.assign(N, 0);tout.assign(N, 0);
        depth[0] = 0;
        tree = input;
        build();
    }
    void dfs(ll node, ll par){
        tin[node] = ++timer;
        parent[node] = par;
        for(auto it : tree[node]){
            if(it == par){
                continue;
            }
            depth[it] = depth[node] + 1;
            dfs(it, node);
        }
        tout[node] = ++timer;
    }

    bool is_ancestor(ll u, ll v){
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    void build(){
        dfs(0, -1);
        for(ll i=0;i<N;i++){
            up[i][0] = parent[i];
        }
        for(ll j=1;j<LOG;j++){
            for(ll i=0;i<N;i++){
                if(up[i][j-1] == -1){
                    up[i][j] = -1;
                }
                else{
                    up[i][j] = up[up[i][j-1]][j-1];
                }
            }
        }
    }

    ll find(ll a, ll b){
        if (is_ancestor(a, b)){
            return a;
        }
        if (is_ancestor(b, a)){
            return b;
        }
        for(ll i = LOG-1; i >= 0; --i) {
            if (up[a][i] != -1 and !is_ancestor(up[a][i], b)){
                a = up[a][i];
            }
        }
        return up[a][0];
    }
};


void solve()
{
    ll n,q;cin>>n>>q;
    vector<vector<ll>> tree(n);
    for(ll i=0;i<n-1;i++){
        ll u,v;cin>>u>>v;
        u--;v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    vector<ll> A(n);
    for(auto &it : A){
        cin>>it;
    }
    LCA ds(tree);
    while(q--){
        ll type;cin>>type;
        if(type == 1){
            ll u,x;cin>>u>>x;
            A[--u] = x;
        }
        else{
            ll u,v;cin>>u>>v;
            u--;v--;
            ll lca = ds.find(u, v);
            if(ds.depth[u] + ds.depth[v] - 2*ds.depth[lca] > 1005){
                cout<<0<<"\n";
            }
            else{
                vector<ll> temp(1005, 0);
                while(u != lca){
                    temp[A[u]/2]++;
                    u = ds.parent[u];
                }
                while(v != lca){
                    temp[A[v]/2]++;
                    v = ds.parent[v];
                }
                temp[A[lca]/2]++;
                ll ans = LLONG_MAX;
                ll last = -1;
                for(ll i=0;i<1005;i++){
                    if(temp[i] >= 2){
                        ans = 0;
                        break;
                    }
                    if(temp[i]){
                        if(last != -1){
                            ans = min(ans, i ^ last);
                        }
                        last = i;
                    }
                }
                cout<<ans<<"\n";
            }
        }
    }
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