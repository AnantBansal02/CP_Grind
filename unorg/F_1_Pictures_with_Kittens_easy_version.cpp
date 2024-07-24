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
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    ll dp[n+1][x+1];
    for(ll i = 0; i <= n; i++){
        for(ll j = 0; j <= x; j++){
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    /*
    
    for(ll i = 1; i <= n; i++){
        for(ll cnt = 1; cnt <= x; cnt++){
            for(ll j = i - 1; j >= max(0LL, i - k); j--){
                dp[i][cnt] = max(dp[i][cnt], arr[i - 1] + dp[j][cnt - 1]);
            }
        }
    }
    optimise this dp!

    */
    vector<deque<ll>> ds(x + 1);
    ds[0].push_back(0);
    for(ll i = 1; i <= x; i++){
        ds[i].push_back(-INF);
    }
    for(ll i = 1; i <= n; i++){
        if(i > k){
            for(ll cnt = 0; cnt <= x; cnt++){
                if(!ds[cnt].empty() and ds[cnt].front() == dp[i - k - 1][cnt]){
                    ds[cnt].pop_front();
                }
            }
        }
        for(ll cnt = 1; cnt <= x; cnt++){
            ll prev = ds[cnt - 1].size() == 0 ? -INF : ds[cnt - 1].front();
            dp[i][cnt] = max(dp[i][cnt], arr[i - 1] + prev);
        }
        for(ll cnt = 0; cnt <= x; cnt++){
            while(!ds[cnt].empty() and ds[cnt].back() < dp[i][cnt]){
                ds[cnt].pop_back();
            }
            ds[cnt].push_back(dp[i][cnt]);
        }
    }
    ll ans = -INF;
    for(ll i = n - k + 1; i <= n; i++){
        ans = max(ans, dp[i][x]);
    }
    if(ans < 0){
        ans = -1;
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
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}