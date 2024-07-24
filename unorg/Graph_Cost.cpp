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
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }

    vector<ll> suff(n), nextSmaller(n, -1);
    stack<ll> st;
    for(ll i=0;i<n;i++){
        while(!st.empty() and arr[st.top()] > arr[i]){
            nextSmaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    suff[n-1] = n-1;
    for(ll i=n-2;i>=0;i--){
        if(arr[i] <= arr[suff[i+1]]){
            suff[i] = i;
        }
        else{
            suff[i] = suff[i+1];
        }
    }
    ll ans = 0;
    ll i = 0;
    while(i < n - 1){
        if(nextSmaller[i] != -1){
            ans += (nextSmaller[i] - i)*arr[i];
            i = nextSmaller[i];
        }
        else{
            ans += (suff[i+1] - i)*arr[suff[i+1]];
            i = suff[i+1];
        }
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