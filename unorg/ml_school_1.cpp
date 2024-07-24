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
    string s; cin >> s;
    ll n = s.size();
    vector<ll> h(n+1, 0), p_pow(n, 0);
    ll p = 37831;
    ll m = 1e9 + 7;
    p_pow[0] = 1;
    for(ll i = 1; i < n; i++){
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }
    for(ll i = 0; i < n; i++){
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
    auto query = [&] (ll i, ll j){
        if(i > j){
            return -1LL;
        }
        ll val = (h[j+1] - h[i] + m) % m;
        (val *= p_pow[n - i - 1]) %= m;
        return val;
    };
    string ans = "";
    ll hash = 0;
    ll idx = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] != 'i'){
            (hash += ((s[i] - 'a' + 1) * p_pow[idx++])) %= m;
        }
        ans += s[i];
        ll val = query(i+1, n-1);
        if((hash * p_pow[n - 1]) % m == val){
            break;
        }
    }
    if(ans.size() == n){
        cout << "notpossible" << "\n";
        return;
    }
    cout << ans << "\n";
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