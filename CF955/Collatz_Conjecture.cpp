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
    ll x, y, k; cin >> x >> y >> k;
    // x++;
    // k--;
    // while(x > y){
    //     if((x % y) > k){
    //         cout << x + k << "\n";
    //         return;
    //     }
    //     else{
    //         ll val = x % y;
    //         k -= val;
    //         x += val;
    //     }
    //     while(x % y == 0){
    //         x /= y;
    //     }
    // }
    // if(k == 0){
    //     cout << x << "\n";
    //     return;
    // }
    // x--;
    // ll len = (y - 1);
    // ll time = k % len;
    // x += time;
    // x = x % len;
    // cout << x + 1 << "\n";
    if(x < y){
        x--;
        ll len = (y - 1);
        ll time = k % len;
        x += time;
        x %= len;
        x++;
        cout << x << "\n";
    }
    else{
        x++;
        k--;
        while(x > y){
            ll val = (y - (x % y)) % y;
            // dbg(val);
            if(k < val){
                x += k;
                cout << x << "\n";
                return;
            }
            else{
                k -= val;
                x += val;
                while(x % y == 0){
                    x /= y;
                }
            }
        }
        x--;
        ll len = (y - 1);
        ll time = k % len;
        x += time;
        x %= len;
        x++;
        cout << x << "\n";
    }
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