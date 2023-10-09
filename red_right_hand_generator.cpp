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
    int m = uniform_int_distribution<ll>(1, min(((n * (n - 1)) / 2), 2'000'00))(rng);

    vector<ll> cost(n);
    for (int i = 0; i < n; i++) {
        cost[i] = uniform_int_distribution<ll>(1LL, 1'000'000'000LL)(rng);
    }

    vector<pair<pair<int, int>, ll>> edges(m);
    set<pair<int, int>> done;
    for (int i = 0; i < m; i++) {
        edges[i].first.first = uniform_int_distribution<ll>(1, n)(rng);
        edges[i].first.second = uniform_int_distribution<ll>(1, n)(rng);
        edges[i].second = uniform_int_distribution<ll>(1LL, 1'000'000'000LL)(rng);
        if (edges[i].first.first == edges[i].first.second || 
            done.count({min(edges[i].first.first, edges[i].first.second), max(edges[i].first.first, edges[i].first.second)})) {
            i--;
        }
        else {
            done.insert({min(edges[i].first.first, edges[i].first.second), max(edges[i].first.first, edges[i].first.second)});
        }
    } 

    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        cout << cost[i];
        if (i == n - 1) cout << "\n";
        else cout << " ";
    }
    for (int i = 0; i < m; i++) {
        cout << edges[i].first.first << " " << edges[i].first.second << " " << edges[i].second;
        if (i != n - 1) cout << "\n";
    }
    return 0;
}

