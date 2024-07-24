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
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    sort(all(arr));
    auto check = [&](ll diff){
        for(ll i = 0; i < n; i++){
            ll curr = i;
            ll ele = arr[i];
            ll per = arr[i] + diff;
            ll ub = upper_bound(all(arr), per) - arr.begin();
            curr += n - ub;
            if(curr <= k){
                return true;
            }
        }
        return false;
    };
    ll low = 0;
    ll high = arr[n-1] - arr[0];
    ll ans = high;
    while(low <= high){
        ll mid = (low + high) >> 1;
        if(check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
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
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}