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
    string s; cin >> s;

    map<ll, vector<ll>> mp;
    for(ll i=0; i < n; i++){
        mp[s[i] - 'a'].push_back(i);
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n, INF));
    for(ll i=0;i<n;i++){
        dp[0][i] = 0;
        dp[1][i] = 1;
    }
    
    for(ll len = 2; len <= n; len++){
        for(ll i=0; i + len <= n; i++){
            ll nidx = i + len - 1;
            ll ch = s[nidx] - 'a';
            ll sz = mp[ch].size();
            ll low = 0;
            ll high = sz-1;
            ll id = -1;
            while(low <= high){
                ll mid = (low + high) >> 1;
                if(mp[ch][mid] >= nidx){
                    id = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            dp[len][i] = 1 + dp[len-1][i];
            id--;
            while(id >= 0 and mp[ch][id] >= i){
                ll idx = mp[ch][id];
                dp[len][i] = min(dp[len][i], dp[idx - i][i] + dp[nidx - idx][idx]);
                id--;
            }
            // dbg(len);dbg(i);
            // cout << dp[len][i] << "\n";
        }
    }
    // i ...... idx ........ nidx
    // idx + 1 ...... nidx = nidx - idx

    cout << dp[n][0] << "\n";

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