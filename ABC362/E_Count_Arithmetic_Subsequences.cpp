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
    ll mod = 998244353;
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<ll> ans(n + 10, 0);
    ans[0] = n;
    unordered_set<ll> st;
    for(ll i_ = 0; i_ < n; i_++){
        for(ll j_ = i_ + 1; j_ < n; j_++){
            ll diff = arr[j_] - arr[i_];
            st.insert(diff);
        }
    }
    for(auto it : st){
        // differences can be O(N^2) but then we will enter the len loop very less
        // frequently so if we enter the loop often it means that no of unique differences are less
        vector<vector<ll>> dp(n, vector<ll>(n, 0));
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < i; j++){
                if(arr[i] - arr[j] == it){
                    (dp[i][1] += 1) %= mod;
                    for(ll len = 2; len < n; len++){
                        (dp[i][len] += dp[j][len-1]) %= mod; 
                    }   
                }
            }
            for(ll len = 1; len < n; len++){
                (ans[len] += dp[i][len]) %= mod;
            }
        }
    }

    for(ll i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << '\n';
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