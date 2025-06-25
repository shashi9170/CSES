#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> vis(n + 1, 0), st(n + 1, 0), parent(n + 1, -1);
    int start = -1, end = -1;

    function<bool(int)> dfs = [&](int node) {
        vis[node] = st[node] = 1;
        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                parent[nbr] = node;
                if (dfs(nbr)) return true;
            } else if (st[nbr]) {
                start = nbr;
                end = node;
                return true;
            }
        }
        st[node] = 0;
        return false;
    };

    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && dfs(i)) break;
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        
        for (int v = end; v != start; v = parent[v])
            cycle.push_back(v);

        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }
}
