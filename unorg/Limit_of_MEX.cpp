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


vector<ll> fun(vector<ll> arr){
    ll n = arr.size();
    vector<ll> ans(n, -1);
    stack<ll> st;
    for(ll i=0;i<n;i++){
        while(!st.empty() and arr[st.top()] <= arr[i]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
vector<ll> fun2(vector<ll> arr){
    ll n = arr.size();
    vector<ll> ans(n, -1);
    stack<ll> st;
    for(ll i=n-1;i>=0;i--){
        while(!st.empty() and arr[st.top()] < arr[i]){ // case 1 1 2 contribution of 1 should be 3!
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
void solve()
{
    ll n;cin>>n;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    vector<ll> front, back;
    front = fun(arr);
    back = fun2(arr);
    // for(auto it : front){
    //     cout<<it<<" ";
    // }
    // cout<<"\n";
    // for(auto it : back){
    //     cout<<it<<" ";
    // }
    // cout<<"\n";
    ll ans = (n*(n+1))/2;
    for(ll i=0;i<n;i++){
        ll left = (back[i] == -1 ? i + 1 : i - back[i]);
        ll right = (front[i] == -1 ? n - i : front[i] - i);
        // cout<<left*right*arr[i]<<" ";
        ans += left*right*arr[i];
    }
    // cout<<"\n";
    map<ll,vector<ll>> mp;
    for(ll i=0;i<n;i++){
        mp[arr[i]].pb(i);
    }
    for(auto it : mp){
        ll val = ((n*(n+1))/2);
        it.second.pb(n);
        ll last = -1;
        for(auto i : it.second){
            ll d = i - last - 1;
            val -= ((d*(d+1))/2);
            last = i;
        }
        // cout<<it.first << " " << val << "\n";
        ans -= val;
    }
    cout<<ans<<"\n";
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