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

vector<ll> arr;
ll n;

ll fun (ll i, ll j, ll h){
    if(i > j){
        return 0LL;
    }
    ll ans = j - i + 1;
    ll mini = INT_MAX;
    for(ll idx = i; idx <= j; idx++){
        mini = min(mini, arr[idx]);
    }
    for(ll idx = i; idx <= j; idx++){
        if(arr[idx] == mini){
            ans = min(ans, fun(i, idx-1, mini) + fun(idx+1, j, mini) + mini - h);
            break;
        }
    }
    return ans;
}

void solve()
{
    cin >> n;
    arr = vector<ll>(n);
    for(auto &it : arr) cin >> it;
    cout << fun(0, n - 1, 0) << "\n";
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