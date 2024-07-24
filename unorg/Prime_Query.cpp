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
    ll n;cin>>n;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    vector<vector<ll>> pre(n+1, vector<ll>(2, 0));
    for(ll i=0;i<n;i++){
        if(arr[i] == 1){
            pre[i+1][0]++;
        }
        if(arr[i] == 2){
            pre[i+1][1]++;
        }
    }
    for(ll i=2;i<=n;i++){
        pre[i][0] += pre[i-1][0];
        pre[i][1] += pre[i-1][1];
    }
    ll q;cin>>q;
    while(q--){
        ll l,r;cin>>l>>r;
        ll k;cin>>k;
        ll fre1 = pre[r][0] - pre[l-1][0];
        ll fre2 = pre[r][1] - pre[l-1][1];
        if(fre1 < fre2){
            swap(fre1, fre2);
        }
        ll maxi = r - l + 1 - fre1 - fre2;
        if(maxi >= k){
            if(fre1 - fre2 > k){
                fre2 += k;
            }
            else{
                k -= (fre1 - fre2);
                fre2 = fre1;
                fre1 += k/2;
                fre2 += k/2;
                if(k % 2){
                    fre1++;
                }
            }
        }
        else{
            if(fre1 - fre2 > maxi){
                fre2 += maxi;
                k -= maxi;
                ll x = fre1;
                ll y = fre2;
                fre1 -= min((x-y)/2, k);
                fre2 += min((x-y)/2, k);
            }
            else{
                k -= (fre1 - fre2);
                maxi -= (fre1 - fre2);
                fre2 = fre1;
                fre1 += maxi/2;
                fre2 += maxi/2;
                if(maxi % 2){
                    fre1++;
                }
            }
        }
        cout<<fre1 * fre2 <<"\n";

    }
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