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

class STLazy{
    public:
    vector<ll> st,lazy;
    static ll N;
    STLazy(ll n){
        st.resize(4*n+1);
        lazy.resize(4*n+1);
        N = n;
    }
    void build(vector<ll>& arr, ll idx = 0, ll low = 0, ll high = N - 1){
        if(low==high){
            st[idx] = arr[low];
            return;
        }
        ll mid = (low + high) >> 1;
        build(arr, 2*idx+1, low, mid);
        build(arr, 2*idx+2, mid+1, high);
        st[idx] = max(st[2*idx+1], st[2*idx+2]);
    }
    void update(ll l, ll r, ll val, ll idx = 0, ll low = 0, ll high = N - 1){
        if(lazy[idx] != 0){
            st[idx] = max(st[idx], lazy[idx]);  
            if(low != high){
                lazy[2*idx+1] = max(lazy[2*idx+1], lazy[idx]);
                lazy[2*idx+2] = max(lazy[2*idx+2], lazy[idx]);
            }
            lazy[idx] = 0;
        }
        if(l>high || low>r){
            return;
        }
        if(low>=l and r>=high){
            st[idx] = (high - low + 1)*val;
            if(low!=high){
                lazy[2*idx+1] = val;
                lazy[2*idx+2] = val;
            }
            return;
        }
        ll mid = (low + high) >> 1;
        update(l, r, val, 2*idx+1, low, mid);
        update(l, r, val, 2*idx+2, mid+1, high);
        st[idx] = max(st[2*idx+1], st[2*idx+2]);
    }
    ll query(ll l, ll r, ll idx = 0, ll low = 0, ll high = N - 1){
        if(lazy[idx] != 0){
            st[idx] = max(st[idx], lazy[idx]);  
            if(low != high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(low>=l and r>=high){
            return st[idx];
        }
        if(l>high || low>r){
            return 0;
        }
        ll mid = (low + high) >> 1;
        return max(query(l, r, 2*idx+1,low,mid), query(l, r, 2*idx+2, mid+1, high));
    }
};
ll STLazy::N;

vector<ll> get(vector<ll>& arr){
    ll n = arr.size();
    ll id = 0;
    map<ll,ll> mp;
    set<ll> st(all(arr));
    for(auto it : st){
        mp[it] = ++id;
    }
    STLazy sg(id);
    vector<ll> ans(n);
    for(ll i=0;i<n;i++){
        ll maxi = sg.query(0, mp[arr[i]] - 1);
        sg.update(mp[arr[i]], mp[arr[i]], maxi + 1);
        ans[i] = maxi+1;
    }
    return ans;
}

void solve()
{
    ll n;cin>>n;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    vector<ll> front = get(arr);
    ll lis = *max_element(all(front));
    for(auto &it : arr){
        it *= -1;
    }
    reverse(all(arr));
    vector<ll> back = get(arr);
    reverse(all(back));
    vector<ll> ans;
    for(ll i=0;i<n;i++){
        if(front[i] + back[i] - 1 == lis){
            ans.pb(i+1);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<"\n";
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