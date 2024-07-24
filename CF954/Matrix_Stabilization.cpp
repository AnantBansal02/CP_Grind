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
    vector<vector<ll>> arr(n, vector<ll>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }   
    vector<ll> di = {-1, 1, 0, 0};
    vector<ll> dj = {0, 0, -1, 1};
    auto check = [&] (ll i, ll j){
        ll maxi = -INF;
        for(ll d=0;d<4;d++){
            ll ni = i + di[d];
            ll nj = j + dj[d];
            if(ni < 0 || nj < 0 || ni >= n || nj >= m){
                continue;
            }
            if(arr[i][j] <= arr[ni][nj]){
                return false;
            }
            maxi = max(maxi, arr[ni][nj]);
        }
        arr[i][j] = maxi;
        return true;
    };
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            check(i, j);
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
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