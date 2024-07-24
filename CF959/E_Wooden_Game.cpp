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
    ll k; cin >> k;
    ll ans = 0;
    vector<ll> a;
    for(ll i = 0; i < k; i++){
        ll n; cin >> n;
        a.pb(n);
        vector<ll> arr(n - 1);
        for(auto &it : arr) cin >> it;
    }
    for(ll bit = 30; bit >= 0; bit--){
        ll cnt = 0;
        for(auto it : a){
            if((1LL << bit) & it){
                cnt++;
            }
        }
        if(cnt >= 1){
            ans |= (1LL << bit);
        }
        if(cnt >= 2){
            ans |= ((1LL << bit) - 1);
            break;
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