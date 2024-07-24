#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;cin>>t;
    while(t--){
        ll m, n;cin>>m>>n;
        vector<vector<ll>> arr(n, vector<ll>(2));
        for(ll i=0;i<n;i++){
            cin>>arr[i][0];
            arr[i][0]--;
        }
        for(ll i=0;i<n;i++){
            cin>>arr[i][1];
            arr[i][1]--;
        }
        vector<ll> pre(2*m-1, 0);
        ll fix = 0;
        for(ll i=0;i<n;i++){
            ll a = arr[i][0];
            ll b = arr[i][1];
            if(b > a){
                if(b > a + m/2){
                    fix++;
                    continue;
                }
                // cout<<a<<" "<<b<<"\n";
                pre[a]++;
                pre[b]--;
            }
            else{
                ll a = arr[i][0];
                ll b = arr[i][1];
                b += m;
                if(b > (a + m/2)){
                    fix++;
                    continue;
                }
                // cout<<a<<" "<<b<<"\n";
                pre[a]++;
                pre[b]--;
            }
        }
        for(ll i=1;i<2*m-1;i++){
            pre[i] += pre[i-1];
        }
        for(ll i=m;i<2*m-1;i++){
            pre[i-m] += pre[i];
        }
        pre.resize(m);
        // for(auto it : pre){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        ll ans = INT_MIN;
        for(ll i=0;i<=m/2;i++){
            if(m & 1){
                ans = max(ans, fix + pre[i] + pre[(i+m/2)%m]);
                ans = max(ans, fix + pre[i] + pre[(i+1 + m/2)%m]);
            }
            else{
                ans = max(ans, fix + pre[i] + pre[(i+m/2)%m]);
            }
        }
        cout<<ans<<"\n";
    }

}
