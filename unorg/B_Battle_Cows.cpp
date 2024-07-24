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
    ll N,K;cin>>N>>K;
    K--;
    vector<ll> arr(N);
    for(auto &it : arr){
        cin>>it;
    }  
    vector<ll> pre(N);
    pre[0] = arr[0];
    for(ll i=1;i<N;i++){
        pre[i] = max(pre[i-1], arr[i]);
    }
    ll maxi = 0;
    if(pre[K] <= arr[K]){
        if(K != 0){
            maxi++;
        }
        for(ll i=K+1;i<N;i++){
            if(arr[i] > arr[K]){
                break;
            }
            else{
                maxi++;
            }
        }
    }
    ll idx = -1;
    for(ll i=0;i<N;i++){
        if(arr[i] > arr[K]){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        maxi = max(maxi, N - 1);
    }
    else{
        swap(arr[0], arr[K]);
        ll cnt = 0;
        for(ll i=1;i<N;i++){
            if(arr[i] > arr[0]){
                break;
            }
            else{
                cnt++;
            }
        }
        maxi = max(maxi, cnt);
        swap(arr[0], arr[K]);
        swap(arr[idx], arr[K]);
        cnt = 0;
        for(ll i=0;i<idx;i++){
            if(arr[i] > arr[idx]){
                cnt = -INF;
            }
        }
        if(idx > 0){
            cnt++;
        }
        for(ll i=idx+1;i<N;i++){
            if(arr[i] > arr[idx]){
                break;
            }
            else{
                cnt++;
            }
        }
        maxi = max(maxi, cnt);
    }
    cout<<maxi<<"\n";
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