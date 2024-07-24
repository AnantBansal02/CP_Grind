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
    ll n,k;cin>>n>>k;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    vector<vector<ll>> pre(n, vector<ll>(k+1, INF));
    for(ll i=0;i<n;i++){
        ll mini = INF;
        for(ll j=0;j<=k;j++){
            if(i+j < n){
                mini = min(mini, arr[i+j]);
            }
            pre[i][j] = mini;
        }
    }
    vector<ll> suff(n, 0);
    suff[n-1] = arr[n-1];
    for(ll i=n-2;i>=0;i--){
        suff[i] = suff[i+1] + arr[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(k+1, -1));
    function<ll(ll, ll)> dfs = [&] (ll idx, ll left) -> ll {
        if(idx == n){
            return 0;
        }
        if(dp[idx][left] != -1){
            return dp[idx][left];
        }
        if(left == 0){
            return suff[idx];
        }
        ll ans = INF;
        for(ll i=idx;i<n;i++){
            if(i - idx > left){
                break;
            }
            ans = min(ans, (i - idx + 1) * pre[idx][i - idx] + dfs(i+1, left - (i - idx)));
        }
        return dp[idx][left] = ans;
    };
    cout<<dfs(0, k)<<"\n";
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