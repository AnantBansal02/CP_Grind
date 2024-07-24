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
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    ll mod = 998244353;
    vector<vector<ll>> dp(n, vector<ll>(1 << k, -1));
    function<ll(ll, ll)> fun = [&] (ll idx, ll prev) -> ll {
        if(idx > n - k){
            return 1;
        }
        if(dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        ll ans = 0;
        ll mask = 0;
        for(ll i = 1; i < k; i++){
            ll b1 = ((1 << (i-1)) & prev) > 0 ? 1 : 0;
            if(b1){
                mask ^= (1 << i);
            }
        }
        for(ll change = 0; change <= 1; change++){
            if(change & 1){
                mask ^= 1;
            }
            bool flag = false;
            for(ll i = 1; i < k; i++){
                ll b1 = ((1 << (i-1)) & prev) > 0 ? 1 : 0;
                ll b2 = ((1 << i) & mask) > 0 ? 1 : 0;
                if(b1 != b2){
                    flag = true;
                    break;
                }
            }
            if(flag and idx != 0) continue;
            ll cnt = 0;
            for(ll i = idx; i < idx + k; i++){
                ll ni = k -  1 - (i - idx);
                ll nj = (i - idx);
                ll j = k - 1 + idx - (i - idx);

                int f1 = ((1 << ni) & mask) > 0 ? 1 : 0;
                int f2 = ((1 << nj) & mask) > 0 ? 1 : 0;

                if(f1){
                    if(s[i] == 'B'){
                        cnt = k;
                        break;
                    }
                }
                else{
                    if(s[i] == 'A') {
                        cnt = k;
                        break;
                    }
                }
                if(f2){
                    if(s[j] == 'B'){
                        cnt = k;
                        break;
                    }
                }
                else{
                    if(s[j] == 'A'){
                        cnt = k;
                        break;
                    }
                }
                
                if(f1 == f2){
                    cnt++;
                }
            }
            if(cnt != k){
                (ans += fun(idx + 1, mask)) %= mod;
            }
        }
        return dp[idx][prev] = ans;
    };
    ll fin = 0;
    for(ll mask = 0; mask < (1 << (k - 1)); mask++){
        (fin += fun(0, mask)) %= mod;
    }
    cout << fin << "\n";
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