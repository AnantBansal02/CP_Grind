#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout << #x << " = " << x << endl
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define all(x) (x).begin(), (x).end()
#define set_bits(x) __builtin_popcountll(x)

void solve()
{
    ll n, k;cin>>n>>k;
    ll mx = -1;
    for(ll i=1;i<=n;i++){
        cout<<"? 1 "<<n*i<<endl;
        ll curr;cin>>curr;
        if(curr == n){
            mx = i;
            break;
        }
    }
    ll lim = (n / k);
    for(ll i=lim;i>=1;i--){
        ll m = mx * i;
        bool flag = 1;
        ll l = 1;
        for(ll j=0;j<k;j++){
            if(l > n){
                flag = 0;
                break;
            }
            cout<<"? "<<l<<" "<<m<<endl;
            ll r;cin>>r;l = r+1;
            if(r == n+1){
                flag = 0;
                break;
            }
        }
        if(flag and l == n+1){
            cout<<"! "<<m<<endl;
            ll res;cin>>res;
            assert(res != -1);
            return;
        }
    }
    cout<<"! -1"<<endl;
    ll res;cin>>res;
    assert(res != -1);
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