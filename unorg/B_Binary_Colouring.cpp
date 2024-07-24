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
    vector<ll> ans;
    for(ll i=0;i<32;i++){
        if((1 << i) & x){
            ans.pb(1);
        }
        else{
            ans.pb(0);
        }
    }
    ll i = 0;
    while(i < 32){
        ll cnt = 0;
        ll start = i;
        while(i < 32 and ans[i] == 1){
            i++;
            cnt++;
        }
        if(cnt > 1){
            for(ll j=start;j<=i;j++){
                ans[j] = 0;
            }
            ans[start] = -1;
            ans[i] = 1;
        }
        else{
            i++;
        }
    }
    cout<<ans.size()<<"\n";
    for(auto it : ans){
        cout<<it<<" ";
    }
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