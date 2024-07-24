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
    ll x, y; 
    cin >> x >> y;
    ll ans = 0;
    for(ll i=0;i<32;i++){
        if(((1LL << i) & x) || ((1LL << i) & y)){
            break;
        }
        else{
            ans++;
        }
    }
    x >>= ans; y >>= ans;
    while((x&1LL) == (y&1LL)){
        ans++;
        x /= 2; y /= 2;
    }
    cout<<(1LL << ans)<<"\n";
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