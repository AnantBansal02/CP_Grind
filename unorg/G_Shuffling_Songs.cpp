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

const ll p = 269;
const ll m = 1e9 + 7;
ll calc(string const& s) {
    ll n = s.size();
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (ll i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<ll> h(n + 1, 0);
    for (ll i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    return h[n];
}  
void solve()
{
    ll n;cin>>n;
    vector<vector<string>> temp(n, vector<string>(2));
    for(ll i=0;i<n;i++){
        cin>>temp[i][0];
        cin>>temp[i][1];
    }  
    vector<vector<ll>> arr(n, vector<ll>(2));
    for(ll i=0;i<n;i++){
        arr[i][0] = calc(temp[i][0]);
        arr[i][1] = calc(temp[i][1]);
    }
    vector<vector<ll>> dp((1 << n), vector<ll>(n, 0));
    for(ll i=0;i<n;i++){
        dp[(1 << i)][i] = 1;
    }
    for(ll mask=0;mask<(1 << n);mask++){
        for(ll lst=0;lst<n;lst++){
            if(!dp[mask][lst]) continue;
            for(ll i=0;i<n;i++){
                if((1 << i) & mask) continue;
                if(arr[lst][0] == arr[i][0] || arr[lst][1] == arr[i][1]){
                    dp[mask | (1 << i)][i] |= dp[mask][lst];
                }
            }
        }
    }
    ll len = 0;
    for(ll mask=0;mask<(1 << n);mask++){
        for(ll i=0;i<n;i++){
            if(dp[mask][i]){
                len = max(len, (ll)set_bits(mask));
            }
        }
    }
    cout<<n - len<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}