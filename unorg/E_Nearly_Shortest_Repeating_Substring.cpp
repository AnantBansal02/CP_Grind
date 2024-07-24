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
    string s;cin>>s;
    function<bool(ll)> check = [&] (ll len) -> bool {
        string sub = s.substr(0, len);
        string temp = "";
        ll m = n/len;
        for(ll i=0;i<m;i++){
            temp += sub;
        }
        ll cnt = 0;
        for(ll i=0;i<n;i++){
            if(temp[i] != s[i]){
                cnt++;
            }
        }
        if(len == n){
            return cnt <= 1;
        }
        string sub2 = s.substr(len, len);
        string temp2 = "";
        for(ll i=0;i<m;i++){
            temp2 += sub2;
        }
        ll cnt2 = 0;
        for(ll i=0;i<n;i++){
            if(temp2[i] != s[i]){
                cnt2++;
            }
        }
        return (cnt <= 1 || cnt2 <= 1);
    };
    ll ans = 1e9;
    for(ll i=1;i*i<=n;i++){
        if(n % i == 0){
            if(check(i)){
                ans = min(ans, i);
            }

            if(check(n/i)){
                ans = min(ans, n/i);
            }
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