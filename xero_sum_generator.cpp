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

    int n = uniform_int_distribution<ll>(1, 1'000'000)(rng);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = uniform_int_distribution<ll>(1, 1'000'000'000)(rng);
    }

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i != n - 1) cout << " ";
    }
    return 0;
}
