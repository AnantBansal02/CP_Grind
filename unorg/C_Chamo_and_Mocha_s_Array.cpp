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

void solve(int t)
{
    ll n;cin>>n;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    if(n == 1){
        cout<<arr[0]<<"\n";
        return;
    }
    if(n == 2){
        cout<<min(arr[0], arr[1])<<"\n";
        return;
    }
    ll maxi = -INF;
    for(ll i=1;i<n-1;i++){
        ll sum = arr[i-1] + arr[i] + arr[i+1];
        ll mn = min({arr[i-1], arr[i], arr[i+1]});
        ll mx = max({arr[i-1], arr[i], arr[i+1]});
        maxi = max(maxi, sum - mn - mx);
    }
    cout<<maxi<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    cin >> t;
    for(ll i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}