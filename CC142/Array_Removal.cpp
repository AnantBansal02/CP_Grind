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
    vector<ll> arr(n);
    ll curr = 0;
    for(auto &it : arr){ cin >> it; curr |= it;}
    ll idx = 0;
    for(ll i = 0; i < 31; i++){
        if(!((1LL << i) & curr)){
            idx = i;
            break;
        }
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(arr[i] >= (1LL << (idx+1))){
            ans++;
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