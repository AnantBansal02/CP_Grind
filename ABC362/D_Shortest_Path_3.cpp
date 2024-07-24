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
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for(auto &it : a) cin >> it;
    vector<vector<pair<ll,ll>>> g(n);
    for(ll i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w;
        u--;v--;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }   
    priority_queue<pair<ll,ll>> pq;
    pq.push({-a[0], 0});
    vector<ll> dis(n, INF);
    dis[0] = a[0];
    while(!pq.empty()){
        auto it = pq.top();pq.pop();
        ll curr = -it.first;
        ll node = it.second;
        if(curr <= dis[node]){
            for(auto &next : g[node]){
                if(dis[next.first] > curr + next.second + a[next.first]){
                    dis[next.first] = curr + next.second + a[next.first];
                    pq.push({-dis[next.first], next.first});
                }
            }
        }
    }
    for(ll i = 1; i < n; i++){
        cout << dis[i] << " \n"[i == n-1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}