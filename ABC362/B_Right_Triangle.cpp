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
    auto dis = [&](ll a, ll b, ll c, ll d){
        return  (a - c)*(a - c) + (b - d)*(b - d);
    };
    vector<vector<ll>> arr(3, vector<ll>(2));   
    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < 2; j++){
            cin >> arr[i][j];
        }
    }
    vector<ll> a = {0, 1, 2};
    do {
        ll first = dis(arr[a[0]][0], arr[a[0]][1], arr[a[1]][0], arr[a[1]][1]);
        ll second = dis(arr[a[1]][0], arr[a[1]][1], arr[a[2]][0], arr[a[2]][1]);
        ll third = dis(arr[a[0]][0], arr[a[0]][1], arr[a[2]][0], arr[a[2]][1]);
        if(first + second == third){
            cout << "Yes" << "\n";
            return;
        }
    } while (next_permutation(all(a)));

    cout << "No" << "\n";
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