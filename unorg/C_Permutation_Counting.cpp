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
    ll n,k;cin>>n>>k;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    sort(all(arr));
    function<bool(ll)> check = [&] (ll mid) -> bool {
        ll minlen = (mid + n - 1);
        ll fre = minlen / n;
        ll cnt = minlen % n;
        ll curr = 0;
        for(ll i=0;i<n;i++){
            if(arr[i] < fre){
                curr += fre - arr[i];
            }
            else if(arr[i] > fre){
                if(cnt > 0){
                    cnt--;
                }
            }
        }
        return curr + cnt <= k;
    };
    ll low = 0;
    ll high = 1e18;
    while(low <= high){
        ll mid = (low + high) >> 1;
        if(check(mid)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<low - 1<<"\n";
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