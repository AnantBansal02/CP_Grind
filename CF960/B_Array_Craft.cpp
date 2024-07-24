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
    ll n, x, y; cin >> n >> x >> y;
    x--;y--;
    vector<ll> ans(n, 1);
    if(y & 1){
        ans[0] = -1;
    }
    else{
        ans[0] = 1;
    }
    for(ll i = 1; i <= y; i++){
        if(ans[i-1] == -1){
            ans[i] = 1;
        }
        else{
            ans[i] = -1;
        }
    }
    if(x + 1 < n) ans[x + 1] = -1;
    for(ll i = x + 2; i < n; i++){
        if(ans[i-1] == -1){
            ans[i] = 1;
        }
        else{
            ans[i] = -1;
        }
    }
    for(auto it : ans) cout << it << " ";
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