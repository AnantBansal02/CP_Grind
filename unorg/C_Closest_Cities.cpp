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
    vector<ll> pre(n+1, 0);
    pre[1] = 1;
    for(ll i=1;i<n-1;i++){
        if(arr[i] - arr[i-1] > arr[i+1] - arr[i]){
            pre[i+1] = 1;
        }
        else{
            pre[i+1] = arr[i+1] - arr[i];
        }
    }
    vector<ll> suff(n+2, 0);
    suff[n+1] = 0;
    suff[n] = 1;
    for(ll i=n-2;i>=1;i--){
        if(arr[i+1] - arr[i] > arr[i] - arr[i-1]){
            suff[i+1] = 1;
        }
        else{
            suff[i+1] = arr[i] - arr[i-1];
        }
    }
    for(ll i=1;i<=n;i++){
        pre[i] += pre[i-1];
    }
    for(ll i=n;i>=0;i--){
        suff[i] += suff[i+1];
    }
    ll q;cin>>q;
    while(q--){
        ll l, r;cin>>l>>r;
        if(l > r){
            cout<<suff[r+1] - suff[l+1]<<"\n";
        }
        else{
            cout<<pre[r-1] - pre[l-1]<<"\n";
        }
    }
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