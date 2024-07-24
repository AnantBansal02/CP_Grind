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

vector<ll> arr, brr;
bool cmp(pair<ll,ll>&a, pair<ll,ll>& b){
    return a.first + arr[a.second] > b.first + arr[b.second];
}
void solve()
{
    ll n,k;cin>>n>>k;
    arr.resize(n);brr.resize(n);
    for(auto &it : arr){
        cin>>it;
    }
    for(auto &it : brr){
        cin>>it;
    }
    vector<pair<ll,ll>> diff(n);
    for(ll i=0;i<n;i++){
        diff[i] = {brr[i] - arr[i], i};
    }
    sort(all(diff), cmp);
    vector<ll> suff(n);
    suff[n-1] = max(0LL, diff[n-1].first);
    for(ll i=n-2;i>=0;i--){
        suff[i] = suff[i+1] + max(0LL, diff[i].first);
    }
    priority_queue<ll> pq;
    ll cost = 0;
    for(ll i=0;i<k;i++){
        pq.push(arr[diff[i].second]);
        cost += arr[diff[i].second];
    }
    ll ans = 0;
    for(ll i=k;i<n;i++){
        ans = max(ans, suff[i] - cost);
        if(!pq.empty() and pq.top() > arr[diff[i].second]){
            cost -= pq.top();
            pq.pop();
            pq.push(arr[diff[i].second]);
            cost += arr[diff[i].second];
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