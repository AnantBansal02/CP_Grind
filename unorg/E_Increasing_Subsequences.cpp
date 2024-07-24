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
    ll x;cin>>x;
    vector<ll> arr;
    for(ll i=60; i >= 0; i--){
        if((1LL << i) & x){
            for(ll a=1;a<=2*i;a+=2){
                arr.push_back(a);
            }
            ll curr = arr.back() - 1;
            for(ll j=i-1;j>=0;j--){
                if((1LL << j) & x){
                    arr.push_back(curr);
                }
                curr -= 2;
            }
            break;
        }
    }    
    cout<<arr.size()<<"\n";
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<"\n";
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