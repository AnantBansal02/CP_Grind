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
    map<pair<ll,ll>, map<ll,ll>> mp1;
    map<pair<ll,ll>, map<ll,ll>> mp2;
    map<pair<ll,ll>, map<ll,ll>> mp3;
    for(ll i=2;i<n;i++){
        mp1[{arr[i-2], arr[i-1]}][arr[i]]++;
        mp2[{arr[i-2], arr[i]}][arr[i-1]]++;
        mp3[{arr[i-1], arr[i]}][arr[i-2]]++;
    }
    ll ans = 0;
    for(auto it : mp1){
        vector<ll> fre;
        for(auto i : it.second) {
            fre.pb(i.second);
        }
        ll tot = accumulate(all(fre), 0LL);
        for(ll i=0;i<fre.size();i++){
            tot -= fre[i];
            ans += fre[i] * tot;
        }
    }
    for(auto it : mp2){
        vector<ll> fre;
        for(auto i : it.second) {
            fre.pb(i.second);
        }
        ll tot = accumulate(all(fre), 0LL);
        for(ll i=0;i<fre.size();i++){
            tot -= fre[i];
            ans += fre[i] * tot;
        }
    }
    for(auto it : mp3){
        vector<ll> fre;
        for(auto i : it.second) {
            fre.pb(i.second);
        }
        ll tot = accumulate(all(fre), 0LL);
        for(ll i=0;i<fre.size();i++){
            tot -= fre[i];
            ans += fre[i] * tot;
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