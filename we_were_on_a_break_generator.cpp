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

    int n = uniform_int_distribution<ll>(1, 5)(rng);
    int m = uniform_int_distribution<ll>(1, 5)(rng);


    vector<string> grid(n);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
                grid[i]+= '.';
            }
            else {
                int k = uniform_int_distribution<ll>(1, 100)(rng);
                if (k % 4 == 0) grid[i] += 'X';
                else grid[i] += '.';
            }
        }
    }

    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        cout << grid[i];
        if (i != n - 1) cout << "\n";
    }
    return 0;
}
