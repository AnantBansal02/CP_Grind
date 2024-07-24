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
    ll n;cin>>n;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    ll i = 0;
    ll maxi = 0;
    while(i < n){
        ll cnt = 0;
        while(i < n and arr[i] % 2 == 1){
            i++;
            cnt++;
        }
        maxi = max(maxi, cnt);
        i++;
    }
    i = 0;
    while(i < n){
        ll cnt = 0;
        ll start = i;
        while(i < n and arr[i] % 2 == 1){
            i++;
            cnt++;
        }
        if(cnt == maxi and maxi != 0){
            arr[(start + i-1)/2] += 1;
            break;
        }
        i++;
    }
    vector<ll> next(n, 0);
    ll dist = -1;
    for(ll i=n-1;i>=0;i--){
        if(arr[i] % 2 == 0){
            dist = 1;
        }
        else{
            next[i] = dist;
            if(dist > 0){
                dist++;
            }
        }
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(arr[i] % 2 == 0){
            ans += n - i;
        }
        else if(next[i] != -1){
            ans += n - i - next[i];
        }
    }
    cout<<ans<<"\n";
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