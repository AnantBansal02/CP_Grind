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
    ll n, m; cin >> n >> m;
    vector<string> arr(n), brr(n);
    for(auto &it : arr){
        cin >> it;
    }
    for(auto &it : brr){
        cin >> it;
    }
    for(ll i = 0; i < n; i++){
        ll a = 0, b = 0;
        for(ll j = 0; j < m; j++){
            a += (arr[i][j] - '0');
            b += (brr[i][j] - '0');
        }
        if(a % 3 != b % 3){
            cout << "NO" << "\n";
            return;
        }
    }
    for(ll j = 0; j < m; j++){
        ll a = 0, b = 0;
        for(ll i = 0; i < n; i++){
            a += (arr[i][j] - '0');
            b += (brr[i][j] - '0');
        }
        if(a % 3 != b % 3){
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
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