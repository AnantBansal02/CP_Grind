#include<bits/stdc++.h>
using namespace std;
#define ll long

long maxBeauty(int n, vector<int> from, vector<int> to, vector<int> a){
    vector<vector<ll>> tree(n);
    for(ll i = 1; i < n; i++){
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

    function<void(ll, ll, ll)> reroot = [&](ll node, ll par, ll prev) {

    };
    reroot(0, -1, 0);

    
    return *max_element(ans.begin(), ans.end());
}

int main(){
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

    cout << maxBeauty(n, from, to, a);
}