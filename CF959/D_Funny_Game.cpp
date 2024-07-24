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


class DSU{
    vector<ll> par, size;
    public:
    DSU(ll n){
        par.resize(n);
        size.resize(n, 1);
        for(ll i = 0; i < n; i++){
            par[i] = i;
        }
    }
    ll find(ll node){
        if(par[node] == node){
            return node;
        }
        return par[node] = find(par[node]);
    }
    void join(ll u, ll v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(size[u] > size[v]){
            par[v] = u;
            size[u] += size[v];
        }
        else{
            par[u] = v;
            size[v] += size[u];
        }
    }
};
void solve()
{
    ll n; cin >> n;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    DSU ds(n);
    vector<pair<ll,ll>> ans;
    for(ll op = n - 1; op >= 1; op--){
        vector<vector<ll>> nodes(op);
        for(ll i = 0; i < n; i++){
            nodes[arr[i] % op].pb(i);
        }
        ll f = 0;
        for(ll mod = 0; mod < op; mod++){
            if(nodes[mod].size() >= 2){
                unordered_set<ll> st;
                for(auto it : nodes[mod]){
                    if(!st.empty() and st.find(ds.find(it)) == st.end()){
                        ans.push_back({nodes[mod][0] + 1, it + 1});
                        ds.join(nodes[mod][0], it);
                        f = 1;
                        break;
                    }
                    st.insert(ds.find(it));
                }
            }
            if(f) break;
        }
    }
    cout << "YES" << "\n";
    for(ll i = n - 2; i >= 0; i--){
        cout << ans[i].fi << " " << ans[i].se << "\n";
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