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
    ll r;cin>>r;
    ll ans = 0;
    for(ll i = 0; i <= r; i++){
        ll upper = 0;
        ll lower = 0;
        ll low = 0;
        ll high = r;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(i*i + mid*mid < (r+1)*(r+1)){
                upper = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        low = 0;
        high = r;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(i*i + mid*mid >= r*r){
                lower = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        // for(ll j=lower;j<=upper;j++){
        //     cout<<i<<" "<<j<<"\n";
        // }
        ans += 4*(upper - lower + 1);
        // if(i != 0 and i != r){
        //     ans += 4*(upper - lower + 1);
        // }
        // else{
        //     ans += 2*(upper - lower + 1);
        // }
    }   
    cout<<ans-4<<"\n";
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