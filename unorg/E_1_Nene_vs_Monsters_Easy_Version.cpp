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
    while(1){
        bool flag = true;
        for(ll i=0;i<n;i++){
            if(arr[i] > 0 and arr[(i+1)%n] > 0 and arr[(i+2)%n] > 0){
                flag = false;
            }
            if(arr[(i+1)%n] > 0){
                arr[(i+1)%n] -= min(arr[(i+1)%n], arr[i]);
            }
        }
        if(flag){
            break;
        }
    } 
    // for(auto it : arr){
    //     cout<<it<<" ";
    // }
    // cout<<"\n";
    vector<ll> ans;
    for(ll i=0;i<n;i++){
        if(arr[i] > 0 and arr[(i+1)%n] > 0){
            arr[(i+1)%n] = 0;
        }
    }
    for(ll i=0;i<n;i++){
        if(arr[i]){
            ans.pb(i);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto it : ans){
        cout<<it+1<<" ";
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