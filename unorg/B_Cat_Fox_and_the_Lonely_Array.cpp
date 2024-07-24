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
    vector<vector<ll>> pre(n, vector<ll>(21, 0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<21;j++){
            if((1LL << j) & arr[i]){
                pre[i][j]++;
            }
        }
        if(i > 0){
            for(ll j=0;j<21;j++){
                pre[i][j] += pre[i-1][j];
            }
        }
    }
    function<bool(ll)> check = [&] (ll mid) -> bool {
        ll ans = 0;
        for(ll i=0;i<mid;i++){
            ans = ans | arr[i];
        }
        for(ll i=mid;i<n;i++){
            vector<ll> temp(21, 0);
            ll curr = 0;
            for(ll j=0;j<21;j++){
                temp[j] = pre[i][j] - pre[i - mid][j];
                if(temp[j]){
                    curr = curr | (1LL << j);
                }
            }
            if(curr != ans){
                return false;
            }
        }
        return true;
    };
    ll low = 1;
    ll high = n;
    ll ans = n;
    while(low <= high){
        ll mid = (low + high) >> 1;
        if(check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
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