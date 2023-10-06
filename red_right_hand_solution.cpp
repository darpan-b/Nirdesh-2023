#include <bits/stdc++.h>
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif
using namespace std;

#define ll long long

const int MAXN = 2e5 + 5;
vector<pair<pair<int, int>, ll>> edges;

int root[MAXN], ranks[MAXN];


int findroot(int node) {
    if (root[node] == node) return node;
    else return root[node] = findroot(root[node]);
}

bool unite(int u, int v) {
    u = findroot(u);
    v = findroot(v);
    if (u == v) return false;
    if (ranks[u] > ranks[v]) {
        root[v] = u;
        ranks[u] += ranks[v];
    }
    else {
        root[v] = u;
        ranks[u] += ranks[v];        
    }
    return true;
}

int main() {
    freopen("testcase_case.txt", "r", stdin);
    freopen("testcase_solution.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    dbg(n, m);
    for (int i = 0; i <= n; i++) {
        root[i] = i;
        ranks[i] = 1;
    }
    vector<ll> cost(n);
    for (auto& e : cost) cin >> e;

    for (int i = 0; i < n; i++) {
        // ll x;
        // cin >> x;
        // adj[i].push_back({n, x});
        // adj[n].push_back({i, x});
        edges.push_back({{i, n}, cost[i]});
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        ll w;
        cin >> w;
        u--;
        v--;
        edges.push_back({{u, v}, w});
        // adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
    sort(edges.begin(), edges.end(), [&](auto lhs, auto rhs) {
        return lhs.second < rhs.second;
    });
    ll ans = 0;
    for (auto e : edges) {
        if (unite(e.first.first, e.first.second)) {
            ans += e.second;
        }
    }
    cout << ans << "\n";
    
    
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
