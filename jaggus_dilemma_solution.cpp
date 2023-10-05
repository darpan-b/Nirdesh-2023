#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("testcase_case.txt", "r", stdin);
    freopen("testcase_solution.txt", "w", stdout);

    string s;
    cin >> s;
    int n = (int)s.size();
    assert(n <= 2'00000);   
    int maxans = 0, curans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') curans++;
        else curans--;
        assert(curans >= 0);
        maxans = max(maxans, curans);
    }
    cout << maxans << "\n";
}
