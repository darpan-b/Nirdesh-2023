#include <bits/stdc++.h>
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif
using namespace std;

const int INF = 1e8 + 5;

int main() {
    freopen("testcase_case.txt", "r", stdin);
    freopen("testcase_solution.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& e : grid) cin >> e;
    vector<vector<int>> dp1(n, vector<int>(m, INF));
    vector<vector<int>> dp2(n, vector<int>(m, INF));
    dp1[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            if (grid[i][j] == INF) continue;
            if (i - 1 >= 0) dp1[i][j] = min(dp1[i][j], dp1[i - 1][j] + 1);
            if (j - 1 >= 0) dp1[i][j] = min(dp1[i][j], dp1[i][j - 1] + 1);
        }
    }
    dp2[n - 1][0] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (i == n - 1 && j == 0) continue;
            if (grid[i][j] == INF) continue;
            if (i + 1 < n) dp2[i][j] = min(dp2[i][j], dp2[i + 1][j] + 1);
            if (j - 1 >= 0) dp2[i][j] = min(dp2[i][j], dp2[i][j - 1] + 1);
        }
    }
    int ans = INF;
    int xans = -1, yans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp1[i][j] + dp2[i][j] < ans) {
                ans = dp1[i][j] + dp2[i][j];
                xans = i + 1;
                yans = j + 1;
            }
        }
    }
    assert(dp1[n - 1][m - 1] < INF && dp2[0][m - 1] < INF);
    assert(ans < INF);
    dbg(ans);
    cout << xans << " " << yans << "\n";
}
