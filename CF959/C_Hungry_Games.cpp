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
    ll n, x; cin >> n >> x;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    vector<ll> pre(n+1, 0);
    for(ll i = 1; i <= n; i++){
        pre[i] += pre[i-1] + arr[i-1];
    }
    vector<ll> dp(n+1, 0);
    ll ans = 0;
    for(ll i = n; i >= 1; i--){
        ll idx = lower_bound(all(pre), pre[i - 1] + x + 1) - pre.begin();
        // dbg(idx);
        dp[i] += idx - i;
        if(idx + 1 <= n){
            dp[i] += dp[idx + 1];
        }
    }
    for(ll i = 1; i <= n; i++){
        // cout << dp[i] << " \n"[i == n];
        ans += dp[i];
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

