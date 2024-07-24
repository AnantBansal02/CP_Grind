#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void solve(int tc) {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    
    vector<pair<int, int>> ver, hor;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ver.emplace_back(x, y);
        hor.emplace_back(y, x);
    }
    
    set<pair<int, int>> deleted;
    sort(hor.begin(), hor.end());
    sort(ver.begin(), ver.end());
    
    vector<int> ans(2, 0);
    int u = 1, d = a;
    int l = 1, r = b;
    int hl = 0, hr = n - 1;
    int vl = 0, vr = n - 1;
    
    for (int i = 0; i < m; ++i) {
        char c;
        int k;
        cin >> c >> k;
        
        if (c == 'U') {
            u += k;
            while (vl <= vr && ver[vl].first < u) {
                if (deleted.find(ver[vl]) == deleted.end()) {
                    ans[i % 2]++;
                    deleted.insert(ver[vl]);
                }
                vl++;
            }
        } else if (c == 'D') {
            d -= k;
            while (vl <= vr && ver[vr].first > d) {
                if (deleted.find(ver[vr]) == deleted.end()) {
                    ans[i % 2]++;
                    deleted.insert(ver[vr]);
                }
                vr--;
            }
        } else if (c == 'L') {
            l += k;
            while (hl <= hr && hor[hl].first < l) {
                if (deleted.find({hor[hl].second, hor[hl].first}) == deleted.end()) {
                    ans[i % 2]++;
                    deleted.insert({hor[hl].second, hor[hl].first});
                }
                hl++;
            }
        } else if (c == 'R') {
            r -= k;
            while (hl <= hr && hor[hr].first > r) {
                if (deleted.find({hor[hr].second, hor[hr].first}) == deleted.end()) {
                    ans[i % 2]++;
                    deleted.insert({hor[hr].second, hor[hr].first});
                }
                hr--;
            }
        }
    }
    
    cout << ans[0] << " " << ans[1] << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}
