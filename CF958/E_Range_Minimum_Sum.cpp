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
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }
    void update(ll l, ll r, ll val, ll idx = 0, ll low = 0, ll high = N - 1){
        if(lazy[idx] != 0){
            st[idx] += (high - low + 1)*lazy[idx];  
            if(low != high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(l>high || low>r){
            return;
        }
        if(low>=l and r>=high){
            st[idx] += (high - low + 1)*val;
            if(low!=high){
                lazy[2*idx+1] += val;
                lazy[2*idx+2] += val;
            }
            return;
        }
        ll mid = (low + high) >> 1;
        update(l, r, val, 2*idx+1, low, mid);
        update(l, r, val, 2*idx+2, mid+1, high);
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }
    ll query(ll l, ll r, ll idx = 0, ll low = 0, ll high = N - 1){
        if(lazy[idx] != 0){
            st[idx] += (high - low + 1)*lazy[idx];  
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
        return (query(l, r, 2*idx+1,low,mid) + query(l, r, 2*idx+2, mid+1, high));
    }
};
ll STLazy::N;

void solve()
{
    ll n; cin >> n;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    vector<ll> prev(n, -1), next(n, n);
    vector<ll> prev2(n, -1), next2(n, n);
    {
        stack<ll> st;
        for(ll i = 0; i < n; i++){
            while(!st.empty() and arr[st.top()] > arr[i]){
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(ll i = n - 1; i >= 0; i--){
            while(!st.empty() and arr[st.top()] > arr[i]){
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    {
        stack<ll> st1, st2;
        for(ll i = 0; i < n; i++){
            while(!st2.empty() and arr[st2.top()] > arr[i]){
                next2[st2.top()] = i;
                st2.pop();
            }
            vector<ll> cand;
            while(!st1.empty() and arr[st1.top()] > arr[i]){
                cand.push_back(st1.top());
                st1.pop();
            }
            reverse(all(cand));
            for(auto it : cand){
                st2.push(it);
            }
            st1.push(i);
        }
        while(!st1.empty()) st1.pop();
        while(!st2.empty()) st2.pop();

        for(ll i = n-1; i >= 0; i--){
            while(!st2.empty() and arr[st2.top()] > arr[i]){
                prev2[st2.top()] = i;
                st2.pop();
            }
            vector<ll> cand;
            while(!st1.empty() and arr[st1.top()] > arr[i]){
                cand.push_back(st1.top());
                st1.pop();
            }
            reverse(all(cand));
            for(auto it : cand){
                st2.push(it);
            }
            st1.push(i);
        }
    }
    STLazy st(n);
    for(ll i = 0; i < n; i++){
        ll left = i - prev[i];
        ll right = next[i] - i;
        if(prev[i] + 1 <= i - 1){
            st.update(prev[i] + 1, i - 1, arr[i] * (left - 1) * (right));
        }
        if(next[i] - 1 >= i + 1){
            st.update(i + 1, next[i] - 1, arr[i] * (left) * (right - 1));
        }  
        if(prev[i] - 1 >= 0){
            st.update(0, prev[i] - 1, arr[i] * left * right);
        }
        if(next[i] + 1 < n){
            st.update(next[i] + 1, n - 1, arr[i] * left * right);
        }
        if(prev[i] != -1){
            ll lleft = i - prev2[i];
            st.update(prev[i], prev[i], arr[i] * (lleft - 1) * (right));
        }
        if(next[i] != n){
            ll rright = next2[i] - i;
            st.update(next[i], next[i], arr[i] * (left) * (rright - 1));
        }
        // for(ll j = 0; j < n; j++){
        //     cout << st.query(j, j) << " \n"[j == n-1];
        // }
    }
    for(ll i = 0; i < n; i++){
        cout << st.query(i, i) << " \n"[i == n-1];
    }
    
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