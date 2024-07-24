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
    ll sz = 2e6 + 100;
    vector<ll> arr(sz);
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        arr[x]++;
    }
    for(ll i=1;i<sz;i++){
        arr[i] += arr[i-1];
    }
    ll ans = 0;
    for(ll i=1;i<sz;i++){
        ll f = arr[i] - arr[i-1];
        if(!f){
            continue;
        }
        ans += (f*(f-1))/2;
        ans += f*(arr[i*2-1] - arr[i]);
        ll k = 2;
        while(1){
            if(i*(k+1)-1 >= sz-1){
                ans += k*f*(arr[sz-1] - arr[i*k-1]);
                break;
            }
            ans += k*f*(arr[i*(k+1)-1] - arr[i*k-1]);
            k++;
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