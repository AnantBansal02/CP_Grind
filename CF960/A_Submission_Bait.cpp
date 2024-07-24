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
    sort(all(arr));
    map<ll,ll> mp;
    ll cnt = 0;
    for(ll i = n-1; i >= 0; i--){
        if(arr[i] == arr[n-1]){
            cnt++;
        }
        mp[arr[i]]++;
    }
    if(cnt & 1){
        cout << "YES" << "\n";
        return;
    }
    for(auto it : mp){
        if(it.se & 1){
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
    
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