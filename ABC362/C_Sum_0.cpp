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
    ll n; cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(2));
    for(ll i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    ll psum = 0, nsum = 0;
    for(ll i = 0; i < n; i++){
        if(arr[i][0] > 0){
            psum += arr[i][0];
        }
        if(arr[i][1] < 0){
            nsum -= arr[i][1];
        }
    }
    vector<ll> ans;
    if(psum > nsum){
        ll diff = psum - nsum;
        for(ll i = 0; i < n; i++){
            if(arr[i][0] > 0){
                ans.pb(arr[i][0]);
            }
            else{
                if(arr[i][1] < 0){
                    if(diff){
                        if(arr[i][1] - arr[i][0] > diff){
                            ans.pb(arr[i][1] - diff);
                            diff = 0;
                        }
                        else{
                            diff -= (arr[i][1] - arr[i][0]);
                            ans.pb(arr[i][0]);
                        }
                    }
                    else{
                        ans.pb(arr[i][1]);
                    }
                }
                else{
                    if(diff){
                        if(-arr[i][0] > diff){
                            ans.pb(-diff);
                            diff = 0;
                        }
                        else{
                            diff -= (-arr[i][0]);
                            ans.pb(arr[i][0]);
                        }
                    }
                    else{
                        ans.pb(0);
                    }
                }
            }
        }
    }  
    else{
        ll diff = nsum - psum;
        for(ll i = 0; i < n; i++){
            if(arr[i][1] < 0){
                ans.pb(arr[i][1]);
            }
            else{
                if(arr[i][0] > 0){
                    if(diff){
                        if(arr[i][1] - arr[i][0] > diff){
                            ans.pb(arr[i][0] + diff);
                            diff = 0;
                        }
                        else{
                            diff -= (arr[i][1] - arr[i][0]);
                            ans.pb(arr[i][1]);
                        }
                    }
                    else{
                        ans.pb(arr[i][0]);
                    }
                }
                else{
                    if(diff){
                        if(arr[i][1] > diff){
                            ans.pb(diff);
                            diff = 0;
                        }
                        else{
                            diff -= (arr[i][1]);
                            ans.pb(arr[i][1]);
                        }
                    }
                    else{
                        ans.pb(0);
                    }
                }
            }
        }
    }
    if(accumulate(all(ans), 0LL) == 0LL){
        cout << "Yes" << "\n";
        for(auto it : ans){
            cout << it << " ";
        }
    }
    else{
        cout << "No" << '\n';
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