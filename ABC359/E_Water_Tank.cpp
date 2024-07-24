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
    vector<ll> prev(n, -1);
    stack<ll> st;
    for(ll i=n-1;i>=0;i--){
        while(!st.empty() and arr[st.top()] < arr[i]){
            prev[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    vector<ll> ans(n);
    for(ll i=0;i<n;i++){
        if(prev[i] == -1){
            ans[i] = (i - prev[i]) * arr[i] + 1;
        }
        else {
            ans[i] = ans[i-1] + (i - prev[i]) * arr[i] + (ans[prev[i]] - ans[i-1]);
        }
    }
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
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}