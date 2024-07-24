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
    ll N;cin>>N;
    string s;cin>>s;
    map<string, ll> mp;
    for(ll i=0;i<N;i+=2){
        string temp = s.substr(i, 2);
        mp[temp]++;
    } 
    ll ans = 0;
    ans += 2*mp["11"];
    if(mp["01"]){
        ans += 2;
    }
    if(mp["10"] >= 2){
        ans += 2;
    }
    else if(mp["10"] >= 1){
        ans++;
    }
    ans += 2*mp["00"];
    if(mp["01"] and mp["10"]){
        ans = max(ans, 3LL);
    }
    cout<<ans<<"\n";
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