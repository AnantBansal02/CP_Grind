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

ll mod = 998244353;
ll f(ll i, ll x){
    ll totalPeriods = (x + 1LL) / (1LL << (i+1LL));
    ll ans = (totalPeriods * (1LL << i)) % mod;
    (ans += max(0LL, (x + 1LL) % (1LL << (i+1LL)) - (1LL << i))) %= mod;
    return ans;
}
void solve()
{
    ll n,m;cin>>n>>m;
    ll ans = 0;
    for(ll i=61;i>=0;i--){
        if((1LL << i) & m){
            (ans += f(i, n)) %= mod;
        }
    }
    cout<<ans<<"\n";
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
