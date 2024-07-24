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


ll get(ll X, ll Y){
    ll ans = 0;
    ans += (X/4) * (Y/2) * 8;
    if(Y%2){
        ans += (X/4)*4;
    }
    if(X%4 >= 1){
        ans += 3 * (Y/2);
        if(Y%2){
            ans += 2;
        }
    }
    if(X%4 >= 2){
        ans += 3 * (Y/2);
        if(Y%2){
            ans += 1;
        }
    }
    if(X%4 >= 3){
        ans += (Y/2);
    }
    return ans;
}
void solve()
{
    ll a,b,c,d;cin>>a>>b>>c>>d;
    a += 1e9 + 12;
    b += 1e9 + 12;
    c += 1e9 + 12;
    d += 1e9 + 12;
    ll ans = get(c, d) + get(a, b) - get(c, b) - get(a, d);
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