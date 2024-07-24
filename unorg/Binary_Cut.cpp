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


bool cmp(pair<ll,ll>&a, pair<ll,ll>&b){
    return a.first + a.second > b.first + b.second;
}
void solve()
{
    string s;cin>>s;
    ll n = s.size();
    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    function<ll(ll, ll)> f = [&](ll idx, ll cnt) -> ll {
        if(idx == n){
            if(cnt <= 1){
                return 0;
            }
            return INT_MAX;
        }
        if(cnt > 1){
            return INT_MAX;
        }
        if(dp[idx][cnt] != -1){
            return dp[idx][cnt];
        }
        bool ok1 = false;
        bool ok2 = false;
        ll ans = INT_MAX;
        for(ll i=idx;i<n;i++){
            if(s[i] == '0'){
                ok1 = true;
            }
            if(s[i] == '1'){
                ok2 = true;
            }
            string temp = s.substr(idx, i - idx + 1);
            if(is_sorted(all(temp))){
                ans = min(ans, 1 + f(i+1, cnt + (ok1 and ok2)));
            }
            else{
                break;
            }
        }
        return dp[idx][cnt] = ans;
    };
    cout<<f(0, 0)<<"\n";
    
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