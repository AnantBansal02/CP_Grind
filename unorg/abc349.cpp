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
    vector<vector<ll>> arr(3, vector<ll>(3, 0));
    for(ll i=0;i<3;i++){
        for(ll j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<ll>> vis(3, vector<ll>(3, 0));

    function<bool(ll)> check = [&](ll num) -> bool{
        for(ll i=0;i<3;i++){
            if(vis[i][0] == num and vis[i][1] == num and vis[i][2] == num){
                return true;
            }
        }
        for(ll j=0;j<3;j++){
            if(vis[0][j] == num and vis[1][j] == num and vis[2][j] == num){
                return true;
            }
        }
        if(vis[0][0] == num and vis[1][1] == num and vis[2][2] == num){
            return true;
        }
        if(vis[2][0] == num and vis[1][1] == num and vis[0][2] == num){
            return true;
        }
        return false;

    };
    function<ll(ll, ll)> dfs = [&](ll turn, ll moves) -> ll {
        ll ans = INT_MIN;
        if(!turn){
            ans = INT_MAX;
        }
        if(turn and check(2)){
            return INT_MIN;
        }
        if(!turn and check(1)){
            return INT_MAX;
        }
        if(moves == 9){
            return 0LL;
        }
        for(ll i=0;i<3;i++){
            for(ll j=0;j<3;j++){
                if(!vis[i][j]){
                    if(turn){
                        vis[i][j] = 1;
                        ans = max(ans, arr[i][j] + dfs(!turn, moves+1));
                    }
                    else{
                        vis[i][j] = 2;
                        ans = min(ans, dfs(!turn, moves+1));
                    }
                    vis[i][j] = 0;
                }
            }
        }
        return ans;
    };
    ll tot = 0;
    for(ll i=0;i<3;i++){
        for(ll j=0;j<3;j++){
            tot += arr[i][j];
        }
    }
    ll tak = dfs(0, 0);
    ll aok = tot - tak;
    // cout<<INT_MIN<<"\n";
    cout<<tak<<"\n";
    if(tak > aok){
        cout<<"Takahashi"<<"\n";
    }
    else{
        cout<<"Aoki"<<"\n";
    }


}
bool cmp(vector<ll>&a, vector<ll>&b){
    if(a[0] != b[0]){
        return a[0] < b[0];
    }
    return a[1] < b[1];

}
void solve2(){
    vector<vector<ll>> arr(8, vector<ll>(2, 0));
    sort(all(arr), cmp);
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    while(t--){
        solve2();
    }
    return 0;
}




