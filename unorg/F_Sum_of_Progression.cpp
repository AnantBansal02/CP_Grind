#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp1[100001][322];
ll dp2[100001][322];
void solve()
{
    ll n,q;cin>>n>>q;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    ll fix = 1;
    while(fix*fix < n){
        fix++;
    }
    for(ll d = 1LL; d <= fix; d++){
        for(ll i=0LL;i<=d;i++){
            dp1[i][d] = 0LL;
            dp2[i][d] = 0LL;
        }
        for(ll i = 0; i < n; i++){
            ll mul = (i+1)/d;
            if((i+1)%d != 0LL){
                mul++;
            }
            if(i+1-d >= 0){
                dp1[i+1][d] = arr[i] + dp1[i+1-d][d];
                dp2[i+1][d] = mul*arr[i] + dp2[i+1-d][d];
            }
            else{
                dp1[i+1][d] = arr[i];
                dp2[i+1][d] = mul*arr[i];
            }
        }
    }
    while(q--){
        ll l, d, k;
        cin>>l>>d>>k;
        ll r = l + (k-1)*d;
        if(d <= fix){
            ll mul = l/d;
            if(l%d != 0LL){
                mul++;
            }
            cout<< (dp2[r][d] - dp2[max(0LL, l-d)][d]) - (mul-1)*(dp1[r][d] - dp1[max(0LL, l-d)][d]) << " ";
        }
        else{
            ll ans = 0; ll cnt = 1;
            for(ll i = l-1; i < r; i += d){
                ans += cnt*arr[i];
                cnt++;
            }
            cout<<ans<<" ";
        }
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}