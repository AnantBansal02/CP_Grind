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

ll power(ll x, ll y, ll p){
    ll res = 1;x = x % p;while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;
}

void solve()
{
    ll n; cin >> n;
    ll mod = 998244353;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin >> it;
    }
    vector<ll> pre(n+1, 0);
    ll flag = 0;
    for(ll i=0;i<n;i++){
        pre[i+1] += pre[i] + arr[i];
        if(pre[i+1] < 0){
            flag = 1;
        }
    }
    if(!flag){
        cout << power(2, n, mod) << "\n";
        return;
    }
    ll maxi = 0;
    for(ll i=1;i<=n;i++){
        maxi = max(maxi, abs(pre[i]) + pre[n] - pre[i]);
    }
    ll ans = 0;
    ll cnt = 0;
    for(ll i=1;i<=n;i++){
        if(abs(pre[i]) + pre[n] - pre[i] == maxi){
           (ans += power(2, cnt + n - i, mod)) %= mod;
        }
        if(pre[i] >= 0){
            cnt++;
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