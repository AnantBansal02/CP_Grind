#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
class STLazy{
    public:
    vector<int> st,lazy,id;
    STLazy(int n){
        st.resize(4*n+1, 0);
        lazy.resize(4*n+1, 0);
        id.resize(4*n+1, 0);
    }
    public:
    void build(int idx, int low, int high, vector<ll>& arr){
        if(low==high){
            st[idx] = arr[low];
            id[idx] = low;
            return;
        }
        int mid = (low + high) >> 1;
        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);
        st[idx] = max(st[2*idx+1], st[2*idx+2]);
        id[idx] = (st[idx] == st[2*idx+1] ? id[2*idx+1] : id[2*idx+2]);
    }
    public:
    void update(int idx, int low, int high, int l, int r, int val){
        // update the previous while traversing
        if(lazy[idx] != 0){
            st[idx] += lazy[idx];  
            // propogate the lazy update downwards
            if(low != high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        // no overlap
        // low high l r || l r low high
        if(l>high || low>r){
            return;
        }
        // complete overlap
        // l low high r
        if(low>=l and r>=high){
            st[idx] += val;
            if(low!=high){
                lazy[2*idx+1] += val;
                lazy[2*idx+2] += val;
            }
            return;
        }
        int mid = (low + high) >> 1;
        update(2*idx+1, low, mid, l, r, val);
        update(2*idx+2, mid+1, high, l, r, val);
        st[idx] = max(st[2*idx+1], st[2*idx+2]);
        id[idx] = (st[idx] == st[2*idx+1] ? id[2*idx+1] : id[2*idx+2]);
    }
    public:
    int query(int idx, int low, int high, int l, int r){
        // if updates remaining!!! lazy!!
        if(lazy[idx] != 0){
            st[idx] += lazy[idx];  
            // propogate the lazy update downwards
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
        int mid = (low + high) >> 1;
        ll ans = max(query(2*idx+1,low,mid,l,r), query(2*idx+2, mid+1, high, l, r));
        id[idx] = (st[idx] == st[2*idx+1] ? id[2*idx+1] : id[2*idx+2]);
        return ans;
    }
};
void solve()
{
    ll n;cin>>n;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    // STLazy seg(n);
    // vector<ll> temp(n);
    // for(ll i=0;i<n;i++){
    //     temp[i] = arr[i] + i + 1;
    // }
    // seg.build(0, 0, n-1, temp);
    // set<ll> brr;
    // ll idx = 0;
    // for(ll i=0;i<n;i++){
    //     ll curr = seg.query(0, 0, n-1, 0, n-1);
    //     ll start = seg.query(0, 0, n-1, idx, idx);
    //     ll l = seg.id[0];
    //     // cout<<curr<<" "<<l<<"\n";
    //     if(brr.find(curr) != brr.end() || curr == start){
    //         brr.insert(start);
    //         seg.update(0, 0, n-1, idx, idx, INT_MIN);
    //         if(idx + 1 <= n - 1){
    //             seg.update(0, 0, n-1, idx+1, n-1, -1);
    //         }
    //         idx++;
    //     }
    //     else{
    //         brr.insert(curr);
    //         seg.update(0, 0, n-1, l, l, INT_MIN);
    //         if(l + 1 <= n - 1){
    //             seg.update(0, 0, n-1, l+1, n-1, -1);
    //         }
    //     }
    // }
    // vector<ll> rr;
    // for(auto it : brr){
    //     rr.push_back(it);
    // }
    // sort(rr.rbegin(), rr.rend());
    // for(auto it : rr){
    //     cout<<it<<" ";    
    // }
    // cout<<"\n";
    vector<ll> brr;
    for(ll i=0;i<n;i++){
        brr.push_back(arr[i] + i + 1);
    }
    sort(brr.begin(), brr.end());
    set<ll, greater<ll>> rr;
    ll left = n - 1;
    ll done = 0;
    for(ll i=n-2;i>=0;i--){
        if(brr[i] >= brr[i+1]){
            ll req = brr[i] - brr[i+1] + 1;
            if(req - done <= left){
                brr[i] = brr[i+1] - 1;
                left -= (req - done);
                done += (req - done);
            }
        }
    }
    for(auto it : brr){
        rr.insert(it);
    }
    for(auto it : rr){
        cout<<it<<" ";
    }
    cout<<"\n";
}
signed main()
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