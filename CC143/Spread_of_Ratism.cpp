#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout << #x << " = " << x << "\n"
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define all(x) (x).begin(), (x).end()
#define set_bits(x) __builtin_popcntll(x)

void solve()
{
    ll n; cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(3));
    for(ll i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }   
    sort(all(arr), [&](vector<ll>&a, vector<ll>&b){
        if(a[0] != b[0]){
            return a[0] < b[0];
        }
        return a[1] < b[1];
    });
    vector<ll> ans(n);
    ll mini = arr[0][0];
    ll maxi = arr[0][1];
    ll cnt = 1;
    ll low = 0;

    for (ll i = 1; i < n; ++i) {
        if (arr[i][1] < maxi || arr[i][0] < maxi) {
            ++cnt;
            mini = min(mini, arr[i][0]);
            maxi = max(maxi, arr[i][1]);
        } 
        else {
            mini = arr[i][0];
            maxi = arr[i][1];
            for (ll j = low; j < i; ++j) {
                ans[arr[j][2]] = cnt;
            }
            cnt = 1;
            low = i;
            
        }   
    }
    for (ll j = low; j < n; ++j) {
        ans[arr[j][2]] = cnt;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n-1];
    }

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