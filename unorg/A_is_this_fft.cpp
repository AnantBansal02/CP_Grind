#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int power(int base, int exponent, int mod) {
    int result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (1LL * result * base) % mod;
        }
        exponent /= 2;
        base = (1LL * base * base) % mod;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int count = (1LL * power(10, x, MOD)/3);
        cout << count << endl;
    }
    return 0;
}
