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
    ll last = 0;
    ll idx = -1;
    bool flag = false;
    for(ll i=0;i<n-1;i++){
        if(__gcd(arr[i], arr[i+1]) < last){
            idx = i;
            break;
        }
        else if(__gcd(arr[i], arr[i+1]) == last){
            flag = true;
        }

        last = __gcd(arr[i], arr[i+1]);
    }
    if(idx == -1 and flag){
        cout<<"YES"<<"\n";
        return;
    }
    auto check = [&] (ll val){
        if(val < 0 || val >= n){
            return false;
        }
        vector<ll> temp;
        for(ll i=0;i<n-1;i++){
            if(i+1 == val){
                if(i + 2 < n ) temp.pb(__gcd(arr[i], arr[i+2]));
            }
            else if(i == val){
                continue;
            }
            else {
                temp.pb(__gcd(arr[i], arr[i+1]));
            }
        }
        // cout<<val<<"\n";
        // for(auto it : temp){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        return is_sorted(all(temp));
    };
    // cout<<idx<<"\n";
    if(check(idx) || check(idx-1) || check(idx+1)){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
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