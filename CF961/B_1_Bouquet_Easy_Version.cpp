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

    map<ll,ll> mp;
    for(auto it : arr){
        mp[it]++;
    }
    ll ans = 0;
    for(auto it : mp){
        if(mp.count(it.fi + 1)){
            ll curr = 0;
            for(int i = 1; i <= it.se; i++){
                if(it.fi * i > m){
                    break;
                }
                ll pos = min((m - (it.fi * i))/(it.fi + 1), mp[it.fi + 1]);
                ll curr = (it.fi * i) + (pos * (it.fi + 1));
                ans = max(ans, curr);
            }
        }
        else{
            ll pos = min(m / it.fi, it.se);
            ans = max(ans, pos * it.fi);
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