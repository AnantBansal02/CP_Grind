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

ll lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

void solve()
{
    ll n;cin>>n;
    vector<ll> arr(n);
    map<ll,ll> mp;
    for(auto &it : arr){
        cin>>it;
        mp[it]++;
    } 
    ll maxi = *max_element(all(arr));
    for(ll i=0;i<n;i++){
        if(maxi % arr[i] != 0){
            cout<<n<<"\n";
            return;
        } 
    }
    vector<ll> vec;
    for(ll i=1;i*i<=maxi;i++){
        if(maxi % i == 0){
            if(mp.count(i) == 0){
                vec.pb(i);
            }
            if(mp.count(maxi/i) == 0){
                vec.pb(maxi/i);
            }
        }
    }
    ll ans = 0;
    for(auto it : vec){
        ll sz = 0;
        ll curr = 1;
        for(ll i=0;i<n;i++){
            if(it % arr[i] == 0){
                sz++;
                curr = lcm(curr, arr[i]);
            }
        }
        // cout<<it<<" "<<sz<<"\n";
        if(curr == it){
            ans = max(ans, sz);
        }
    }
    cout<<ans<<"\n";
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