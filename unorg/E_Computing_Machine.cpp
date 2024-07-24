# pragma GCC optimize("-Ofast")
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
    string a, b; cin >> a >> b;
    vector<ll> possible(n+1, 0), done(n+1, 0);
    for(ll i=1;i<n-1;i++){
        if(a[i-1] == '0' and a[i+1] == '0' and b[i] != '1'){
            possible[i+1] = 1;
            b[i] = '1';
        }
    }
    vector<ll> pre(n+1, 0);
    pre[1] = a[0] == '1' ? 1 : 0;
    for(ll i=1;i<n-1;i++){
        if(b[i-1] == '1' and b[i+1] == '1' and a[i] == '0'){
            done[i+1] = 1;
            pre[i+1]++;
        }
        else if(a[i] == '1'){
            pre[i+1]++;
        }
        pre[i+1] += pre[i];
    }
    pre[n] = pre[n-1] + (a[n-1] == '1' ? 1 : 0);
    // for(ll i = 1; i <= n; i++){
    //     cout << pre[i] << " ";
    // }
    // cout << "\n";
    ll q; cin >> q;
    while(q--){
        ll l, r; cin >> l >> r;
        ll ans = 0;
        if(r - l + 1 <= 2){
            for(ll i=l;i<=r;i++){
                ans += a[i-1] - '0';
            }
        }
        else{
            ans = pre[r] - pre[l-1];
            if(done[l]) ans--;
            if(done[r]) ans--;
            bool flag1 = false, flag2 = false;
            if(possible[l] and done[l+1]){ans--; flag1 = true;}
            if(possible[r] and done[r-1]){ans--; flag2 = true;}
            if(l+1 == r-1 and flag1 and flag2) ans++;
        }
        cout << ans << "\n";
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