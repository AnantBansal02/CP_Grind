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

ll C2(ll num){
    return (num * (num - 1))/2;
}
class Solution {
public:
    ll timer = 1;
    ll ans = INF;
    ll N;
    void dfs(ll node, ll par, vector<ll> graph[], ll tin[], ll low[], ll vis[], ll sub[]){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto child : graph[node]){
            if(child == par){
                continue;
            }
            if(!vis[child]){
                dfs(child, node, graph, tin, low, vis, sub);
                sub[node] += sub[child];
                if(low[child] > tin[node]){
                    // ans.push_back({child, node});
                    ans = min(ans, C2(sub[child]) + C2((N - sub[child])));   
                }
            }
            low[node] = min(low[node], low[child]);
        }
    }
    ll fun(ll n, vector<vector<ll>>& edges) {
        N = n;
        vector<ll> graph[n];
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        ll vis[(ll)1e5] = {0};
        ll tin[n];
        ll sub[n];
        for(ll i=0;i<n;i++) sub[i] = 1;
        ll low[n];
        for(ll i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, -1, graph, tin, low, vis, sub);
            }
        }
        ans = min(ans, C2(n));
        return ans;
    }
};
void solve()
{
    ll n, m; cin >> n >> m;
    vector<vector<ll>> g;
    for(ll i=0;i<m;i++){
        ll u, v; cin >> u >> v;
        u--;v--;
        g.pb({u, v});
    }
    Solution sl;
    cout << sl.fun(n, g) << "\n";
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