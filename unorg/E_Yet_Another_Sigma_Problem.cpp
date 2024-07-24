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

class Trie {

public:
    struct Node{
        Node *links[26];
        int cnt = 0;
        bool flag = false;
        bool containskey(char ch){
            return links[ch-'a'] != NULL;
        }
        void setkey(char ch,Node *node){
            links[ch-'a'] = node;
        }
        Node *next(char ch){
            return links[ch-'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }
    };

    /** Initialize your data structure here. */
    Node *root = new Node();
    Trie() {
        
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(!node->containskey(word[i])){
                node->setkey(word[i], new Node());
            }
            node = node->next(word[i]);
            node->cnt++;
        }
        node->setEnd();
    }    
    /** Returns if the word is in the trie. */
    ll search(string word) {
        int n = word.length();
        Node *node = root;
        // cout<<word<<"\n";
        ll ans = 0;
        for(int i=0;i<n;i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node = node->next(word[i]);
            // cout<<node->cnt<<"\n";
            node->cnt--;
            ans += node->cnt;
        }
        return ans;
    }
};
void solve()
{
    Trie tr;
    ll n;cin>>n;
    vector<string> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    for(auto it : arr){
        tr.insert(it);
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ans += tr.search(arr[i]);
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
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}