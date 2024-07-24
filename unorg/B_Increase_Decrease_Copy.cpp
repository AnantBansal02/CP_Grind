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
    vector<ll> a(n), b(n+1);
    for(auto &it : a){
        cin>>it;
    }
    for(auto &it : b){
        cin>>it;
    }
    ll ans = 0;
    bool flag = false;
    ll mini = INF;
    for(ll i=0;i<n;i++){
        ans += abs(a[i] - b[i]);
        ll mx = max(a[i], b[i]);
        ll mn = min(a[i], b[i]);
        if(b[n] >= mn and b[n] <= mx){
            flag = true;
        }
        else if(b[n] > mx){
            mini = min(mini, (b[n] - mx));
        }
        else{
            mini = min(mini, (mn - b[n]));
        }
    }
    ans++;
    if(!flag){
        ans += mini;
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