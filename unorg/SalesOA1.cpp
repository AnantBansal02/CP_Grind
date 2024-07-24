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

class STLazy{
    vector<ll> st,lazy;
    public:
    STLazy(ll n){
        st.resize(4*n+1, 0);
        lazy.resize(4*n+1, 0);
    }
    public:
    void build(ll idx, ll low, ll high, vector<ll>& arr){
        if(low==high){
            st[idx] = arr[low];
            return;
        }
        ll mid = (low + high) >> 1;
        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }
    public:
    void update(ll idx, ll low, ll high, ll l, ll r, ll val){
        // update the previous while traversing
        if(lazy[idx] != 0){
            st[idx] += (high - low + 1)*lazy[idx];  
            // propogate the lazy update downwards
            if(low != high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        // no overlap
        // low high l r || l r low high
        if(l>high || low>r){
            return;
        }
        // complete overlap
        // l low high r
        if(low>=l and r>=high){
            st[idx] += (high - low + 1)*val;
            if(low!=high){
                lazy[2*idx+1] = val;
                lazy[2*idx+2] = val;
            }
            return;
        }
        ll mid = (low + high) >> 1;
        update(2*idx+1, low, mid, l, r, val);
        update(2*idx+2, mid+1, high, l, r, val);
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }
    public:
    ll query(ll idx, ll low, ll high, ll l, ll r){
        // if updates remaining!!! lazy!!
        if(lazy[idx] != 0){
            st[idx] += (high - low + 1)*lazy[idx];  
            // propogate the lazy update downwards
            if(low != high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(low>=l and r>=high){
            return st[idx];
        }
        if(l>high || low>r){
            return 0;
        }
        ll mid = (low + high) >> 1;
        return (query(2*idx+1,low,mid,l,r) + query(2*idx+2, mid+1, high, l, r));
    }
};
void solve()
{
    ll mod = 1e9 + 7;
    ll n,k;cin>>n>>k;
    // vector<vector<ll>> dp(n+1, vector<ll>(k+1, -1));
    // STLazy st(n+10);
    // ll low = 0;
    // ll high = n+9;
    // function<ll(ll, ll)> solve = [&] (ll idx, ll curr) -> ll {
    //     if(curr > k){
    //         return 0;
    //     }
    //     if(idx == n){
    //         if(curr == k){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     // if(dp[idx][curr] != -1){
    //     //     return dp[idx][curr];
    //     // }
    //     ll ans = 0;
    //     for(ll i=1;i<=n;i++){
    //         ll cnt = st.query(0, low, high, i+1, n);
    //         st.update(0, low, high, i, i, 1);
    //         (ans += solve(idx+1, curr + cnt)) %= mod;
    //         st.update(0, low, high, i, i, -1);
    //     }
    //     cout<<ans<<"\n";
    //     return dp[idx][curr] = ans;
    // };
    
    // ll res = solve(0, 0);
    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<=k;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<res<<"\n";
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[1][0] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= min(j, i - 1); ++l) {
                dp[i][j] += dp[i - 1][j - l];
                dp[i][j] %= mod;
            }
        }
    }
    cout<<dp[n][k]<<"\n";
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