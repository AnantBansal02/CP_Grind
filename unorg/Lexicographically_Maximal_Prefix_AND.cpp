#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(last) cout << #last << " = " << last << "\n"
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define all(last) (last).begin(), (last).end()
#define set_bits(last) __builtin_popcountll(last)


// class Trie {

// public:
//     struct Node{
//         Node *links[2];
//         bool flag = false;
//         ll cnt1 = 0;
//         ll cnt0 = 0;
//         bool contcurrnskey(char ch){
//             return links[ch-'0'] != NULL;
//         }
//         void setkey(char ch,Node *node){
//             links[ch-'0'] = node;
//         }
//         Node *nelastt(char ch){
//             return links[ch-'0'];
//         }
//         void setEnd(){
//             flag = true;
//         }
//         bool isEnd(){
//             return flag;
//         }
//     };

//     Node *root = new Node();
//     Trie() {
        
//     }
//     void insert(string word) {
//         Node *node = root;
//         ll n = word.size();
//         for(ll i=0;i<n;i++){
//             if(word[i] == '0'){
//                 node->cnt0++;
//             }
//             else{
//                 node->cnt1++;
//             }
//             if(!node->contcurrnskey(word[i])){
//                 node->setkey(word[i], new Node());
//             }
//             node = node->nelastt(word[i]);
//         }
//         node->setEnd();
//     }   
//     ll search(ll num) {
//         string word = "";
//         for(ll i=31;i>=0;i--){
//             if(((1LL << i) & num)){
//                 word.pb('1');
//             }
//             else{
//                 word.pb('0');
//             }
//         }
//         ll n = word.size();
//         Node *node = root;
//         string ans = "";
//         for(ll i=0;i<n;i++){
//             if(word[i] == '0'){
//                 if(node->cnt0){
//                     node->cnt0--;
//                     node = node->nelastt('0');
//                     ans += '0';
//                 }
//                 else{
//                     node->cnt1--;
//                     node = node->nelastt('1');
//                     ans += '1';
//                 }
//             }
//             else{
//                 if(node->cnt1){
//                     node->cnt1--;
//                     node = node->nelastt('1');
//                     ans += '1';
//                 }
//                 else{
//                     node->cnt0--;
//                     node = node->nelastt('0');
//                     ans += '0';
//                 }
//             }
//         }
//         ll tor = 0;
//         for(ll i=0;i<n;i++){
//             if(ans[i] == '1'){
//                 tor += (1LL << (n-i-1));
//             }
//         }
//         return tor;
//     }
// };

// void solve()
// {
//     ll n;cin>>n;
//     vector<ll> arr(n);
//     for(auto &it : arr){
//         cin>>it;
//     }
//     Trie tr;
//     sort(all(arr));
//     for(ll i=0;i<n-1;i++){
//         string temp = "";
//         for(ll j=31;j>=0;j--){
//             if(((1LL << j) & arr[i])){
//                 temp.pb('1');
//             }
//             else{
//                 temp.pb('0');
//             }
//         }
//         tr.insert(temp);
//     }
//     vector<ll> ans(n, 0);
//     ans[0] = arr[n-1];
//     for(ll i=1;i<n;i++){
//         ll num = tr.search(ans[i-1]);
//         ans[i] = (num & ans[i-1]);
//     }
//     for(auto it : ans){
//         cout<<it<<" ";
//     }
//     cout<<"\n";
// }

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll &x : arr) {
        cin >> x;
    }
    sort(arr.begin(), arr.end());

    vector<vector<ll>> bits(32);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < 32; ++j) {
            if (arr[i] & (1LL << j)) {
                bits[j].push_back(arr[i]);
            }
        }
    }

    multiset<ll> mst;
    for (ll i = 0; i < n; ++i) {
        ll mask = 0;
        for (ll j = 31; j >= 0; --j) {
            if ((arr[i] & (1LL << j)) && (arr.back() & (1LL << j))) {
                mask ^= (1LL << j);
            }
        }
        mst.insert(mask);
    }

    ll last = arr.back();
    cout << last << " ";
    mst.erase(mst.find(last));

    for (ll i = 1; i < n; ++i) {
        ll next_last = *mst.rbegin();
        mst.erase(mst.find(next_last));

        vector<ll> to_update;
        ll mask_req = 0;
        for (ll j = 31; j >= 0; --j) {
            if ((last & (1LL << j)) && !(next_last & (1LL << j))) {
                to_update.push_back(j);
                mask_req ^= (1LL << j);
            }
        }

        last &= next_last;
        for (ll bit : to_update) {
            for (ll val : bits[bit]) {
                val &= (last ^ mask_req);
                if (mst.find(val) == mst.end()) continue;
                mst.erase(mst.find(val));
                val &= last;
                mst.insert(val);
            }
        }

        cout << last << " ";
    }
    cout << "\n";
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