#include<iostream>
#include<cstdlib>
using namespace std;
#define int long long

/* Function to compute (base^exponent) % mod */
int mod_exp(int base, int exponent, int mod) {
    long long result = 1, power = base; // long long to prevent overflow
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * power) % mod;
        }
        power = (power * power) % mod; // square the base
        exponent /= 2;
    }
    return result % mod;
}

/* Function to compute (a * b) % mod considering overflow */
long long modular_multiplication(long long a, long long b, long long mod) {
    long long result = 0, mod_a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result + mod_a) % mod;
        }
        mod_a = (mod_a * 2) % mod;
        b /= 2;
    }
    return result % mod;
}

/* Miller-Rabin primality test, iterations indicate accuracy */
bool is_prime(long long num, int iterations) {
    if (num < 2) {
        return false;
    }
    if (num != 2 && num % 2 == 0) {
        return false;
    }
    long long d = num - 1;
    while (d % 2 == 0) {
        d /= 2;
    }
    for (int i = 0; i < iterations; i++) {
        long long a = rand() % (num - 1) + 1;
        long long x = mod_exp(a, d, num);
        long long temp_d = d;
        while (temp_d != num - 1 && x != 1 && x != num - 1) {
            x = modular_multiplication(x, x, num);
            temp_d *= 2;
        }
        if (x != num - 1 && temp_d % 2 == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
    int test_cases; 
    cin >> test_cases;
    while (test_cases--) {
        int n; 
        cin >> n;
        if (n == 1 || n == 2) {
            cout << 6 << "\n";
            continue;
        }
        int first_prime, second_prime;

        int candidate = (n % 2 == 0) ? n + 1 : n;
        for (; candidate < 2 * n; candidate += 2) {
            if (is_prime(candidate, 20)) {
                first_prime = candidate;
                break;
            }
        }

        candidate += 2;
        for (; candidate < 2 * n; candidate += 2) {
            if (is_prime(candidate, 20)) {
                second_prime = candidate;
                break;
            }
        }

        cout << first_prime * second_prime << "\n";
    }
    return 0;
}
