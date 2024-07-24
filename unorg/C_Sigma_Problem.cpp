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
    ll mod = 1e8;
    ll n;cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(all(arr));
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ans += arr[i] * (n - 1);
    }
    for(ll i=0;i<n;i++){
        ll low = i+1;
        ll high = n-1;
        ll idx = -1;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(arr[i] + arr[mid] >= 1e8){
                idx = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(idx != -1){
            ans -= (n - idx) * mod;
        }
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