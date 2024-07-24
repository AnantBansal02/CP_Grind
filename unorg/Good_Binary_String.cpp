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
    vector<ll> ans;
    ll last = -1;
    for(ll i=0;i<n;i+=2){
        if(s[i] != s[i+1]){
            if((s[i] == '1' and last != 1) || (s[i] == '0' and last != 0)){
                ans.pb(i+1);
                last = s[i] - '0';
            }
            else{
                ans.pb(i+2);
                last = s[i+1] - '0';
            }

        }
    }
    cout<<ans.size()<<"\n";
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<"\n";
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