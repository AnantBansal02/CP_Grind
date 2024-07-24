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
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    vector<ll> ans;
    for(auto it : arr){
        ans.pb(it);
    }
    ll fin = -1;
    k++;
    for(ll bit = 30; bit >= 0; bit--){
        ll sz = ans.size();
        ll cnt = 0;
        vector<ll> ind;
        for(ll i = 0; i < sz; i++){
            if((1LL << bit) & ans[i]){
                ind.pb(i);
                cnt++;
            }
        }
        if((1LL << bit) & k){
            if(cnt % 2 == 0){
                ll cmp = 0;
                for(ll i = 0; i < cnt; i += 2){
                    cmp += ind[i+1] - ind[i];
                }
                fin = max(fin, sz - cmp);
            }
        }
        else{
            if(cnt & 1){
                break;
            }
            if(cnt > 0){
                ll i = 0, idx = 0;
                vector<ll> nans;
                while(i < sz){
                    ll val = 0;
                    ll f = 1;
                    while(idx < cnt and i >= ind[idx] and i <= ind[idx+1]){
                        val ^= ans[i];
                        i++;f = 0;
                    }
                    if(f){
                        nans.pb(ans[i]);
                        i++;
                    }
                    else{
                        nans.pb(val);
                        idx += 2;
                    }
                }
                ans = nans;
            }
        }
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
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}