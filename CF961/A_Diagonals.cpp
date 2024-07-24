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
    if(k == 0){
        cout << 0 << "\n";
        return;
    }
    ll ans = 0;
    ll f = 1;
    ll start = n;
    while(k > 0){
        if(f){
            ans++;
            k -= start;
            f = 0;
        }
        else{
            k -= start;
            ans++;
            if(k > 0){
                k -= start;
                ans++;
            }
        }
        start--;
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