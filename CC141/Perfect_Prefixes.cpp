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

vector<ll> arr, pre;
vector<vector<ll>> dp;
ll sum (ll num){
    return (num * (num + 1))/2;
}
ll fun(ll idx, ll flag){
    ll n = arr.size();
    if(idx >= n){
        return 0LL;
    }
    if(dp[idx][flag] != -1){
        return dp[idx][flag];
    }
    ll ans = 0;
    if(flag == 1){
        if(idx + 1 < n){
            ll curr = 0;
            if(pre[idx + 1] == sum(idx + 2))curr++;
            if(pre[idx] - arr[idx] + arr[idx+1] == sum(idx + 1))curr++;
            ans = max(ans, curr + fun(idx + 2, 1));
        }
    }
    if(pre[idx] == sum(idx + 1)){
        if(flag != 0){
            ans = max(ans, 1 + fun(idx + 1, 2));
        }
        if(flag == 0){
            ans = max(ans, 1 + fun(idx + 1, 0));
        }
    }
    else{
        if(flag != 0){
            ans = max(ans, fun(idx + 1, 2));
        }
        if(flag == 0){
            ans = max(ans, fun(idx + 1, 0));
        }
    }
    if(flag == 0){
        ans = max(ans, fun(idx, 1));
    }
    return dp[idx][flag] = ans;
}
void solve()
{
    ll n; cin >> n;
    arr = vector<ll>(n);
    for(auto &it : arr) cin >> it;
    pre = vector<ll>(n);
    for(ll i = 0; i < n; i++){
        pre[i] = arr[i] ;
    }
    for(ll i = 1; i < n; i++){
        pre[i] += pre[i - 1];
    }
    dp = vector<vector<ll>> (n, vector<ll>(3, -1));
    cout << fun(0, 0) << "\n";
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