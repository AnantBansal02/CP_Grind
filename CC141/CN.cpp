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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define o_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> 
void del(o_set& os, ll ele){
    auto it = os.find_by_order(os.order_of_key(ele));
    if(it != os.end() and *it == ele){
        os.erase(it);
    }
}

ll power(ll a, ll b, ll mod){
    ll ans = 1;
    while(b > 0){
        if(b & 1){
            (ans *= a) %= mod;
        }
        (a *= a) %= mod;
        b /= 2;
    }
    return ans;
}
int numberOfGoodSubsequences(int n, vector<int> &arr) {
    // Write your code here.
    ll mod = 1e9 + 7;
    ll ans = 0;
    o_set st;
    
    o_set st2;
    for(ll i = 0; i < n; i++){
        for(ll j = n - 1; j >= i + 1; j--){
            st2.insert(arr[j]);
        }
        for(ll j = i + 1; j < n; j++){
            del(st2, arr[j]);
            if (arr[i] < arr[j]) {
                ll k1 = st.order_of_key(arr[j] + 1) - st.order_of_key(arr[i]);
                ll k2 = st2.order_of_key(arr[j] + 1) - st2.order_of_key(arr[i]);
                (ans += power(2, k1 + k2, mod)) %= mod;
            }
            else{
                ll k1 = st.order_of_key(arr[i] + 1) - st.order_of_key(arr[j]);
                ll k2 = st2.order_of_key(arr[i] + 1) - st2.order_of_key(arr[j]);
                (ans += power(2, k1 + k2, mod)) %= mod;
            }
        }
        st.insert(arr[i]);
    }
    return ans;
}