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
    vector<ll> arr(n), brr(n);
    for(auto &it : arr) cin >> it;
    for(auto &it : brr) cin >> it;
    sort(all(arr));sort(all(brr));
    // auto check = [&](ll mid){
        
    //     return false;
    // };
    ll ans = 0;
    // ll low = 0;
    // ll high = 1e10;
    // while(low <= high){
    //     ll mid = (low + high) >> 1;
    //     if(check(mid)){
    //         ans = mid;
    //         low = mid + 1;
    //     }
    //     else{
    //         high = mid - 1;
    //     }
    // }
    // cout << ans << "\n";
    for(ll i = 0; i < n; i++){
        ll f = INF;
        for(ll j = 0; j < n; j++){
            f = min(f, abs(arr[j] - brr[(j + i)%n]));
        }
        ans = max(ans, f);
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