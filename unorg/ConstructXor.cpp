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
    ll n,s;cin>>n>>s;
    if((s & 1) ||  n == 1 || s < n){
        cout<<"-1"<<"\n";
        return;
    }
    // map<ll,ll> mp;
    // mp[0] += s;
    // for(ll i=0;i<60;i++){
    //     while(mp[i] > 2){
    //         mp[i] -= 2;
    //         mp[i+1]++;
    //     }
    //     if(mp[i+1] % 2 == 1){
    //         mp[i] += 2;
    //         if(mp[i] > n){
    //             cout<<"-1"<<"\n";
    //             return;
    //         }
    //         mp[i+1]--;
    //     }
    // }
    // vector<ll> arr(n, 0);
    // ll idx = 0;
    // for(auto it : mp){
    //     // cout<<it.first<<" "<<it.second<<"\n";
    //     ll temp = it.second;
    //     while(temp--){
    //         arr[idx] = arr[idx] + (1LL << it.first);
    //         idx = (idx + 1)%n;
    //     }
    // }
    // for(auto it : arr){
    //     cout<<it<<" ";
    // }
    // cout<<"\n";
    // return;
    if(n & 1){
        vector<ll> ans(n, 0);
        for(ll i=3;i<n;i++){
            ans[i] = 1;
        }
        s -= (n - 3);
        s /= 2;
        if(set_bits(s) <= 1 and (s < 3 || n == 3)){
            cout<<"-1"<<"\n";
            return;
        }
        if(set_bits(s) == 1){
            for(ll i=32;i>=0;i--){
                if((1LL << i) & s){
                    ans[0] = ans[1] = ans[2] = (1LL << (i - 1));
                    ans[3] ^= (1LL << (i - 1));
                    s ^= (1LL << i);
                    break;
                }
            }
            for(auto it : ans){
                cout<<it<<" ";
            }
            cout<<"\n";
            return;
        }
        for(ll i=32;i>=0;i--){
            if((1LL << i) & s){
                ans[1] = ans[2] = (1LL << i);
                s ^= (1LL << i);
                ans[0] ^= s;
                ans[1] ^= s;
                break;
            }
        }
        
        for(auto it : ans){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    else{
        s -= n - 2;
        for(ll i=0;i<n-2;i++){
            cout<<1<<" ";
        }
        cout<<s/2<<" "<<s/2<<"\n";
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