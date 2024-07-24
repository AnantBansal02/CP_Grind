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
    vector<ll> A(n), B(n);
    for(auto &it : A) cin >> it;
    for(auto &it : B) cin >> it;
    map<ll,ll> mp;
    for(ll i = 0; i < n; i++){
        mp[B[i]] = i;
    }
    vector<ll> a = A, b = B;
    sort(all(a));sort(all(b));
    for(ll i = 0; i < n; i++){
        if(a[i] != b[i]){
            cout << "NO" << "\n";
            return;
        }
    }
    int tot = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            tot++;
            ll idx = mp[A[i]];
            swap(B[i], B[idx]);
            mp[B[idx]] = idx;
            mp[A[i]] = i;
        }
    }
    if(tot%2 == 0){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
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
