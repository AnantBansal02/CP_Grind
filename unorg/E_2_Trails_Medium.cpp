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

class matrix_expo{
    public:
    ll m, n, mod;
    vector<vector<ll>> mat, ans;
    matrix_expo(vector<vector<ll>>& arr, ll N, ll MOD){
        this->m = arr.size();
        this->n = N;
        this->mod = MOD;
        mat = vector<vector<ll>>(m, vector<ll>(m));
        ans = vector<vector<ll>>(m, vector<ll>(m));
        for(ll i=0;i<m;i++){
            for(ll j=0;j<m;j++){
                mat[i][j] = arr[i][j];
            }
            ans[i][i] = 1;
        }
        build();
    }
    vector<vector<ll>> mult(vector<vector<ll>> A, vector<vector<ll>> B){
        ll a = A.size();
        ll b = B[0].size();
        assert(((ll)A[0].size()) == ((ll)B.size()));
        ll c = B.size();
        vector<vector<ll>> curr(a, vector<ll>(b));
        for(ll i=0;i<a;i++){
            for(ll j=0;j<b;j++){
                ll val = 0;
                for(ll k=0;k<c;k++){
                    (val += A[i][k] * B[k][j]) %= mod;
                }
                curr[i][j] = val;
            }
        }
        return curr;
    }
    void build(){
        ll N = n;
        while(N){
            if(N % 2 == 1){
                ans = mult(ans, mat);
                N--;
            }
            if(N){
                mat = mult(mat, mat);
                N = N >> 1;
            }
        }
    }
};

void solve()
{
    ll mod = 1e9 + 7;
    ll m, n;cin>>m>>n;
    vector<vector<ll>> arr(m, vector<ll>(2));
    for(ll i=0;i<m;i++){
        cin>>arr[i][0];
    }
    for(ll i=0;i<m;i++){
        cin>>arr[i][1];
    }
    vector<vector<ll>> temp(2, vector<ll>(m));
    for(ll j=0;j<m;j++){
        temp[0][j] = arr[j][0] + arr[j][1];
        temp[1][j] = arr[j][0];
    }
    vector<vector<ll>> mat(m, vector<ll>(m));
    for(ll i=0;i<m;i++){
        for(ll j=0;j<m;j++){
            mat[i][j] = arr[i][0]*temp[0][j] + arr[i][1]*temp[1][j];
        }
    }
    vector<vector<ll>> day(1, vector<ll>(m));
    day[0][0] = 1;

    matrix_expo fun(mat, n, mod);
    day = fun.mult(day, fun.ans);
    ll ans = 0;
    for(ll i=0;i<m;i++){
        (ans += day[0][i]) %= mod;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}