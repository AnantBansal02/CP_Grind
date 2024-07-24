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
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) cin >> arr[i];
    if(count(all(arr), arr[0]) == n){
        cout << "NO" << "\n";
        return;
    }
    string ans(n, 'B');
    ll flag = 0;
    for(ll i=1;i<n;i++){
        if(arr[i] == arr[i-1]){
            ans[i] = 'R';
            flag = 1;
            break;
        }
    }
    if(!flag){
        ans[n-1] = 'R';
    }
    cout << "YES" << "\n";
    cout << ans << "\n";
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