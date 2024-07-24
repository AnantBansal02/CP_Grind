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
    ll N, K;cin>>N>>K;
    vector<ll> A(N);
    for(auto &it : A){
        cin>>it;
    }
    vector<ll> pre(N), suff(N);
    pre[0] = A[0];
    suff[N-1] = A[N-1];
    for(ll i=1;i<N;i++){
        pre[i] += pre[i-1] + A[i];
    }
    for(ll i=N-2;i>=0;i--){
        suff[i] += suff[i+1] + A[i];
    }
    ll first, last;
    if(K & 1){
        first = (K/2) + 1;
        last = K/2;
    }
    else{
        first = K/2;
        last = K/2;
    }
    ll i = -1, j = N;
    ll low = 0; 
    ll high = N-1;
    while(low <= high){
        ll mid = (low + high) >> 1;
        if(pre[mid] <= first){
            i = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    low = N-1; 
    high = 0;
    while(low >= high){
        ll mid = (low + high) >> 1;
        if(suff[mid] <= last){
            j = mid;
            low = mid - 1;
        }
        else{
            high = mid + 1;
        }
    }
    // dbg(i);dbg(j);
    ll ans = 0;
    ans += (i + 1);
    ans += (N - j);
    if(i >= j){
        ans -= (i - j + 1);
    }
    if(i < j and i + 1 == j - 1){
        first -= (i >= 0 ? pre[i] : 0LL);
        last -= (j < N ? suff[j] : 0LL);
        if(first + last >= A[i+1]){
            ans++;
        }
    }
    cout<<ans<<"\n";
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