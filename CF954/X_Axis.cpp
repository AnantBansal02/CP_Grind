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
    ll a, b, c; cin >> a >> b >> c;
    ll ans = INF;
    for(ll i=0;i<=10;i++){
        ans = min(ans, abs(a-i) + abs(b-i) + abs(c-i));
    }
    cout << ans << "\n";
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

class SCC {
    public:
    // Components will be topologically sorted
    vector<vector<ll>> adj, rev, components;
    vector<ll> which_component;
    ll N;
    SCC(ll n){
        this->N = n;
        adj.resize(N);
        rev.resize(N);
        which_component.resize(N, -1);
    }
    SCC(vector<vector<ll>>& g) {
        this->N = (ll)g.size();
        adj.resize(N);
        rev.resize(N);
        which_component.resize(N, -1);
        for (ll i = 0; i < N; i++) {
            for (auto it : g[i]) {
                adj[i].emplace_back(it);
                rev[it].emplace_back(i);
            }
        }
    }
    void addEdge(ll a, ll b){
        adj[a].emplace_back(b);
        rev[b].emplace_back(a);
    }
    void dfs(ll node, vector<ll>& vis, vector<ll>& order) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, order);
            }
        }
        order.emplace_back(node);
    }

    void dfs2(ll node, vector<ll>& vis, vector<ll>& temp, ll& id) {
        vis[node] = 1;
        which_component[node] = id;
        temp.emplace_back(node);
        for (auto it : rev[node]) {
            if (!vis[it]) {
                dfs2(it, vis, temp, id);
            }
        }
    }

    void build() {
        vector<ll> vis(N, 0), order;
        for (ll i = 0; i < N; i++) {
            if (!vis[i]) {
                dfs(i, vis, order);
            }
        }
        reverse(order.begin(), order.end());
        fill(vis.begin(), vis.end(), 0);
        ll id = 0;
        for (ll i = 0; i < N; i++) {
            if (!vis[order[i]]) {
                components.emplace_back();
                vector<ll>& temp = components.back();
                dfs2(order[i], vis, temp, id);
                id++;
            }
        }
    }
};