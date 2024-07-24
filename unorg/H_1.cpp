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


class two_sat {
    public:
    ll n = 0;
    vector<vector<ll>> adj;
    vector<bool> values;
    two_sat(ll N){
        for (int i = 0; i < N; i++) new_var();
    }
    ll inv(ll var) {
        return var ^ 1;
    }
 
    ll new_var() {
        adj.emplace_back();
        adj.emplace_back();
        return 2 * n++;
    }

    ll convert (ll val) {
        ll idx = abs(val) - 1;
        return 2*idx + (val < 0);
    }

    void implies(ll a, ll b) {
        adj[a].push_back(b);
        adj[inv(b)].push_back(inv(a));
    }
 
    void either(ll a, ll b) {
        adj[inv(a)].push_back(b);
        adj[inv(b)].push_back(a);
    }
 
    void set_value(ll a) {
        adj[inv(a)].push_back(a);
    }
 
    void equal(ll a, ll b) {
        implies(a, b);
        implies(inv(a), inv(b));
    }
 
    void unequal(ll a, ll b) {
        implies(a, inv(b));
        implies(inv(a), b);
    }

    bool solve() {
        SCC scc(adj);
        scc.build();
 
        for (ll i = 0; i < n; i++)
            if (scc.which_component[2 * i] == scc.which_component[2 * i + 1])
                return false;
 
        values.resize(2 * n);
        // 1 -1 2 -2.....
        vector<bool> done(n, false);
 
        // (Kosaraju) In Topological order!
        for (auto &component : scc.components)
            for (auto x : component) {
                values[x] = done[x / 2];
                done[x / 2] = true;
            }
 
        for (ll i = 0; i < n; i++)
            assert(values[2 * i] ^ values[2 * i + 1]);
 
        return true;
    }
};

void solve()
{
    ll N;cin>>N;
    vector<vector<ll>> arr(3, vector<ll>(N));
    for(ll i=0;i<3;i++){
        for(ll j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    two_sat sat(N);
    
    for(ll j=0;j<N;j++){
        sat.either(sat.convert(arr[0][j]), sat.convert(arr[1][j]));
        sat.either(sat.convert(arr[0][j]), sat.convert(arr[2][j]));
        sat.either(sat.convert(arr[1][j]), sat.convert(arr[2][j]));
    }
    if(sat.solve()){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
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