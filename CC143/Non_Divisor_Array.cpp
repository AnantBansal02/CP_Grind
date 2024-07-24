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
    vector<ll> ans(n+1, 0);
    ll maxi = 1;
    ans[1] = 1;
    for(ll i = 1; i <= n; i++){
        for(ll j = i*2; j <= n; j += i){
            ans[j] = ans[i] + 1;
            maxi = max(maxi, ans[j]);
        }
    }
    for(ll i = 1; i <= n; i++){
        for(ll j = i*2; j <= n; j += i){
            assert(ans[i] != ans[j]);
        }
    }
    cout << maxi << "\n";
    for(ll i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
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