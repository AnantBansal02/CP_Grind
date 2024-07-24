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
    string s; cin >> s;
    vector<ll> land, croc, water;
    for(ll i = 1; i <= n; i++){
        if(s[i-1] == 'L'){
            land.pb(i);
        }
        if(s[i-1] == 'C'){
            croc.pb(i);
        }
        if(s[i-1] == 'W'){
            water.pb(i);
        }
    }
    land.pb(n+1);
    // function<bool(ll)> fun = [&](ll idx) -> bool{  
    //     if(idx > n){
    //         return true;
    //     }
    //     bool ans = false;
    //     if(idx > 0 and s[idx - 1] == 'W'){
    //         auto it = lower_bound(all(land), idx) - land.begin();
    //         auto bt = lower_bound(all(croc), idx) - croc.begin();
    //         if(land[it] - idx > k || (bt < croc.size() and croc[bt] < land[it])){
    //             return false;
    //         }
    //         ans |= fun(land[it]);
    //     }
    //     if(idx == 0 || s[idx - 1] == 'L'){
    //         for(ll i = 1; i <= m; i++){
    //             if(idx + i > n){
    //                 return true;
    //             }
    //             if(s[idx + i - 1] != 'C'){
    //                 ans |= fun(idx + i);
    //             }
    //         }
    //     }
    //     return ans;
    // };
    // bool ans = fun(0);
    // if(ans){
    //     cout << "YES" << "\n";
    // }
    // else{
    //     cout << "NO" << "\n";
    // }
    ll curr = 0;
    ll swim = 0;
    while(curr < n){
        auto it = upper_bound(all(land), curr) - land.begin();
        if(land[it] - curr > m){
            if(s[curr + m - 1] == 'C'){
                cout << "NO" << "\n";
                return;
            }
            curr += m;
            auto it = lower_bound(all(land), curr) - land.begin();
            auto bt = lower_bound(all(croc), curr) - croc.begin();
            if(bt < croc.size() and croc[bt] < land[it]){
                cout << "NO" << "\n";
                return;
            }
            if(swim + land[it] - curr > k){
                cout << "NO" << "\n";
                return;
            }
            swim += land[it] - curr;
            curr = land[it];
        }   
        else{
            curr = land[it];
        }
    }
    cout << "YES" << "\n";
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