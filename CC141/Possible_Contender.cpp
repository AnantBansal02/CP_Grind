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
    ll n; cin >> n;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    
    auto check = [&] (ll mid){
        ll i = 0;
        ll c1 = 0, c2 = 0;
        while(i < n){
            if(arr[i] < mid){
                while(i < n and arr[i] < mid){
                    i++;
                }
                c1++;
            }
            if(i < n) c2++;
            i++;
        }
        return c1 < c2;
    };
    
    ll low = 0;
    ll high = *max_element(all(arr));
    ll possible = 0;
    while(low <= high){
        ll mid = (low + high) >> 1;
        if(check(mid)){
            possible = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    for(auto it : arr){
        if(it <= possible){
            cout << '1';
        }
        else{
            cout << '0';
        }
    }
    cout << "\n";
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