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
    ll ans = 0;
    ll i = 0;
    while(i < n){
        if(arr[i] == 0){
            i++;
            continue;
        }
        if(arr[i] > 2){
            ans++;
            i++;
            continue;
        }
        ll start = i;
        i++;
        ll len1 = 0, len2 = 1;
        while(i < n and arr[i] > 0 and arr[i] <= 4){
            if(arr[i] <= 2){
                if(len1 % 2 == 0){
                    len1 = 0;
                    len2++;
                }
                else{
                    break;
                }
            }
            if(arr[i] > 2){
                len1++;
            }
            i++;
        }
        ll len = i - start;
        ans += (len - (len2/2));
    }
    cout << ans << "\n";
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