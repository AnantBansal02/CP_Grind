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


ll mod = 1e9 + 7;

ll NC2(ll x){
    return ((x * (x - 1))/2) % mod;
}

ll dp[64][64];

ll fun(ll n, ll k){
    if(k < 0LL){
        return 0LL;
    }
    if(n == 1LL){
        return 1LL;
    }
    ll m = 0;
    for(ll i = 63; i >= 0; i--){
        if((1LL << i) & n){
            m = i;
            break;
        }
    }
    if((1LL << m) == n){
        if(dp[m][k] != -1){
            return dp[m][k];
        }
        m--;
    }
    ll mid = (1LL << m);
    ll ans1, ans2;
    ans1 = fun(mid, k);
    dp[m][k] = ans1;
    ans2 = fun(n - mid, k - 1LL);
    ll x = (k >= m) ? mid % mod : 0;
    ll y = min((1LL << k) - 1, n - mid) % mod;  
    ll ans = (ans1 + ans2 - NC2(x + 1LL) - NC2(y + 1LL) + NC2(x + y + 1LL) + 2*mod) % mod;
    return ans;
}
void solve()
{
    ll n, k; 
    cin >> n >> k;
    cout << fun(n, k) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while(t--){
        solve();
    }
    return 0;
}