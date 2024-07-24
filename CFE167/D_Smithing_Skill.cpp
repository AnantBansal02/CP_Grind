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
    ll n, m; cin >> n >> m;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;

    vector<ll> brr(n);
    for(auto &it : brr) cin >> it;

    vector<pair<ll,ll>> a;
    for(ll i = 0; i < n; i++){
        a.pb({arr[i], brr[i]});
    }
    vector<ll> crr(m);
    for(auto &it : crr) cin >> it;

    sort(crr.rbegin(), crr.rend());
    sort(all(a), [&](pair<ll,ll>&f, pair<ll,ll>&s){
        if((f.fi - f.se) == (s.fi - s.se)){
            return f.fi < s.fi;
        }
        return (f.fi - f.se) < (s.fi - s.se);
    });
    ll ans = 0;
    vector<ll> fre(1e6+10, 0);
    {
        ll i = 0;
        while(i < m){
            while(i < m and crr[i] >= a[0].fi){
                ll curr = crr[i];
                ll diff = (a[0].fi - a[0].se);
                ll div = (curr - a[0].fi)/diff;
                ans += 2*(div + 1);
                curr -= diff * (div + 1);
                fre[curr]++;
                i++;
            }
            while(i < m){
                fre[crr[i]]++;
                i++;
            }
        }
    }
    ll j = 1e6 + 9;
    for(ll i = 1; i < n;i++){
        for(;j >= a[i].fi; j--){
            if(!fre[j]) continue;
            ll curr = j;
            ll diff = (a[i].fi - a[i].se);
            ll div = (curr - a[i].fi)/diff;
            ans += fre[j]*2*(div + 1);
            curr -= (div + 1) * diff;
            fre[curr] += fre[j];
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