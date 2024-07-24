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
    auto sum = [&] (ll num){
        return (num *(num + 1))/2;
    };
    ll n, k; cin >> n >> k;
    if(k % 2 == 1){
        cout << "No" << "\n";
        return;
    }
    vector<ll> ans(n);
    ll tot = 0;
    iota(ans.begin(), ans.end(), 1);
    ll mul = n - 1;
    for(ll i=n-1;i>=n/2 and k;i--){
        ll left = n - i - 1;
        // tot += 2*mul;
        // cout << tot << "\n";
        if(2*mul < k){
            k -= 2*mul;
            swap(ans[i], ans[left]);
        }
        else{
            for(ll j=i-1;j>=left;j--){
                k -= 2;
                if(k == 0){
                    swap(ans[i], ans[j]);
                    break;
                }
            }
            break;
        }
        mul -= 2;
    }
    if(k != 0){
        cout << "No" << "\n";
        return;
    }
    else{
        cout << "Yes" << "\n";
    }
    ll check = 0;
    for(ll i=1;i<=n;i++){
        check += abs(ans[i-1] - i);
        cout << ans[i-1] << " ";
    }
    cout << "\n";
    // cout << check << "\n";
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