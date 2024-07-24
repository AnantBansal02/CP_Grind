#include<bits/stdc++.h>
using namespace std;
typedef long ll;

long maxBeauty(int n, vector<int> from, vector<int> to, vector<int> a){
    vector<vector<ll>> tree(n);
    for(ll i = 0; i < n - 1; i++){
        tree[from[i] - 1].push_back(to[i] - 1);
        tree[to[i] - 1].push_back(from[i] - 1);
    }
    vector<ll> sub(n), ans(n, 0);

    function<void(ll, ll, ll)> dfs = [&](ll node, ll par, ll dis) {
        ans[0] += dis * a[node];
        sub[node] += a[node];
        for(auto it : tree[node]){
            if(it == par) continue;
            dfs(it, node, dis + 1);
            sub[node] += sub[it];
        }
    };
    dfs(0, -1, 0);
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    function<void(ll, ll)> reroot = [&](ll node, ll par) {
        for(auto it : tree[node]){
            if(it == par) continue;
            ll curr = ans[node] - sub[it] + sum - sub[it];
            ans[it] = curr;
            reroot(it, node);
        }
    };
    reroot(0, -1);
    return *max_element(ans.begin(), ans.end());
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> from(m), to(m);
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            from[i] = u;
            to[i] = v;
        }
        int N; cin >> N;
        vector<int> a(N);
        for(auto &it : a) cin >> it;

        cout << maxBeauty(n, from, to, a) << "\n";
    }
    return 0;
}