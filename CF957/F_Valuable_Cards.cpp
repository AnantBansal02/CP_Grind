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
    vector<ll> div;
    for(ll i = 1; i*i <= k; i++){
        if(k % i == 0){
            div.pb(i);
            ll ni = k/i;
            if(i != ni){
                div.pb(ni);
            }
        }
    }
    sort(all(div));
    ll sz = div.size();
    vector<ll> can(k + 1, 0);
    can[1] = 1;
    ll ans = 1;
    for(ll i = 0; i < n; i++){
        if(k % arr[i] == 0 and can[k/arr[i]] == 1){
            for(ll j = 0; j < sz; j++){
                can[div[j]] = 0;
            }
            can[1] = 1;
            ans++;
        }
        for(ll j = sz - 1; j >= 0; j--){
            if(div[j] % arr[i] == 0 and can[div[j]/arr[i]]){
                can[div[j]] = 1;
            }
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5+10);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}