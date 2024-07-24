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

int dp[5001][5001];
int ans[5001];
void solve()
{
    string s;cin>>s;
    ll n = s.size();
    for(ll len = 1; len <= n; len++){
        for(ll i=0; i < n-len+1; i++){
            ll j = i + len - 1;
            if(i == j){
                dp[i][j] = 1;
                continue;
            }
            if(len == 2){
                if(s[i] == s[j]){
                    dp[i][j] = 2;
                }
                else{
                    dp[i][j] = 0;
                }
                continue;
            }
            if(len % 2 == 0){
                ll mid = (i + j)/2;
                // if(front[i][mid] == back[j][mid+1]){
                //     dp[i][j] = min(dp[i][mid], dp[mid+1][j]) + 1;
                // }
                if(s[i] == s[j] and dp[i+1][j-1]){
                    dp[i][j] = min(dp[i][mid], dp[mid+1][j]) + 1;
                }
            }
            else{
                ll mid = (i + j)/2;
                // if(front[i][mid-1] == back[j][mid+1]){
                //     dp[i][j] = min(dp[i][mid-1], dp[mid+1][j]) + 1;
                // }
                if(s[i] == s[j] and dp[i+1][j-1]){
                    dp[i][j] = min(dp[i][mid-1], dp[mid+1][j]) + 1;
                }
            }
        }
    }
    memset(ans, 0, sizeof(ans));
    for(ll len = 1; len <= n; len++){
        for(ll i=0; i < n-len+1; i++){
            ll j = i + len - 1;
            ans[dp[i][j]]++;
        }
    }
    for(ll i=n-1;i>=0;i--){
        ans[i] += ans[i+1];
    }
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}