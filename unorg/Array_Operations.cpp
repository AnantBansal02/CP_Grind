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

ll n,k;
vector<ll> arr;
    
bool check(ll mid){
    vector<ll> temp = arr;
    ll sum = 0;
    ll pow = 0;
    ll req = 0;
    for(ll i=0;i<n;i++){
        if(temp[i] % k != 0 and temp[i] >= mid){
            sum++;
        }
        else if(temp[i] % k == 0){
            if(temp[i] >= mid){
                sum++;
                while(temp[i]/k >= mid and temp[i] % k == 0){
                    temp[i] /= k;
                    pow++;
                }
            }
            else{
                while(temp[i] % k == 0){
                    temp[i] /= k;
                    pow++;
                }
            }
        }
        else if(temp[i] % k != 0 and temp[i] < mid and temp[i] * k >= mid){
            req++;
        }
    }
    if(req <= pow){
        sum += req;
    }
    else{
        sum += pow;
        req -= pow;
        priority_queue<ll> pq;
        for(ll i=0;i<n;i++){
            ll cnt = 0;
            while(temp[i] % k == 0){
                temp[i] /= k;
                cnt++;
            }
            if(cnt > 0){
                pq.push(cnt);
            }
        }
        while(!pq.empty() and req > 0){
            auto it = pq.top();
            pq.pop();
            sum--;
            if(it >= req){
                sum += req;
                req = 0;
            }
            else{
                sum += it;
                req -= it;
            }
        }
    }
    return sum >= mid;
}
void solve()
{
    cin>>n>>k;
    arr = vector<ll>(n);
    for(auto &it : arr){
        cin>>it;
    }
    ll low = 0;
    ll high = n;
    ll ans = 0;
    while(low <= high){
        ll mid = (low + high) >> 1;
        if(check(mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
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