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
    ll ans = 0;
    for(ll i = 0; i < 2; i++){
        vector<ll> temp(n + 1);
        ll maxi = 0;
        for(ll j = 0; j < n; j++){
            temp[arr[j]]++;
            if(temp[arr[j]] > 1){
                maxi = max(maxi, arr[j]);
            }
            ans += arr[j];
            arr[j] = maxi;
        }
    }
    for(ll i = n - 1; i > 0; i--){
        ans += arr[i] + arr[i] * (n - i - 1);
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