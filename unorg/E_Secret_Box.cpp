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
    ll x,y,z,k;
    cin >> x >> y >> z >> k;
    ll ans = 0;
    // set<vector<ll>> st;
    for(ll i=1;i<=x;i++){
        for(ll j=1;j<=y;j++){
            ll mul = i * j;
            if(k % mul == 0 and k/mul <= z){
                ll p = k/mul;
                ans = max(ans, (x + 1 - i) * (y + 1 - j) * (z + 1 - p));
            }
        }
    }
    cout << ans << "\n";
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