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

bool cmp(pair<string,ll>&A, pair<string,ll> &B){
    string a = A.first;
    string b = B.first;
    ll n = min(a.size(), b.size());
    for(ll i=0;i<n;i++){
        if(a[i] != b[i]){
            return a[i] < b[i];
        }
    }
    return (ll)a.size() < (ll)b.size();
}
void solve()
{
    ll n;cin>>n;
    vector<pair<string,ll>> arr(n);
    ll sum = 0;
    for(ll i=0;i<n;i++){
        string s;cin>>s;
        ll a;cin>>a;
        sum += a;
        arr[i] = {s, a};
    }
    sort(all(arr), cmp);
    cout<<arr[sum%n].first<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}