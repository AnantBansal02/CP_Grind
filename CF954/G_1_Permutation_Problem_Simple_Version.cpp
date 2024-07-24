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

void solve(ll t)
{
    ll n; cin >> n;
    vector<ll> arr(n+1);
    for(ll i=1;i<=n;i++) cin >> arr[i];
    ll ans = 0;
    unordered_map<ll, map<ll,ll>> mp;
    for(ll i = 1; i <= n; i++){
        ll idx = i;
        ll val = arr[i];
        ll g = __gcd(idx, val);
        idx /= g;
        val /= g;

        for(ll j = 1; j*j <= val; j++){
            if((val % j) == 0){
                ans += mp[j][idx];
                ll nj = val / j;
                if(nj != j){
                    ans += mp[nj][idx];
                }
            }
        }
        for(ll j = 1; j*j <= val; j++){
            if((val % j) == 0){
                mp[idx][j]++;
                ll nj = val / j;
                if(nj != j){
                    mp[idx][nj]++;
                }
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}