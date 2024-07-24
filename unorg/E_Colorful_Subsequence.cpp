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
#define INF 1e15
#define all(x) (x).begin(), (x).end()
#define set_bits(x) __builtin_popcountll(x)



void solve()
{
    ll N,K;cin>>N>>K;
    vector<vector<ll>> arr (N, vector<ll>(2));
    for(auto &it : arr){
        cin>>it[0]>>it[1];
    }
    vector<pair<ll,ll>> vec = {{-INF, -1}, {-INF, -2}};
    vector<vector<vector<pair<ll,ll>>>> dp(2);
    // vector<vector<pair<ll, ll>>> (K+1, vec));
    dp[0].resize(K+1, vec);
    dp[1].resize(K+1, vec);
    dp[0][0][0].first = 0;
    dp[0][0][1].first = 0;
    for(ll i=1;i<=N;i++){
        ll curr = arr[i-1][0];
        ll val = arr[i-1][1];

        auto &currDPvec = dp[i & 1], &prevDPvec = dp[(i-1) & 1];
        for(ll j=0;j<=K;j++){
            currDPvec[j][0].first = -INF;
            currDPvec[j][0].second = -1;
            currDPvec[j][1].first = -INF;
            currDPvec[j][1].second = -2;
        }
        // taking
        // for(ll prev=1;prev<=N;prev++){
        //     if(prev == curr){
        //         continue;
        //     }
        //     for(ll j=0;j<=K;j++){
        //         dp[i][j][curr] = max(dp[i][j][curr], val + dp[i-1][j][prev]);
        //     }
        // }
        for(ll j=0;j<=K;j++){
            if(curr == prevDPvec[j][0].second){
                assert(prevDPvec.size() >= 2);
                assert(prevDPvec[j][1].second != curr);
                currDPvec[j].push_back({val + prevDPvec[j][1].first, curr});
            }
            else{
                currDPvec[j].push_back({val + prevDPvec[j][0].first, curr});
            }
        }
            
        // not taking
        // for(ll prev=1;prev<=N;prev++){
        //     for(ll j=0;j<K;j++){
        //         dp[i][j+1][prev] = max(dp[i][j+1][prev], dp[i-1][j][prev]);
        //     }
        // }       
        for(ll j=0;j<K;j++){
            currDPvec[j+1].push_back({prevDPvec[j][0].first, prevDPvec[j][0].second});
            currDPvec[j+1].push_back({prevDPvec[j][1].first, prevDPvec[j][1].second});
        } 

        for(ll j=0;j<=K;j++){
            sort(currDPvec[j].rbegin(), currDPvec[j].rend());
            if(currDPvec[j][0].second == currDPvec[j][1].second){
                ll maxi = -INF, color = -2;
                for(ll k=1;k<currDPvec[j].size();k++){
                    if(currDPvec[j][k].second != currDPvec[j][0].second){
                        maxi = currDPvec[j][k].first;
                        color = currDPvec[j][k].second;
                        break;
                    }
                }
                currDPvec[j][1].first = maxi;
                currDPvec[j][1].second = color;
            }
            currDPvec[j].resize(2);
        }
    }
    ll ans = -1;
    ans = max(ans, dp[N & 1][K][0].first);
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}