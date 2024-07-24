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
    ll n; cin >> n;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    if(n == 1){
        cout << 0 << "\n";
        return;
    }
    ll pre[n+2][31][2], suff[n+2][31][2];
    memset(pre, 0, sizeof(pre));
    memset(suff, 0, sizeof(suff));
    for(ll i = 1; i <= n; i++){
        for(ll bit = 0; bit <= 30; bit++){
            if((1 << bit) & arr[i-1]){
                pre[i][bit][0] += pre[i-1][bit][1];
                pre[i][bit][1] += pre[i-1][bit][0] + 1;
            }
            else{
                pre[i][bit][0] += pre[i-1][bit][0] + 1;
                pre[i][bit][1] += pre[i-1][bit][1];
            }
        }
    }
    for(ll i = n; i >= 1; i--){
        for(ll bit = 0; bit <= 30; bit++){
            if((1 << bit) & arr[i-1]){
                suff[i][bit][0] += suff[i+1][bit][1];
                suff[i][bit][1] += suff[i+1][bit][0] + 1;
            }
            else{
                suff[i][bit][0] += suff[i+1][bit][0] + 1;
                suff[i][bit][1] += suff[i+1][bit][1];
            }
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        for(ll bit = 30; bit >= 0; bit--){
            if((1 << bit) & arr[i - 1]){
                ans += pre[i][bit][1] * suff[i][bit][0];
                ans += pre[i][bit][0] * suff[i][bit][1];
                break;
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