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
    ll n, k; cin >> n >> k;
    vector<vector<ll>> tree(n);
    for(ll i = 1; i < n; i++){
        ll u, v; cin >> u >> v;
        u--;v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    
    auto check = [&](ll mid) {
        vector<ll> sub(n, 0);
        vector<ll> par(n);
        ll curr = 0;
        function<void(ll, ll)> dfs = [&](ll node, ll pr) {
            sub[node]++;
            par[node] = pr;
            for(auto it : tree[node]){
                if(it == pr) continue;
                dfs(it, node);
                sub[node] += sub[it];
            }
            if(sub[node] >= mid){
                sub[node] = 0;
                curr++;
            }
        };
        dfs(0, -1);
        return curr > k;
    };
    ll ans = 1;
    ll low = 1;
    ll high = n;
    while(low <= high){
        ll mid = (low + high) >> 1;
        if(check(mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
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