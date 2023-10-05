#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(0, i)(rng) -> gives an int in the range [0,i]

int main() {
    freopen("testcase_case.txt", "w", stdout);

    int n = uniform_int_distribution<ll>(1, 2'000'00)(rng);

    int curinside = 0;
    string s = "";
    for (int i = 0; i < n; i++) {
        if (curinside == 0) {
            s += '1';
            curinside++;
        }
        else {
            int ones = uniform_int_distribution<ll>(1, n - i)(rng);
            string o = string(ones, '1');

            int zeroes = uniform_int_distribution<ll>(1, min(n - i, curinside))(rng);
            string z = string(zeroes, '0');

            int choice = (uniform_int_distribution<ll>(1, 1000)(rng)) % 2;

            if (choice == 1) {
                curinside += ones;
                i += ones - 1;
                s += o;
            }
            else {
                curinside -= zeroes;
                i += zeroes - 1;
                s += z;
            }
        }
    }
    cout << s << "\n";
    return 0;
}
