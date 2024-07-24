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
    string s;cin>>s;
    ll n = s.size();
    ll ans = 0;
    ll cnt = 0;
    bool flag = false;
    for(ll i=0;i<n;i++){
        if(s[i] == '0'){
            if(flag){
                ans += i + 1 - cnt;
            }
            cnt++;
        }
        if(s[i] == '1'){
            flag = true;
        }
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