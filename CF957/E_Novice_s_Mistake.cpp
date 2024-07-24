// #pragma GCC optimize("-Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define dbg(x) cout << #x << " = " << x << "\n"
// #define pb push_back
// #define fi first
// #define se second
// #define INF 1e18
// #define all(x) (x).begin(), (x).end()
// #define set_bits(x) __builtin_popcountll(x)

// void solve()
// {
//     ll n; cin >> n;
//     if(n == 1){
//         cout<<9999<<endl;
//         for(int i=2;i<10001;i++){
//             cout<<i<<" "<<i-1<<endl;
//         }
//         return;
//     }
//     auto calc = [&](ll val){
//         return (ll)floor(log10(val)) + 1;
//     };
//     string num = "";
//     string extra = to_string(n);
//     for(ll i = 0; i < 10000; i++){
//         num += extra;
//     }
//     vector<vector<ll>> ans;
//     for(ll i = 1; i <= 10000; i++){
//         ll mul = n * i;
//         for(ll len = 1; len <= 20; len++){
//             ll curr = mul - i*calc(n) + len;
//             if(curr <= n) continue;
//             string s = to_string(curr);
//             if(s.size() != len) continue;
//             ll sz = s.size();
//             ll f = 1;
//             if(num.substr(0, sz) != s){
//                 f = 0;
//             }
//             if(f and i*calc(n) - len <= min(10000LL, mul)){
//                 ans.pb({i, i*calc(n) - len});
//             }
//         }
//     }
//     cout << ans.size() << '\n';
//     for(auto it : ans){
//         cout << it[0] << " " << it[1] << "\n";
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // factorial(1e5,1e9+7);
//     // sieve(1e5);
//     ll t = 1;
//     cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }

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
    if(n == 1){
        cout<<9999<<endl;
        for(int i=2;i<10001;i++){
            cout<<i<<" "<<i-1<<endl;
        }
        return;
    }
    auto calc = [&](ll val){
        return (ll)floor(log10(val)) + 1;
    };
    string num = "";
    string extra = to_string(n);
    for(ll i = 0; i < 50; i++){
        num += extra;
    }
    vector<vector<ll>> ans;
    for(ll len = 1; len <= 10; len++){
        string curr = num.substr(0, len);
        if(len <= calc(n)) continue;
        ll req = stoll(curr);
        // n * x - (x*val - len) == req;
        ll div = (n - calc(n));
        if(div <= 0) continue;
        if((req - len) % div == 0){
            ll x = (req - len)/ div;
            if(x > 10000){
                break;
            }
            if((x * calc(n) - len) <= min(10000LL, n * x)){
                ans.pb({x, x*calc(n) - len});
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto it : ans){
        cout << it[0] << " " << it[1] << "\n";
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