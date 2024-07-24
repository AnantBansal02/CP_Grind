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
    vector<string> arr(n);
    for(auto &it : arr){
        cin >> it;
    }
    vector<ll> vec(n);
    for(int i=0;i<n;i++){
        ll cnt = 0;
        for(int j=0;j<m;j++){
            if(arr[i][j] == '#'){
                cnt++;
            }
        }
        vec[i] = cnt;
    }
    for(int i=0;i<n;i++){
        ll prev;
        if(i == 0) prev = 0;
        else prev = vec[i-1];
        ll next;
        if(i == n-1) next = 0;
        else next = vec[i+1];
        if(vec[i] > prev and vec[i] > next){
            ll cnt = 0;
            for(int j=0;j<m;j++){
                if(arr[i][j] == '#'){
                    cnt++;
                    if(cnt == vec[i]/2 + 1){
                        cout << i+1 << " " << j+1 << "\n";
                        return;
                    }
                }
            }
        }
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