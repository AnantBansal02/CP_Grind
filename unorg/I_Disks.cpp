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
    vector<vector<ll>> arr(n, vector<ll>(3));
    for(ll i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    auto check = [&](ll i, ll j){
        ll x = abs(arr[i][0] - arr[j][0]);
        ll y = abs(arr[i][1] - arr[j][1]);
        return ((x*x + y*y) == (arr[i][2] + arr[j][2]) * (arr[i][2] + arr[j][2]));
    };
    vector<vector<ll>> g(n);
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            if(check(i, j)){
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }
    vector<ll> vis(n, 0), col(n, -1);
    function<void(ll, ll&, ll&, ll)> dfs = [&](ll node, ll& a, ll& b, ll curr){
        vis[node] = 1;
        for(auto it : g[node]){
            if(col[it] == curr){
                a = -INF;
                b = -INF;
            }
            col[it] = !curr;
        }
        for(auto it : g[node]){
            if(!vis[it]){
                if(curr){
                    b++;
                }
                else{
                    a++;
                }
                dfs(it, a, b, !curr);
            }
        }
    };
    for(ll i = 0; i < n; i++){
        if(vis[i] == 0){
            ll a = 1, b = 0;
            dfs(i, a, b, 1);
            if(a != b and a > 0){
                cout << "YES" << "\n";
                return;
            }
        }
    }
    cout << "NO" << "\n";

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