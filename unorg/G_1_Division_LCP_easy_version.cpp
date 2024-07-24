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

vector<ll> z_function(string s) {
    ll n = s.size();
    vector<ll> z(n);
    ll l = 0, r = 0;
    for(ll i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
void solve()
{
    ll n,l,r;cin>>n>>l>>r;
    string s;cin>>s;
    vector<ll> z = z_function(s);
    z[0] = n;


    function<bool(ll, ll)> check = [&] (ll mid, ll req) -> bool {
        ll cnt = 0;
        ll i = 0;
        while(i < n){
            if(z[i] >= mid){
                cnt++;
                i += mid;
            }
            else{
                i++;
            }
        }
        return cnt >= req;
    };
    vector<ll> ans(n+1, 0);
    for(ll LCP=1;LCP*LCP<=n;LCP++){
        ll i = 0, cnt = 0;
        while(i < n){
            if(z[i] >= LCP){
                cnt++;
                i += LCP;
            }
            else{
                i++;
            }
        }
        for(ll i=0;i<=cnt;i++){
            ans[i] = LCP;
        }
    }
    for(ll i=l;i<=r;i++){
        if(i*i <= n){
            ll low = 1;
            ll high = n;
            ll curr = 0;
            while(low <= high){
                ll mid = (low + high) >> 1;
                if(check(mid, i)){
                    curr = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            cout<<curr<<" ";
        }
        else{
            cout<<ans[i]<<" ";
        }
    }
    cout<<"\n";

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