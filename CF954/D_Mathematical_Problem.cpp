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
    ll n; cin >> n;
    string s; cin >> s;
    if(n == 2){
        if(s[0] == '0'){
            cout << s[1] << "\n";
        }
        else{
            cout << s << "\n";
        }
        return;
    }
    if(count(all(s), '0') == 0){
        vector<ll> arr;
        for(auto it : s){
            arr.push_back(it - '0');
        }
        ll ans = INF;
        for(ll i=0;i<n-1;i++){
            ll curr = 0;
            for(ll j = 0; j < n; j++){
                if(j == i){
                    curr += 10 * arr[j];
                }
                else if(arr[j] != 1){
                    curr += arr[j];
                }
                else if(j == i+1 and arr[j] == 1){
                    curr += arr[j];
                }
            }
            ans = min(ans, curr);
        }
        cout << ans << "\n";
        return;
    }
    else{
        if(n == 3){
            if(s[0] == '0' || s[2] == '0'){
                cout << 0 << "\n";
                return;
            }
            else{
                ll val1 = (ll)(s[0] - '0') + (ll)(s[2] - '0');
                ll val2 = (ll)(s[0] - '0') * (ll)(s[2] - '0');
                cout << min(val1, val2) << "\n";
                return;
            }
        }
        cout << 0 << "\n";
        return;
    }
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