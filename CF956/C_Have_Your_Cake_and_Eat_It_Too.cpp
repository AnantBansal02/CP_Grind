#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n; cin >> n;
    vector<vector<ll>> arr(3, vector<ll>(n));
    vector<vector<ll>> pre(3, vector<ll>(n+1));
    vector<vector<ll>> suff(3, vector<ll>(n+1));

    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < n; j++){
            cin >> arr[i][j];
            pre[i][j+1] = arr[i][j];
            suff[i][j+1] = arr[i][j];
        }
    }
    for(ll i = 0; i < 3; i++){
        for(ll j = 1; j <= n; j++){
            pre[i][j] += pre[i][j-1];
            // cout << pre[i][j] << " ";
        }
        // cout << "\n";
        for(ll j = n; j >= 1; j--){
            if(j + 1 <= n){
                suff[i][j] += suff[i][j+1];
            }
        }
    }
    ll tot = accumulate(all(arr[0]), 0LL);
    tot = (tot + 2)/ 3;
    ll la, ra, lb, rb, lc, rc;
    auto check = [&](ll idx1, ll j1, ll j2){
        vector<int> ans(5, 0);
        ll low = idx1 + 2;
        ll high = n;
        ll idx2 = -1;
        while(low <= high){
            ll mid = low + high >> 1;
            if(suff[j1][mid] >= tot){
                idx2 = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(idx2 != -1){
            // cout << idx1 << " " << idx2 << "\n";
            // cout << pre[j2][idx2-1] - pre[j2][idx1] << "\n";
            if(pre[j2][idx2-1] - pre[j2][idx1] >= tot){
                // dbg(idx2);  
                ans[0] = 1;
                ans[1] = idx2;
                ans[2] = n;
                ans[3] = idx1+1;
                ans[4] = idx2-1;
                return ans;
            }
        }
        low = idx1 + 2;
        high = n;
        idx2 = -1;
        while(low <= high){
            ll mid = low + high >> 1;
            if(suff[j2][mid] >= tot){
                idx2 = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(idx2 != -1){
            if(pre[j1][idx2-1] - pre[j1][idx1] >= tot){
                ans[0] = 1;
                ans[3] = idx2;
                ans[4] = n;
                ans[1] = idx1+1;
                ans[2] = idx2-1;
                return ans;
            }
        }
        return ans;
    };
    
    for(ll i = 1; i <= n; i++){
        if(pre[0][i] >= tot){
            auto vec = check(i, 1, 2);
            if(vec[0]){
                la = 1;lb = vec[1];lc = vec[3];
                ra = i;rb = vec[2];rc = vec[4];
                cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << "\n";
                return;
            }
        }
        if(pre[1][i] >= tot){
            auto vec = check(i, 0, 2);
            if(vec[0]){
                la = vec[1];lb = 1;lc = vec[3];
                ra = vec[2];rb = i;rc = vec[4];
                cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << "\n";
                return;
            }
        }
        if(pre[2][i] >= tot){
            auto vec = check(i, 0, 1);
            if(vec[0]){
                la = vec[1];lb = vec[3];lc = 1;
                ra = vec[2];rb = vec[4];rc = i;
                cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << "\n";
                return;
            }
        }
    }
    cout << "-1" << "\n";
}
int main()
{
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}