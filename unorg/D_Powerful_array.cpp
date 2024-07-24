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
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    vector<vector<ll>> queries(q, vector<ll>(3));
    for(ll i=0;i<q;i++){
        cin >> queries[i][0] >> queries[i][1];
        queries[i][2] = i;
    } 
    const ll sz = 450;
    sort(all(queries), [&](vector<ll>&a, vector<ll>&b){
        return (a[0] / sz) < (b[0] / sz);
    });
    vector<ll> ans(q);
    ll left = 0, right = -1;
    vector<ll> mp(1e6 + 1, 0);
    ll curr = 0;
    for(auto it : queries){
        ll l = it[0] - 1;
        ll r = it[1] - 1;
        while(right < r){
            right++;
            ll num = arr[right];
            ll prev = mp[num];
            mp[num]++;
            ll now = mp[num];
            curr -= prev * prev * num;
            curr += now * now * num;
        }
        while(left < l){
            ll num = arr[left];
            ll prev = mp[num];
            mp[num]--;
            ll now = mp[num];
            curr -= prev * prev * num;
            curr += now * now * num;
            left++;
        }
        while(right > r){
            ll num = arr[right];
            ll prev = mp[num];
            mp[num]--;
            ll now = mp[num];
            curr -= prev * prev * num;
            curr += now * now * num;
            right--;
        }
        while(left > l){
            left--;
            ll num = arr[left];
            ll prev = mp[num];
            mp[num]++;
            ll now = mp[num];
            curr -= prev * prev * num;
            curr += now * now * num;
        }
        ans[it[2]] = curr;
    }

    for(auto it : ans){
        cout << it << "\n";
    }

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