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
    sort(all(arr));
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll low = i;
        ll high = n - 1;
        ll idx = -1;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(arr[mid] == arr[i] + (mid - i)){
                idx = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        ll diff = idx - i;
        ans += ((diff) * (diff - 1)) / 2;

        low = i;
        high = n - 1;
        ll idx2 = -1;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(arr[mid] <= arr[i] + 1 + (mid - i)){
                idx2 = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        ans += idx2 - idx;
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