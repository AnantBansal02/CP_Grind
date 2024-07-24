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
    vector<string> arr(n);
    for(auto &it : arr) cin >> it;
    ll ans = n;
    for(ll mask = 0; mask < (1 << n); mask++){
        set<ll> st;
        for(ll i=0;i<n;i++){
            if((1 << i) & mask){
                for(ll j=0;j<m;j++){
                    if(arr[i][j] == 'o'){
                        st.insert(j);
                    }
                }
            }
        }
        if(st.size() == m){
            ans = min(ans, (ll)set_bits(mask));
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