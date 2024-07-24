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
    ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    
    if(tx > sx){
        if(sy & 1){
            sx += (sx & 1);
        }
        else{
            sx += 1 - (sx & 1);
        }
    }
    else if(tx < sx){  
        if(sy & 1){
            sx -= ((sx & 1) == 1 ? 0 : 1);
        }
        else{
            sx -= ((sx & 1) == 1 ? 1 : 0);
        }
    }
    // cout << sx << " " << sy << "\n";
    ll ans = abs(sy - ty);
    if(abs(sy - ty) < abs(tx - sx)){
        ll ny = ty;
        ll nx = sx;
        if(tx > sx){
            nx += abs(sy - ty);
        }
        else{
            nx -= abs(sy - ty);
        }
        if(ny & 1){
            if(tx > nx){
                tx -= ((tx & 1) == 1 ? 0 : 1);
                nx += (nx & 1);
            }
            else{
                tx += (tx & 1);
                nx -= ((nx & 1) == 1 ? 0 : 1);
            }
        }
        else{
            if(tx > nx){
                tx -= ((tx & 1) == 1 ? 1 : 0);
                nx += 1 - (nx & 1);
            }
            else{
                nx -= ((nx & 1) == 1 ? 1 : 0);
                tx += 1 - (tx & 1);
            }
        }
        ans += (abs(tx - nx) + 1) / 2;
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
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}