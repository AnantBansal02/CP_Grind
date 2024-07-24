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
    vector<vector<pair<ll,ll>>> g(n);
    for(ll i=0;i<m;i++){
        ll u, v, w; 
        cin >> u >> v >> w;
        u--;v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<ll> s(n);
    for(auto &it : s) cin >> it;

    vector<vector<ll>> dis(n, vector<ll>(n, INF));
    dis[0][0] = 0;
    priority_queue<vector<ll>> pq;
    pq.push({0, 0, 0});
    while(!pq.empty()){
        auto it = pq.top();pq.pop();
        ll curr = -it[0];
        ll node = it[1];
        ll mini = it[2];
        for(auto next : g[node]){
            ll nmini = (s[mini] <= s[next.first] ? mini : next.first);
            if(dis[next.first][nmini] > curr + (next.second * s[mini])){
                dis[next.first][nmini] = curr + (next.second * s[mini]);
                pq.push({-dis[next.first][nmini], next.first, nmini});
            }
        }
    }
    ll ans = INF;
    for(ll i=0;i<n;i++){
        ans = min(ans, dis[n-1][i]);
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