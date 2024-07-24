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
    string s;cin>>s;
    if(n == 1){
        cout<<"Bob"<<"\n";
        return;
    }
    ll cnt1 = 0, cnt0 = 0;
    for(ll i=0;i<n;i++){
        if(s[i] == '1'){
            cnt1++;
        }
        else{
            cnt0++;
        }
    } 
    bool flag = true;
    while((cnt1 + cnt0) >= 3){
        // cout<<cnt1<<" "<<cnt0<<"\n";
        if(flag){
            if(cnt1 < cnt0){
                swap(cnt1, cnt0);
            }
            if(cnt1 % 2 == 1 and cnt0 % 2 == 1){
                cnt0--;
            }
            else if(cnt1 % 2 == 0 and cnt0 % 2 == 1){
                cnt0--;
            }
            else if(cnt1 % 2 == 1 and cnt0 % 2 == 0){
                cnt1--;
            }
            else{
                cnt1--;
            }
            flag = false;
        }
        else{
            if(cnt1 < cnt0){
                swap(cnt1, cnt0);
            }
            if(cnt1 % 2 == 1 and cnt0 % 2 == 1){
                cnt0--;
            }
            else if(cnt1 % 2 == 0 and cnt0 % 2 == 1){
                cnt0--;
            }
            else if(cnt1 % 2 == 1 and cnt0 % 2 == 0){
                cnt1--;
            }
            else{
                cnt1--;
            }
            flag = true;
        }
    }
    if(cnt1 == cnt0){
        if(flag){
            cout<<"Bob"<<"\n";
        }
        else{
            cout<<"Alice"<<"\n";
        }
    }
    else{
        if(flag){
            cout<<"Alice"<<"\n";
        }
        else{
            cout<<"Bob"<<"\n";
        }
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