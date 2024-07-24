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

ll power(ll x, ll y){
    ll res = 1;x = x;while (y > 0){if (y & 1)res = (res * x);y = y >> 1;x = (x * x);}return res;
}
ll help(vector<vector<ll>>& comop, ll x){
    ll low = 0;
    ll high = comop.size() - 1;
    ll idx = -1;
    while(low <= high){
        ll mid = (low + high) >> 1;
        if(comop[mid][0] >= x){
            idx = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return idx;
}
void solve()
{
    ll n,q;cin>>n>>q;
    ll len = 0;
    vector<vector<ll>> op;
    bool ignore = false;
    for(ll i=0;i<n;i++){
        ll type, x;
        cin>>type>>x;
        if(ignore){
            continue;
        }
        if(type == 1){
            len++;
            op.push_back({len, 1, x});
        }
        else{
            if(len >= 1e18/(1 + x)){
                ignore = true;
                len = 1e18;
            }
            else{
                len += len * x;
            }
            op.push_back({len, 2});
        }
    }
    vector<vector<ll>> comop;
    ll N = op.size();
    ll i = 0;
    while(i<N){
        if(op[i][1] == 1){
            comop.push_back(op[i]);
            i++;
            continue;
        }
        while(i < N and op[i][1] == 2){
            i++;
        }
        comop.push_back({op[i-1]});
    }
    while(q--){
        ll x;cin>>x;
        while(1){
            ll idx = help(comop, x);
            if(comop[idx][1] == 1){
                cout<<comop[idx][2]<<" ";
                break;
            }
            else{
                x = x%comop[idx-1][0];
                if(x == 0){
                    cout<<comop[idx-1][2]<<" ";
                    break;
                }
            }
        }
    }
    cout<<"\n";
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