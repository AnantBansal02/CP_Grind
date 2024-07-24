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
    ll n;cin>>n;
    string s;cin>>s;
    const ll p = 7817;
    const ll m = 1e9 + 9;
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (ll i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<ll> h(n + 1, 0);
    for (ll i = 0; i < n; i++){
        h[i+1] = (h[i] + (s[i]) * p_pow[i]) % m;
    }
    map<ll,ll> mp;
    stack<ll> st;
    for(ll i=0;i<n;i++){
        if(s[i] == '('){
            st.push(i);
        }
        else if(!st.empty()){
            ll id = st.top();
            st.pop();
            ll cur_h = (h[i+1] + m - h[id]) % m;
            cur_h = (cur_h * p_pow[n-id-1]) % m;
            // cout<<id<<" "<<i<<" "<<cur_h<<"\n";
            mp[cur_h]++;
        }
    }
    ll ans = 0;
    for(auto it : mp){
        ans += (it.second * (it.second - 1))/2;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}