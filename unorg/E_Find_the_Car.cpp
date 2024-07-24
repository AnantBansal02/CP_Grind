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
    ll n,k,q;cin>>n>>k>>q;
    vector<ll> arr(k), brr(k);
    for(auto &it : arr){
        cin>>it;
    }
    for(auto &it : brr){
        cin>>it;
    }
    for(ll i=0;i<q;i++){
        ll a;cin>>a;
        // cout<<a<<"\n";
        ll low = 0;
        ll high = k-1;
        ll idx = -1;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(arr[mid] >= a){
                idx = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        assert(idx != -1);
        // cout<<idx<<"\n";
        if (arr[idx] == a) {
            cout << brr[idx] << " ";
        } else {
            ll prev = 0;
            if (idx != 0) {
                prev = brr[idx - 1];
            }
            ll prev2 = 0;
            if (idx != 0) {
                prev2 = arr[idx - 1];
            }
            cout << prev +  (((a - prev2)*(brr[idx] - prev))/(arr[idx] - prev2)) << " ";
        }
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}