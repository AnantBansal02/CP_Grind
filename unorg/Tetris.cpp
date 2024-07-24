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

// ll mod = 1e9 + 7;
// ll f(ll n, ll turn, ll flag){
//     if(n <= 0){
//         return flag;
//     }
//     if(dp[n][turn][flag] != -1){
//         return dp[n][turn][flag];
//     }
//     ll ans = 0;
//     if(turn == 1){
//         (ans += f(n - 1, 0, 0)) %= mod;
//         (ans += f(n - 2, 1, 0)) %= mod;
//         (ans += f(n - 3, 1, 0)) %= mod;
//         (ans += f(n - 4, 1, 1)) %= mod;
//     }
//     else{
//         (ans += f(n - 1, 1, 0)) %= mod;
//         (ans += f(n - 2, 0, 0)) %= mod;
//         (ans += f(n - 3, 0, 0)) %= mod;
//         (ans += f(n - 4, 0, 0)) %= mod;
//     }
//     return dp[n][turn][flag] = ans%mod;
// }
// ll dp[100005][2];
// ll mod = 1e9+7;
// void solve()
// {
//     ll n;cin>>n;
//     if(n==3){
//         cout<<"3"<<"\n";
//         return;
//     }
//     if(n==2){
//         cout<<"1"<<"\n";
//         return; 
//     }
//     if(n==1){
//         cout<<"1"<<"\n";
//         return;
//     }
//     ll ans = (dp[n][0]+dp[n+1][0])%mod;
//     ans = (ans + dp[n+2][0])%mod;
//     ans = (ans + dp[n+3][0])%mod;
//     if(n<100000)
//     ans = (ans-dp[n-1][1]-dp[n-2][0]-dp[n-3][0]+4*mod)%mod;
//     if(n<99999)
//     ans = (ans-dp[n+1-1][1]-dp[n+1-2][0]-dp[n+1-3][0]+4*mod)%mod;
//     if(n<99998)
//     ans = (ans-dp[n+2-1][1]-dp[n+2-2][0]-dp[n+2-3][0]+4*mod)%mod;
//     if(n<99997)
//     ans = (ans-dp[n+3-1][1]-dp[n+3-2][0]-dp[n+3-3][0]+4*mod)%mod;
// 	cout<<ans<<"\n";

// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // factorial(1e5,1e9+7);
//     // seive(1e5);
//     memset(dp, 0, sizeof(dp));
//     dp[1][1] = 1;
//     dp[2][0] = 1;
//     dp[3][0] = 1;
//     dp[4][0] = 1;
//     int n = 100000;
//     for(int i=1;i<n+4;i++){
//         if(i<n)
//         dp[i][0] = (dp[i][0]+dp[i-1][1])%mod;
//         if(i-2>0 && i<n)
//         dp[i][0] = (dp[i][0]+dp[i-2][0])%mod;
//         if(i-3>0 && i<n)
//         dp[i][0] = (dp[i][0]+dp[i-3][0])%mod;
//         if(i-4>0)
//         dp[i][0] = (dp[i][0]+dp[i-4][0])%mod;
        
//         if(i<n)
//         dp[i][1] = (dp[i][1]+dp[i-1][0])%mod;
//         if(i-2>0 && i<n)
//         dp[i][1] = (dp[i][1]+dp[i-2][1])%mod;
//         if(i-3>0 && i<n)
//         dp[i][1] = (dp[i][1]+dp[i-3][1])%mod;
//         if(i-4>0 && i<n)
//         dp[i][1] = (dp[i][1]+dp[i-4][1])%mod;
//     }
//     ll t = 1;
//     cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }
ll MOD = 1000000007;
ll MAXN = 100000;


ll dp[100004][2];

void precomputeDP() {
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[3][0] = 1;
    dp[4][0] = 1;

    int n = 100000;
    for (int i = 1; i < n + 4; i++) {
        if (i < n)
            dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
        if (i - 2 > 0 && i < n)
            dp[i][0] = (dp[i][0] + dp[i - 2][0]) % MOD;
        if (i - 3 > 0 && i < n)
            dp[i][0] = (dp[i][0] + dp[i - 3][0]) % MOD;
        if (i - 4 > 0)
            dp[i][0] = (dp[i][0] + dp[i - 4][0]) % MOD;

        if (i < n)
            dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
        if (i - 2 > 0 && i < n)
            dp[i][1] = (dp[i][1] + dp[i - 2][1]) % MOD;
        if (i - 3 > 0 && i < n)
            dp[i][1] = (dp[i][1] + dp[i - 3][1]) % MOD;
        if (i - 4 > 0 && i < n)
            dp[i][1] = (dp[i][1] + dp[i - 4][1]) % MOD;
    }
}

ll solve(ll n) {
    if (n == 3)
        return 3;
    if (n == 2)
        return 1;
    if (n == 1)
        return 1;

    ll ans = (dp[n][0] + dp[n + 1][0]) % MOD;
    ans = (ans + dp[n + 2][0]) % MOD;
    ans = (ans + dp[n + 3][0]) % MOD;
    if (n < MAXN)
        ans = (ans - dp[n - 1][1] - dp[n - 2][0] - dp[n - 3][0] + 4 * MOD) % MOD;
    if (n < MAXN - 1)
        ans = (ans - dp[n + 1 - 1][1] - dp[n + 1 - 2][0] - dp[n + 1 - 3][0] + 4 * MOD) % MOD;
    if (n < MAXN - 2)
        ans = (ans - dp[n + 2 - 1][1] - dp[n + 2 - 2][0] - dp[n + 2 - 3][0] + 4 * MOD) % MOD;
    if (n < MAXN - 3)
        ans = (ans - dp[n + 3 - 1][1] - dp[n + 3 - 2][0] - dp[n + 3 - 3][0] + 4 * MOD) % MOD;

    return (ans + MOD) % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precomputeDP();

    ll t;
    std::cin >> t;
    while (t--) {
        ll n;
        std::cin >> n;
        std::cout << solve(n) << "\n";
    }

    return 0;
}