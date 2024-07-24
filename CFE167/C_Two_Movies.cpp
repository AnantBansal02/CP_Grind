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

void solve(ll t)
{
    ll n; cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(2));
    for(ll i = 0; i < n; i++){
        cin >> arr[i][0];
    }
    for(ll i = 0; i < n; i++){
        cin >> arr[i][1];
    }
    ll a = 0, b = 0;
    for(ll i = 0; i < n; i++){
        if(arr[i][0] == -1 and arr[i][1] == -1){
            continue;
        }
        if(arr[i][0] == 1 and arr[i][1] == 1){
            continue;
        }
        if(arr[i][0] == 1){
            a++;
        }
        else if(arr[i][1] == 1){
            b++;
        }
    }
    for(ll i = 0; i < n; i++){
        if(arr[i][0] == -1 and arr[i][1] == -1){
            if(a > b){
                a--;
            }
            else{
                b--;
            }
        }
    }
    for(ll i = 0; i < n; i++){
        if(arr[i][0] == 1 and arr[i][1] == 1){
            if(a > b){
                b++;
            }
            else{
                a++;
            }
        }
    }
    cout << min(a, b) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    for(ll i =1; i <= t; i++){
        solve(i);
    }
    return 0;
}