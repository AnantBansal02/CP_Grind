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
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> arr(n, vector<ll>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }   
    vector<string> vec(n);
    for(auto &it : vec) cin >> it;
    ll change = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(vec[i][j] == '1'){
                change += arr[i][j];
            }
            else{
                change -= arr[i][j];
            }
        }
    }
    vector<ll> changes;
    vector<vector<ll>> pre(n, vector<ll>(m, 0));
    pre[0][0] = vec[0][0] - '0';
    for (ll j = 1; j < m; j++) 
        pre[0][j] = pre[0][j - 1] + (vec[0][j] - '0'); 
    for (ll i = 1; i < n; i++) 
        pre[i][0] = pre[i - 1][0] + (vec[i][0] - '0'); 

    for (ll i = 1; i < n; i++) { 
        for (ll j = 1; j < m; j++) 
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (vec[i][j] - '0'); 
    } 
    // for(ll i = 0; i < n; i++){
    //     for(ll j = 0; j < m; j++){
    //         cout << pre[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    for(ll i = k - 1; i < n; i++){
        for(ll j = k - 1; j < m; j++){
            ll prev = 0;
            if(i - k >= 0){
                prev += pre[i - k][j];
            }
            if(j - k >= 0){
                prev += pre[i][j - k];
            }
            if(i - k >= 0 and j - k >= 0){
                prev -= pre[i - k][j - k];
            }
            ll val = (pre[i][j] - prev);
            ll val2 = ((k*k) - val);
            changes.push_back(val - val2);
        }
    }
    // for(auto it : changes){
    //     cout << it << " ";
    // }
    // cout << "\n";
    // cout << change << "\n";
    ll sz = changes.size();
    ll g = changes[0];
    for(ll i = 1; i < sz; i++){
        g = __gcd(g, changes[i]);
    }
    // cout << g << "\n";
    if(g == 0){
        if(change == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        return;
    }
    // else{
    //     cout << "NO" << "\n";
    //     return;
    // }
    if(change % g == 0){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
    // cout << "\n";
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