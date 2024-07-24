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
    ll n;cin>>n;
    vector<vector<ll>> arr(n, vector<ll>(2));
    for(ll i=0;i<n;i++){
        cin>>arr[i][0] >> arr[i][1];
    }
    vector<vector<ll>> adj(n);
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            if(arr[i][0] == arr[j][0] || arr[i][1] == arr[j][1]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<vector<ll>> dp((1 << n), vector<ll>(2, -1));
    function<ll(ll, ll)> dfs = [&] (ll mask, ll turn) -> ll {
        bool flag = true;
        if(dp[mask][turn] != -1){
            return dp[mask][turn];
        }
        ll ans = !turn ? INT_MIN : INT_MAX;
        for(ll i=0;i<n;i++){
            if((1 << i) & mask){
                continue;
            }
            for(auto j : adj[i]){
                if((1 << j) & mask){
                    continue;
                }
                flag = false;
                ll nmask = (mask ^ (1 << i)) ^ (1 << j);
                if(!turn){
                    ans = max(ans, dfs(nmask, !turn));
                }
                else{
                    ans = min(ans, dfs(nmask, !turn));
                }
            }
        }
        if(flag){
            if(turn){
                return INT_MAX;
            }
            else{
                return INT_MIN;
            }
        }
        return dp[mask][turn] = ans;
    };
    ll ans = dfs(0, 0);
    // for(ll i=0;i<(1 << n);i++){
    //     for(ll j=0;j<2;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    if(ans > 0){
        cout<<"Takahashi"<<"\n";
    }
    else{
        cout<<"Aoki"<<"\n";
    }
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