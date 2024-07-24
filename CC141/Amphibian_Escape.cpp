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
    ll n, k, h; cin >> n >> k >> h;
    ll ans = 0;

    auto check = [&](ll x, ll i){
        ll val = (h - i + i - x - 1)/(i - x) + 1;
        // assert((i - x)*(val-1) + 1 >= h);
        return val <= k;
    };
    for(ll i = 1; i <= n; i++){
        if(i >= h){
            ans += n;
        }
        else{
            ll low = 0;
            ll high = i - 1;
            ll x = -1;
            while(low <= high){
                ll mid = (low + high) >> 1;
                if(check(mid, i)){
                    x = mid;
                    low = mid + 1;
                } 
                else{
                    high = mid - 1;
                }
            }
            if(x != -1){
                ans += x;
            }
            // cout << x << " ";
        }
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