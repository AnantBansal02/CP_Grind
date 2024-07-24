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

using ll = long long;
const int mod = 1e9 + 7;

struct Node {
    ll D, C, B, A;
    ll max_val;
    Node(int val = 0) {
        D = C = B = 0;
        A = val;
        max_val = max(0, val);
    }
};

Node merge(Node a, Node b) {
    Node res;
    res.D = max({a.D + b.D, a.D + b.B, a.C + b.D});
    res.C = max({a.D + b.C, a.C + b.C, a.D + b.A});
    res.B = max({a.B + b.D, a.B + b.B, a.A + b.D});
    res.A = max(a.B + b.A, a.A + b.C);
    res.max_val = max({res.D, res.C, res.B, res.A});
    return res;
}

class SegmentTree {
    vector<Node> t;
    int n;

public:
    SegmentTree(vector<int> &arr) {
        n = arr.size();
        t.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<int> &arr, int id, int l, int r) {
        if(l == r) {
            t[id] = Node(arr[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(arr, id << 1, l, mid);
        build(arr, id << 1 | 1, mid + 1, r);
        t[id] = merge(t[id << 1], t[id << 1 | 1]);
    }

    void update(int id, int l, int r, int pos, int x) {
        if(pos < l || pos > r) {
            return;
        }
        if(l == r) {
            t[id].A = x;
            t[id].max_val = max(0, x);
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, pos, x);
        update(id << 1 | 1, mid + 1, r, pos, x);
        t[id] = merge(t[id << 1], t[id << 1 | 1]);
    }

    Node query(int id, int l, int r, int lq, int rq) {
        if(lq > r || l > rq) {
            return Node();
        }
        if(lq <= l && r <= rq) {
            return t[id];
        }
        int mid = (l + r) >> 1;
        return merge(query(id << 1, l, mid, lq, rq), query(id << 1 | 1, mid + 1, r, lq, rq));
    }
};

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        ll res = 0;
        int n = nums.size();
        SegmentTree segTree(nums);
        for(auto &q : queries) {
            int pos = q[0], x = q[1];
            segTree.update(1, 0, n - 1, pos, x);
            res += segTree.query(1, 0, n - 1, 0, n - 1).max_val;
            res %= mod;
        }
        return res;
    }
};