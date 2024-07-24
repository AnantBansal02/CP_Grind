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
    string s; cin>>s;
    vector<ll> pre1(n+1, 0), pre2(n+1, 0);
    for(ll i=0;i<n;i++){
        if(s[i] == '1'){
            pre1[i+1]++;
        }
        else{
            pre2[i+1]++;
        }
        pre1[i+1] += pre1[i];
        pre2[i+1] += pre2[i];
    }  
    ll ans = 0;
    map<ll,ll> mp;
    for(ll i=0;i<=n;i++){
        ll diff = pre2[i] - pre1[i];
        ans += mp[diff];
        mp[diff]++;        
    }
    for(ll i=0;i<n;i++){
        ans += (n - i);
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