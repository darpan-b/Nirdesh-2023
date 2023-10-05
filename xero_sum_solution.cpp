#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("testcase_case.txt", "r", stdin);
    freopen("testcase_solution.txt", "w", stdout);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n; i++) ans ^= a[i];
    cout << ans << "\n";
    return 0;
}
