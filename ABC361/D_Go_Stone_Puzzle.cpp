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


struct State {
    string stones;
    int steps;
};

int solve(int N, string S, string T) {
    int countS_W = 0, countS_B = 0, countT_W = 0, countT_B = 0;
    for (char c : S) {
        if (c == 'W') countS_W++;
        else countS_B++;
    }
    for (char c : T) {
        if (c == 'W') countT_W++;
        else countT_B++;
    }
    if (countS_W != countT_W || countS_B != countT_B) return -1;
    queue<State> q;
    set<string> visited;
    string target = T + "..";
    q.push({S + "..", 0});
    visited.insert(S + "..");

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.stones == target) {
            return current.steps;
        }

        for (int i = 0; i < N + 1; ++i) {
            if (current.stones[i] != '.' && current.stones[i + 1] != '.') {
                for (int j = 0; j < N + 2; ++j) {
                    if (current.stones[j] == '.' && current.stones[j + 1] == '.') {
                        string nextState = current.stones;
                        swap(nextState[i], nextState[j]);
                        swap(nextState[i + 1], nextState[j + 1]);

                        if (visited.find(nextState) == visited.end()) {
                            q.push({nextState, current.steps + 1});
                            visited.insert(nextState);
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int N;
    string S, T;
    cin >> N >> S >> T;

    int result = solve(N, S, T);
    cout << result << endl;

    return 0;
}
