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

ll n, m, src, dst;
vector<vector<vector<ll>>> g;
void solve()
{
    cin>>n>>m;
    g = vector<vector<vector<ll>>>(n);
    map<ll, vector<ll>> mp;
    for(ll i=0;i<m;i++){
        ll u,v,c;cin>>u>>v>>c;
        u--;v--;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
        mp[c].push_back(v);mp[c].push_back(u);
    }
    cin>>src>>dst;src--;dst--;
    vector<ll> dist(n, INT_MAX);
    dist[src] = 0;
    queue<ll> q;
    q.push(src);
    ll level = 1;
    set<ll> st;
    while(!q.empty()){
        ll sz = q.size();
        while(sz--){
            auto node = q.front();q.pop();
            for(auto it : g[node]){
                // cout<<node<<" "<<it[0]<<" "<<it[1]<<"\n";
                if(st.find(it[1]) == st.end()){
                    st.insert(it[1]);
                    for(auto adjNode : mp[it[1]]){
                        if(dist[adjNode] > level){
                            dist[adjNode] = level;
                            q.push(adjNode);
                        }
                    }
                }
            }
        }
        level++;
    }
    // cout<<dist[3]<<"\n";
    cout<<dist[dst]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}