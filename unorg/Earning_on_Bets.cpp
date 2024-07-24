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

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
ll findlcm(vector<ll>& arr)
{   
    ll n = arr.size();
    ll ans = arr[0];
    for (ll i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));
 
    return ans;
}
void solve()
{
    ll n; cin >> n;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    ll lcm = findlcm(arr);
    ll sum = 0;
    for(ll i=0;i<n;i++){
        sum += lcm / arr[i];
    }
    if(sum >= lcm){
        cout << "-1" << "\n";
        return;
    }
    for(ll i=0;i<n;i++){
        cout<<lcm/arr[i]<<" ";
    }
    cout<<"\n";
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