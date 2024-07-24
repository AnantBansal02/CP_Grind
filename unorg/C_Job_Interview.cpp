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
    ll n, m; cin >> n >> m;
    ll sz = n + m + 1;
    vector<ll> a(sz), b(sz);
    for(auto &it : a) cin >> it;
    for(auto &it : b) cin >> it;

    vector<pair<ll,ll>> p, t;
    ll p_sum = 0, t_sum = 0;
    for(ll i=0;i<sz;i++){
        if(a[i] > b[i] and p.size() != n + 1){
            p.push_back({a[i], i});
            p_sum += a[i];
        }
        else if(t.size() != m + 1){
            t.push_back({b[i], i});
            t_sum += b[i];
        }
        else{
            p.push_back({a[i], i});
            p_sum += a[i];
        }
    }
    vector<ll> ans(sz);
    // cout << p.size() << " " << t.size() << "\n";
    // dbg(p_sum);dbg(t_sum);
    if(p.size() == n + 1){
        for(ll i=0;i<=n;i++){
            auto it = p[i]; 
            ans[it.second] = p_sum + t_sum - a[it.second];
        }
        for(ll i=0;i<m;i++){
            auto it = t[i];
            ans[it.second] = p_sum + t_sum - b[it.second] - p.back().first + b[p.back().second];
        }
    }
    else if(t.size() == m + 1){
        for(ll i=0;i<=m;i++){
            auto it = t[i]; 
            ans[it.second] = p_sum + t_sum - b[it.second];
        }
        for(ll i=0;i<n;i++){
            auto it = p[i];
            ans[it.second] = p_sum + t_sum - a[it.second] - t.back().first + a[t.back().second];
        }
    }

    for(auto it : ans){
        cout << it << " ";
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