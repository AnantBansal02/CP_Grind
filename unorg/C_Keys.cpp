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
    ll n,m,k;cin>>n>>m>>k;
    vector<vector<ll>> arr(m);
    vector<ll> res(m, 0);
    for(ll i=0;i<m;i++){
        ll sz;cin>>sz;
        while(sz--){
            ll x;cin>>x;x--;
            arr[i].pb(x);
        }
        char x;cin>>x;
        if(x == 'o'){
            res[i] = 1;
        }
    }
    ll ans = 0;
    for(ll mask=0;mask<(1 << n);mask++){
        bool flag = true;
        for(ll i=0;i<m;i++){
            ll cnt = 0;
            for(auto it : arr[i]){
                if((1 << it) & mask){
                    cnt++;
                }
            }
            if((cnt >= k and !res[i]) || (cnt < k and res[i])){
                flag = false;
                break;
            }
        }
        if(flag){
            ans++;
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
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}