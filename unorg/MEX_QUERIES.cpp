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
    vector<ll> arr(n+1);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    arr[n] = 0;n++;
    vector<ll> ans(n, -1);
    ll curr = 0;
    for(ll i=0;i<n;i++){
        ans[i] = curr + arr[i];
        if(arr[i] > 0){
            arr[i]--;
            continue;
        }
        ll idx = i;
        ll flag = false;
        while(idx > 0){
            idx /= 2;
            curr++;
            if(arr[idx] > 0){
                arr[idx]--;
                flag = true;
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<"\n";

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