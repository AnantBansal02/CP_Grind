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

    auto sum = [&](ll num){
        return (num * (num + 1)) / 2;
    };
    ll n, a, b; cin >> n >> a >> b;
    if(b >= a){
        ll diff = b - a;
        if(diff >= n){
            cout << sum(b) - sum(b - n) << "\n";
        }   
        else{
            cout << sum(b) - sum(a) + (n - diff) * a << "\n";
        }
    }
    else{
        cout << n * a << "\n";
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