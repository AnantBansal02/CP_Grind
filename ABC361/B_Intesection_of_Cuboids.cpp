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
    vector<vector<ll>> arr(2, vector<ll>(6));
    for(ll i = 0; i < 2; i++){
        for(ll j = 0; j < 6; j++){
            cin >> arr[i][j];
        }
    }
    ll cnt = 0;
    if(arr[1][0] < arr[0][3] and (arr[1][0] >= arr[0][0] || arr[1][3] > arr[0][0])){
        cnt++;
    }
    if(arr[1][1] < arr[0][4] and (arr[1][1] >= arr[0][1] || arr[1][4] > arr[0][1])){
        cnt++;
    }
    if(arr[1][2] < arr[0][5] and (arr[1][2] >= arr[0][2] || arr[1][5] > arr[0][2])){
        cnt++;
    }
    if(cnt == 3){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
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