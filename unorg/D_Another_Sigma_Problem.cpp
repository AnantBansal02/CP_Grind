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
    ll mod = 998244353;
    ll n;cin>>n;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        ll len = 0;
        ll num = arr[i];
        while(num > 0){
            len++;
            num /= 10;
        }
        mp[len]++;
    }
    ll ans = 0;
    ll sum = accumulate(all(arr), 0LL);
    // cout<<sum<<"\n";
    for(ll i=0;i<n-1;i++){
        sum -= arr[i];
        ll len = 0;
        ll num = arr[i];
        while(num > 0){
            len++;
            num /= 10;
        }
        mp[len]--;
        for(auto it : mp){
            ll mul = (arr[i] * power(10, it.first, mod)) % mod;
            (ans += mul * it.second) %= mod;
        }
        (ans += sum) %= mod;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}