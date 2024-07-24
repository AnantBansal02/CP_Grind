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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    ll ans = 0;
    ll i = 0;
    while(i < n){
        ll maxi = 0, sum = 0, cnt = 0;
        while(i < n and arr[i] != 0){
            if(cnt % 2 == 0) maxi = max(arr[i], maxi);
            sum += arr[i];cnt++;
            i++;
        }
        if(cnt & 1){ 
            ans += (sum - maxi)*2 + maxi;
        }
        else{
            ans += sum * 2;
        }
        i++;
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