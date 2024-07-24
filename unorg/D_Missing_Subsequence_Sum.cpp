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
    ll n, k;cin>>n>>k;
    ll msb = -1;
    vector<ll> ans;
    for(ll i=31;i>=0;i--){
        if((1 << i) & k){
            msb = i;
            break;
        }
    }
    ll sum = 0;
    for(ll i=0;i<msb;i++){
        sum += (1 << i);
        ans.pb((1 << i));
    }
    ans.pb(k-1-sum);
    ans.pb((1 << msb) + (1 << msb+1));
    ans.pb(k+1);
    for(ll i=msb+1;i<22;i++){
        if((1 << i) > n){
            break;
        }
        ans.pb((1 << i));
    }
    sort(all(ans));
    cout<<ans.size()<<"\n";
    for(auto it : ans){
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