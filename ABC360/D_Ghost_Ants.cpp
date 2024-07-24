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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> 
  

void solve()
{
    ll n, t; cin >> n >> t;
    string s; cin >> s;
    vector<ll> arr(n);
    ordered_set st; 
    for(auto &it : arr) cin >> it;
    for(ll i = 0; i < n; i++){
        if(s[i] == '0'){
            st.insert(arr[i]);
        }
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == '1'){
            ans += st.order_of_key(arr[i]);
        }
    }
    vector<ll> fin(n);
    ordered_set st2; 
    for(ll i = 0; i < n; i++){
        if(s[i] == '1'){
            fin[i] = arr[i] + t;
        }
        else{
            fin[i] = arr[i] - t;
            st2.insert(fin[i]);
        }
    }
    ll prev = ans;
    ans = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == '1'){
            ans += st2.order_of_key(fin[i] + 1);
        }
    }
    cout << ans - prev << "\n";

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