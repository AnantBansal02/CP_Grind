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
    if(n%3 == 2){
        vector<ll> ans(n);
        ans[0] = 4;
        ans[1] = 5;
        ans[2] = 2;
        ans[3] = 1;
        ans[4] = 3;
        for(ll i=6;i<=n;i++){
            ans[i-1] = i;
        }
        for(int i=6;i<=n;i+=3){
            swap(ans[i-1], ans[i+1]);
        }
        for(auto it : ans){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    else{
        vector<ll> ans(n);
        for(ll i=1;i<=n;i++){
            ans[i-1] = i;
        }
        for(ll i=2;i<=n;i+=3){
            swap(ans[i-1], ans[i]);
        }
        for(auto it : ans){
            cout<<it<<" ";
        }
        cout<<"\n";
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