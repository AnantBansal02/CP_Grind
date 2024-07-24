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
    vector<vector<ll>> arr(2, vector<ll>(n));
    for(ll i = 0; i < 2; i++){
        for(ll j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }   
    vector<pair<ll,ll>> a;
    for(ll i = 0; i < n; i++){
        a.pb({arr[0][i], arr[1][i]});
    }
    sort(all(a));
    auto check = [&](ll num, ll fre1, ll fre2){
        if(num * fre1 > m){
            return 0LL;
        }
        ll pos = min((m - (num * fre1))/(num + 1), fre2);
        ll curr = (num * fre1) + (pos * (num + 1));
        return curr;
    };
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(i + 1 < n and a[i].fi == a[i+1].fi - 1){
            ll f = min(m / a[i].fi, a[i].se);
            ans = max(ans, check(a[i].fi, f, a[i+1].se));
            ll diff = m - check(a[i].fi, f, a[i+1].se);
            if(diff > 0){
                ll pos = min((m - (a[i].fi * f))/(a[i].fi + 1), a[i+1].se);
                // ll curr = (a[i].fi * a[i].se) + (pos * (a[i].fi + 1));
                ll cover = min({diff, f, a[i+1].se - pos});
                ans = max(ans, check(a[i].fi, f, a[i+1].se) + cover);
            }
        }
        else{
            ll pos = min(m / a[i].fi, a[i].se);
            ans = max(ans, pos * a[i].fi);
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