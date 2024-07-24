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
    ll n, t;cin>>n>>t;
    vector<vector<ll>> tree(n);
    for(ll i=0;i<n-1;i++){
        ll u,v;cin>>u>>v;u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<ll> rounds(t);
    for(ll i=0;i<t;i++){
        cin>>rounds[i];
    }
    vector<ll> win(n, -1);
    function<void(ll, ll)> dfs = [&] (ll node, ll par) {
        for(auto it : tree[node]){
            if(it == par) continue;
            dfs(it, node);
            if(win[it] == 0){
                win[node] = 1;
            }
        }
        if(win[node] == -1){
            win[node] = 0;
        }
    };
    dfs(rounds[0]-1, -1);
    if(win[rounds[0] - 1]){
        cout<<"Ron"<<"\n";
    }
    else{
        cout<<"Hermione"<<"\n";
    }
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