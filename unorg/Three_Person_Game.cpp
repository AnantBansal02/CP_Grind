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

ll power(ll x, ll y, ll p){
    ll res = 1;x = x % p;while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;
}
ll modInverse(ll n, ll p){
    return power(n, p - 2, p);
}
vector<ll> fac;
void factorial(int n, int MOD){
    fac.resize(n + 1);fac[0] = 1;for (int i = 1; i < n; i++){fac[i] = fac[i - 1] * i % MOD;}
}
ll ncrmod(ll n, ll r, ll p){
    if (n < r)return 0;
    if (r == 0)return 1;
    return (((fac[n] * modInverse(fac[r], p)) % p) * modInverse(fac[n - r], p)) % p;
}
vector<ll> primes;
void seive(ll n){
    bool prime[n + 1];memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {for (int i = p * p; i <= n; i += p)prime[i] = false;}
    }
    for (int p = 2; p <= n; p++)if(prime[p])primes.push_back(p);
}
ll getNoOfFactors(ll num) {
    if( num < 2 ) { return 0;}ll cnt = 0;
    for ( auto x : primes ) {while( num % x == 0 ) {cnt++;num /= x ;}}
    if( num > 1){cnt++;}
    return cnt;
}
vector<int> parent;
vector<vector<int>> up;
vector<int> depth;
int LOG;

int dfs(int node){
    if(depth[node] != -1){
        return depth[node];
    }
    return depth[node] = 1 + dfs(parent[node]);
}
void dfs2(int node, int par, vector<vector<int>> &tree){
    for(auto it : tree[node]){
        if(it != par){
            parent[it] = node;
            dfs2(it, node, tree);
        }
    }
}
void pre(){
    int n = parent.size();
    while((1<<LOG)<=n){
        LOG++;
    }
    up = vector<vector<int>> (n,vector<int>(LOG));
    for(int i=0;i<n;i++){
        up[i][0] = parent[i];
    }
    for(int j=1;j<LOG;j++){
        for(int i=0;i<n;i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}

int lca(int a, int b){
    int ans = 0;
    if(depth[a] < depth[b]){
        swap(a,b);
    }
    int k = depth[a] - depth[b];
    for(int j=LOG-1;j>=0;j--){
        if((1<<j) & k){
            ans = ans | (1 << j);
            a = up[a][j];
        }
    }
    if(a==b){
        return ans;
    }
    for(int j=LOG-1;j>=0;j--){
        if(up[a][j] != up[b][j]){
            ans = ans | (1 << j);
            a = up[a][j];
            b = up[b][j];
        }
    }
    return ans+1;
}

void solve()
{
    int n;cin>>n;
    int a,b,c;cin>>a>>b>>c;
    vector<vector<int>> tree(n);
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    parent.resize(n, 0);
    depth.resize(n,-1);
    dfs2(0, 0, tree);
    depth[0] = 0;
    for(int i=0;i<n;i++){
        dfs(i);
    }
    pre();
    cout<<
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}