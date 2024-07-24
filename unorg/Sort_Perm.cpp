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
    for(auto &it : arr) cin >> it;

    ll low = 0;
    set<ll> st;
    for(ll i=1;i<n;i++){
        if(arr[i] < arr[i-1]){
            low = max(low, arr[i-1] - arr[i]);
            st.insert(i);
        }
    }
    auto check = [&](ll mid){
        vector<ll> temp = arr;
        for(auto it : st){
            temp[it] += mid;
        }
        for(ll i=1;i<n;i++){
            if(temp[i] < temp[i-1] and st.find(i) == st.end()){
                temp[i] += mid;
            }
        }
        return is_sorted(all(temp));
    };
    auto sum = [&] (ll num) {
        if(num <= 0){
            return 0LL;
        }
        return (num * (num + 1) / 2);
    };

    ll high = n;
    ll l = low;
    ll ans = 0;
    while(low <= high){
        ll mid = (low + high) >> 1;
        if(check(mid)){
            ans = sum(mid) - sum(l - 1);
            low = mid + 1;
        }
        else{
            high = mid - 1;
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
