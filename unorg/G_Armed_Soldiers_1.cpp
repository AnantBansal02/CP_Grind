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

ll N, K;
vector<pair<ll,ll>> arr;

bool check(ll mid){
    map<ll, ll> mp;
    for(ll i=0;i<N;i++){
        if(arr[i].second >= mid){
            mp[arr[i].first - (arr[i].second - mid)]++;
            mp[arr[i].first + (arr[i].second - mid) + 1]--;
        }
    }
    ll maxi = 0;
    ll curr = 0;
    for(auto it : mp){
        curr += it.second;
        maxi = max(maxi, curr);
    }
    // cout<<mid<<" "<<maxi<<"\n";
    return maxi <= K;
}
void solve()
{
    cin>>N>>K;
    arr = vector<pair<ll,ll>> (N);
    for(ll i=0;i<N;i++){
        cin>>arr[i].first;
    }
    for(ll i=0;i<N;i++){
        cin>>arr[i].second;
    }
    sort(all(arr));
    // check(0);
    ll low = 0;
    ll high = 1e9;
    ll ans = INT_MAX;
    while(low <= high){
        ll mid = (low + high) >> 1;
        if(check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
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