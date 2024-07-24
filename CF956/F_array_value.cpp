// #pragma GCC optimize("-Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define dbg(x) cout << #x << " = " << x << "\n"
// #define pb push_back
// #define fi first
// #define se second
// #define INF 1e18
// #define all(x) (x).begin(), (x).end()
// #define set_bits(x) __builtin_popcountll(x)


// struct Node{
//     Node* links[2];
//     ll maxi[2] = {-1, -1};
// };
// void solve()
// {
//     ll n, k; cin >> n >> k;
//     vector<ll> arr(n);
//     for(auto &it : arr) cin >> it;
//     auto check = [&](ll mid){
//         vector<Node*> used;
//         Node* root = new Node();
//         used.pb(root);
//         auto insert = [&](ll val, ll idx){
//             Node* curr = root;
//             for(ll i = 29; i >= 0; i--){
//                 ll f = 0;
//                 if((1LL << i) & val){
//                     f = 1;
//                 }   
//                 if(curr->links[f] == NULL){
//                     curr->links[f] = new Node();
//                     used.pb(curr->links[f]);
//                 }
//                 curr->maxi[f] = max(curr->maxi[f], idx);
//                 curr = curr->links[f];
//             }
//         };
//         auto query = [&](ll val){
//             ll idx = -1;
//             Node* curr = root;
//             for(ll i = 29; i >= 0; i--){
//                 if(((1LL << i) & val) and ((1LL << i) & mid)){
//                     idx = max(idx, curr->maxi[1]);
//                     if(i == 0){
//                         idx = max(idx, curr->maxi[0]);
//                     }
//                     curr = curr->links[0];
//                 }
//                 else if(((1LL << i) & val)){
//                     if(i == 0){
//                         idx = max(idx, curr->maxi[1]);
//                     }
//                     curr = curr->links[1];
//                 }
//                 else if(((1LL << i) & mid)){
//                     idx = max(idx, curr->maxi[0]);
//                     if(i == 0){
//                         idx = max(idx, curr->maxi[1]);
//                     }
//                     curr = curr->links[1];
//                 }
//                 else{
//                     if(i == 0){
//                         idx = max(idx, curr->maxi[0]);
//                     }
//                     curr = curr->links[0];
//                 }
//                 if(curr == NULL){
//                     break;
//                 }
//             }
//             return idx;
//         };
//         ll last = -1;
//         ll sum = 0;
//         for(ll i = 0; i < n; i++){
//             last = max(last, query(arr[i]));
//             sum += (last + 1);
//             insert(arr[i], i);
//         }
//         for(auto &it : used){
//             delete it;
//         }
//         return sum >= k;
//     };
//     ll low = 0;
//     ll high = 1e10;
//     ll ans = high;
//     while(low <= high){
//         ll mid = (low + high) >> 1;
//         if(check(mid)){
//             ans = mid;
//             high = mid - 1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     cout << ans << "\n";
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // factorial(1e5,1e9+7);
//     // sieve(1e5);
//     ll t = 1;
//     cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int ch[3000042][2]{}, mx[3000042]{};
int nc = 1;
void insert(int root,int val,int idx){
    int curr=root;
    for(int i=29;i>=0;i--){
        int lr = ((val&(1<<i)) != 0);
        
        if(!ch[curr][lr]){
            nc++;
            mx[nc]=idx;
            ch[curr][lr]=nc;
        }

        mx[curr]=max(mx[curr],idx);
        curr=ch[curr][lr];
    }

    mx[curr]=max(mx[curr],idx);
}
 
int query(int root,int mid,int val){
    int curr=root;
    int idx=-1;

    for(int i=29;i>=0;i--){
        if(!curr)return idx;
 
        //check out with 1
        if((val&(1<<i)) && (mid&(1<<i))){
            if(ch[curr][1])idx=max(idx,mx[ch[curr][1]]);
            curr=ch[curr][0];
        }
        else if((val&(1<<i))){
            curr=ch[curr][1];
        }
        else if((mid&(1<<i))){
            if(ch[curr][0])idx=max(idx,mx[ch[curr][0]]);
            curr=ch[curr][1];
        }
        else{
            curr=ch[curr][0];
        }
    }
 
    if(curr)idx=max(idx,mx[curr]);

    return idx;
}
 

int v[100069]{};
int32_t main(){ 
    int t;
    cin >> t;
    while(t--){
        int n;
        long long k;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
 
        int l=0,r=(1<<30)-1,fin;
        while(l<=r){
            int mid=l+(r-l)/2;
 
            int left=-1;
            long long ans=0;
            nc = 1;
            int root = nc;
            for(int i=0;i<n;i++){
                left=max(left,query(root,mid,v[i]));
                ans+=((long long)left+1);
                insert(root,v[i],i);
            }

            for(int i=0;i<=nc;i++){
                ch[i][0] = 0;
                ch[i][1] = 0;
                mx[i] = 0;
            }

            if(ans<k){
                l=mid+1;
            }
            else{
                fin=mid;
                r=mid-1;
            }
        }
 
        cout << fin << endl;
    }
 
    return 0;
}