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
    ll i = 0;
    ll cnt0 = 0, cnt1 = 0;
    string fin = "";
    while(i < n){
        ll cnt = 0;
        while(i < n and s[i] == '0'){
            i++;
            cnt++;
        }
        if(cnt){
            cnt0++;
        }
        if(i < n){
            cnt1++;
            i++;
        }
    }   
    cout << (cnt1 > cnt0 ? "YES" : "NO" )<< "\n";
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