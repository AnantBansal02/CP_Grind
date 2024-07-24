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

ll MAXN = 300001;
vector<ll> a(MAXN);
vector<vector<ll>> tree(MAXN), dp(20, vector<ll>(MAXN, -1));

ll dfs(ll node, ll par, ll prev){
    if(dp[prev][node] != -1){
        return dp[prev][node];
    }
    ll ans = LLONG_MAX;
    for(ll i = 1; i < 20; i++){
        if(i != prev){
            ll curr = i*a[node];
            for(auto &it : tree[node]){
                if(it == par) continue;
                curr += dfs(it, node, i);
            }
            ans = min(ans, curr);
        }
    }
    return dp[prev][node] = ans;
}

void solve()
{
    ll n;cin>>n;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(ll i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    ll ans = dfs(1, 0, 0);
    cout << ans << "\n";
    for(ll i = 1; i <= n; i++){
        tree[i].clear();
    }
    for(ll i = 0; i < 20; i++){
        for(ll j = 1; j <= n; j++){
            dp[i][j] = -1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}