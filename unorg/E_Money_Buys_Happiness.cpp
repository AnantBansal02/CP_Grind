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
    ll m,x;cin>>m>>x;
    vector<vector<ll>> arr(m, vector<ll>(2));
    ll sum = 0;
    for(ll i=0;i<m;i++){
        cin>>arr[i][0]>>arr[i][1];
        sum += arr[i][1];
    }
    ll ans = 0;
    vector<vector<ll>> dp(sum+1, vector<ll>(2, 0));
    dp[0][1] = 1;
    for(ll i=0;i<m;i++){
        ll cost = arr[i][0];
        ll val = arr[i][1];
        for(ll j=sum;j>=0;j--){
            if(j - val >= 0 and dp[j - val][0] >= cost and dp[j - val][1]){
                ans = max(ans, j);
                dp[j][0] = max(dp[j][0], dp[j - val][0] - cost);
                dp[j][1] = 1;
            }
            if(dp[j][1]){
                dp[j][0] += x;
            }
        }
    }
    printf("%lld\n", ans);
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