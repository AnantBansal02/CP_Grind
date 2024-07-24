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
    ll n, c; cin >> n >> c;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    if(n == 1){
        cout << 0 << "\n";
        return;
    }
    vector<ll> pre(n), suff(n), sum(n);
    pre[0] = arr[0];
    sum[0] = arr[0];
    suff[n-1] = arr[n-1];
    for(ll i=1;i<n;i++){
        pre[i] = max(pre[i-1], arr[i]);
        sum[i] += sum[i-1] + arr[i];
    }
    for(ll i=n-2;i>=0;i--){
        suff[i] = max(suff[i+1], arr[i]);
    }
    vector<ll> ans(n);
    {
        if(arr[0] + c < suff[1]){
            priority_queue<ll> pq;
            for(ll i=1;i<n;i++){
                pq.push(arr[i]);
            }
            ll temp = c, cnt = 0;
            while(!pq.empty() and arr[0] + temp < pq.top()){
                auto it = pq.top();pq.pop();
                temp += it;
                cnt++;
            }
            ans[0] = cnt;
        }   
        else{
            ans[0] = 0;
        }
    }
    for(ll i=1;i<n;i++){
        if(arr[i] >= suff[i] and (arr[i] > pre[i-1]) and (arr[i] > (arr[0] + c))){
            ans[i] = 0;
        }
        else{
            ans[i] += i;
            if(i + 1 < n and sum[i] + c < suff[i+1]){
                ans[i]++;
            }
        }
    } 
    for(auto it : ans){
        cout << it << " ";
    }
    cout << "\n";
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