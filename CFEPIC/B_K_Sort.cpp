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
    vector<ll> diff;
    for(ll i = 1; i < n; i++){
        if(arr[i] < arr[i-1]){
            diff.pb(arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
        }
    }
    sort(all(diff));
    ll ans = 0;
    ll sz = diff.size();
    ll sum = 0;
    for(ll i = 0; i < sz; i++){
        ll val = diff[i] - sum;
        if(val >= 0){
            ans += val * (sz - i + 1);
            sum += val;
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