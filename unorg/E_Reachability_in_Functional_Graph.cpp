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
    ll n; cin >> n;
    vector<vector<ll>> g(n);
    for(ll i=0;i<n;i++){
        ll x; cin >> x; x--;
        g[i].push_back(x);
    }
    vector<vector<ll>> cycles;
    vector<ll> vis(n, 0);
    vector<ll> par(n, -2);
    function<void(ll, ll)> dfs = [&] (ll node, ll p) {
        par[node] = p;
        ll next = g[node][0];
        vis[node] = 1;
        if(vis[next]){
            if(par[next] != -2){
                vector<ll> temp;
                ll curr = node;
                while(curr != next){
                    temp.push_back(curr);
                    curr = par[curr];
                }
                temp.push_back(next);
                cycles.push_back(temp);
            }
        }
        else{
            dfs(next, node);
        }
        par[node] = -2;
    };

    for(ll i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, -1);
        }
    }
    vis.assign(n, 0);
    vector<ll> ans(n, 0);
    for(auto it : cycles){
        ll sz = it.size();
        for(auto i : it){
            vis[i] = 1;
            ans[i] = sz;
        }
    }
    
    function<void(ll)> dfs2 = [&] (ll node) {
        ll next = g[node][0];
        vis[node] = 1;
        if(vis[next]){
            ans[node] = 1 + ans[next];
            return;
        }
        else{
            dfs2(next);
            ans[node] = 1 + ans[next];
        }
    };

    for(ll i=0;i<n;i++){
        if(!vis[i]){
            dfs2(i);
        }
    }

    // for(ll i=0;i<n;i++){
    //     cout << ans[i] << " \n"[i == n-1];
    // }

    ll sum = accumulate(all(ans), 0LL);

    cout << sum << "\n";

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