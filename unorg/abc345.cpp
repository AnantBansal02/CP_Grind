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

ll N, M, K;
vector<vector<vector<ll>>> g;
vector<ll> vis;
vector<ll> ans;

ll dfs(ll node, ll par, ll &K){
    vis[node] = 1;
    vector<vector<ll>> temp;
    for(auto &it : g[node]){
        if(it[0] == par || vis[it[0]]){
            continue;
        }
        temp.pb({dfs(it[0], node, K), it[1]});
    }
    ll cnt = 0;
    for(auto &it : temp){
        if(it[0] == 1 and K > 0){
            if(cnt % 2 == 0){
                K -= 2;
            }
            ans.pb(it[1]);
            cnt++;
        }
    }
    if(cnt % 2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}
void solve()
{
    cin>>N>>M>>K;
    if(K & 1){
        cout<<"No"<<"\n";
        return;
    }
    g = vector<vector<vector<ll>>>(N);
    vis = vector<ll>(N, 0);
    for(ll i=1;i<=M;i++){
        ll u,v;cin>>u>>v;
        u--;v--;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    for(ll i=0;i<N;i++){
        if(!vis[i] and K){
            dfs(i, -1, K);
        }
    }
    if(K != 0){
        cout<<"No"<<"\n";
        return;
    }
    cout<<"Yes"<<"\n";
    cout<<ans.size()<<"\n";
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}