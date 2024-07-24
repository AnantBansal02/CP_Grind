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
    ll n; cin >> n;
    if(set_bits(n) == 1){
        cout << 1 << "\n";
        cout << n << "\n";
        return;
    }
    vector<ll> vec;
    for(ll bit = 0; bit < 60; ++bit){ 
        if(n & (1LL << bit)) {
            vec.push_back(bit);
        }
    }
    vector<ll> ans(1, n);
    for(auto bit : vec) {
        ans.push_back(n ^ (1LL << bit));
    }
    reverse(all(ans));
    cout << ans.size() << "\n";
    for(auto it : ans){
        cout << it << " ";
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