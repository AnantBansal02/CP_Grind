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
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;

    vector<vector<ll>> tree(n);
    vector<ll> ind(n, 0);
    for(ll i = 1; i < n; i++){
        ll u, v; cin >> u >> v; u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
        ind[u]++;ind[v]++;
    }
    if(n == 1){
        cout << "0\n";
        return;
    }
    vector<ll> leaves;
    function<void(ll, ll)> dfs = [&] (ll node, ll par) {
        ll isleaf = 1;
        for(auto it : tree[node]){
            if(it == par) continue;
            dfs(it, node);
            isleaf = 0;
        }
        if(isleaf) leaves.push_back(node);
    };
    ll mini = *min_element(all(arr));
    vector<ll> ans;
    ll root = -1;
    for(ll i = 0; i < n; i++){
        if(arr[i] == mini){
            root = i;
            dfs(i, -1);
            break;
        }
    }
    // for(auto it : leaves) cout << it << " ";
    // cout << "\n";
    queue<ll> q;
    for(auto it : leaves){
        q.push(it);
    }
    while(!q.empty()){
        auto it = q.front();q.pop();
        ans.push_back(it);
        for(auto next : tree[it]){
            if(ind[next] == 1 || next == root) continue;
            ind[next]--;
            if(ind[next] == 1){
                q.push(next);
            }
        }
    }
    assert(ans.size() == n - 1);
    cout << n - 1 << "\n";
    for(auto it : ans){
        cout << it + 1 << " ";
    }
    cout << "\n";
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