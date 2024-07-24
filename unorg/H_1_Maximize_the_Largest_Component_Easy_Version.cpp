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


class DSU{
    public:
    vector<ll> parent,size;
    DSU(ll n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(ll i=0;i<n;i++){
            parent[i] = i;
        }
    }
    
    ll findUPar(ll node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(ll u, ll v){
        ll ul_u = findUPar(u);
        ll ul_v = findUPar(v);
        if(ul_u == ul_v){
            return;
        }
        if(size[ul_u] < size[ul_v]){
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
        else{
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        }
    }
};

void solve()
{
    ll n, m; cin >> n >> m;
    vector<string> arr(n);
    for(auto &it : arr) cin >> it;
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    DSU ds(n*m);
    auto bfs = [&](ll i, ll j){
        queue<pair<ll,ll>> q;
        q.push({i, j});
        vector<ll> di = {-1, 1, 0, 0};
        vector<ll> dj = {0, 0, 1, -1};
        while(!q.empty()){
            auto it = q.front();q.pop();
            ll row = it.first;
            ll col = it.second;
            for(ll d=0;d<4;d++){
                ll ni = row + di[d];
                ll nj = col + dj[d];
                if(ni >= 0 and nj >= 0 and ni < n and nj < m and !vis[ni][nj] and arr[ni][nj] == '#'){
                    vis[ni][nj] = 1;
                    ds.unionBySize(i*m + j, ni*m + nj);
                    q.push({ni, nj});
                }
            }   
        }
    };
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(!vis[i][j] and arr[i][j] == '#'){
                vis[i][j] = 1;
                bfs(i, j);
            }
        }
    }
    ll ans = 0;
    if(m > 1){
        for(ll j=0;j<m;j++){
            set<ll> temp;
            ll cnt = 0;
            for(ll i=0;i<n;i++){
                if(arr[i][j] == '#'){
                    temp.insert(ds.findUPar(i*m + j));
                }
                else{
                    cnt++;
                }
            }
            if(j != m - 1){
                for(ll i=0;i<n;i++){
                    if(arr[i][j+1] == '#'){
                        temp.insert(ds.findUPar(i*m + j+1));
                    }
                }
            }
            if(j != 0){
                for(ll i=0;i<n;i++){
                    if(arr[i][j-1] == '#'){
                        temp.insert(ds.findUPar(i*m + j-1));
                    }
                }
            }
            ll curr = cnt;
            for(auto it : temp){
                // cout << it << " ";
                curr += ds.size[it];
            }
            // cout << "\n";
            ans = max(ans, curr);
        }
    }
    else{
        ans = max(ans, n);
    }

    if(n > 1){
        for(ll i=0;i<n;i++){
            set<ll> temp;
            ll cnt = 0;
            for(ll j=0;j<m;j++){
                if(arr[i][j] == '#'){
                    temp.insert(ds.findUPar(i*m + j));
                }
                else{
                    cnt++;
                }
            }
            if(i != n - 1){
                for(ll j=0;j<m;j++){
                    if(arr[i+1][j] == '#'){
                        temp.insert(ds.findUPar((i+1)*m + j));
                    }
                }
            }
            if(i != 0){
                for(ll j=0;j<m;j++){
                    if(arr[i-1][j] == '#'){
                        temp.insert(ds.findUPar((i-1)*m + j));
                    }
                }
            }
            ll curr = cnt;
            for(auto it : temp){
                curr += ds.size[it];
            }
            ans = max(ans, curr);
        }
    }
    else{
        ans = max(ans, m);
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