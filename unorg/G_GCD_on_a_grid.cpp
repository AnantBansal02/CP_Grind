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

ll n, m;
ll arr[101][101];

void solve()
{
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<ll> st;
    for(ll i=1;i*i<=arr[0][0];i++){
        if(arr[0][0] % i == 0){
            st.pb(i);
            st.pb(arr[0][0]/i);
        }
    }
    vector<vector<ll>> dp(2, vector<ll>(m, 0));
    sort(st.rbegin(), st.rend());
    for(auto d : st){
        if((arr[0][0] % d) != 0){
            continue;
        }
        dp[0][0] = 1;
        for(ll i=0;i<n;i++){
            ll idx = (i % 2 == 0) ? 0 : 1;
            for(ll j=0;j<m;j++){
                if(i == 0 and j == 0){
                    // cout<<1<<" ";
                    continue;
                }
                ll flag = dp[!idx][j];
                if(j > 0){
                    flag = flag || dp[idx][j-1];
                }
                if(flag and (arr[i][j] % d) == 0){
                    dp[idx][j] = 1;
                }
                else{
                    dp[idx][j] = 0;
                }
                // cout<<dp[!idx][j]<<" ";
                // dp[!idx][j] = 0;
            }
            // cout<<"\n";
        }
        ll idx = (n % 2 == 1) ? 0 : 1;
        if(dp[idx][m-1] == 1){
            cout<<d<<"\n";
            return;
        }
        for(ll i=0;i<m;i++){
            dp[0][i] = 0;
            dp[1][i] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e6);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

