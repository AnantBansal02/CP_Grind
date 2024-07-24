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
    ll m, x; cin >> m >> x;
    vector<vector<ll>> arr(m, vector<ll>(2));
    ll sum = 0;
    for(auto &it : arr){
        cin >> it[0] >> it[1];
        sum += it[1];
    }
    vector<vector<ll>> dp(sum+1, vector<ll>(2, 0));
    dp[0][0] = 1;
    for(ll i = 0; i < m; i++){
        ll c = arr[i][0];
        ll h = arr[i][1];
        for(ll j = sum; j >= 0; j--){
            if(j - h >= 0 and dp[j - h][0] == 1 and dp[j - h][1] >= c){
                dp[j][0] = 1;
                dp[j][1] = max(dp[j][1], dp[j - h][1] - c);
            }
            if(dp[j][0] == 1){
                dp[j][1] += x;
            }
        }
    }
    for(ll i = sum; i >= 0; i--){
        if(dp[i][0]){
            cout << i << "\n";
            return;
        }
    }
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