#include <bits/stdc++.h>
#define int long long
using namespace std;

const int LOG = 30;

int n, q;
vector<int> t, dist, cycleDist, vis, indeg;
vector<vector<int>> dp, adj, cycles;
map<int, int> cycleSize, nodeToCycleId;

// Binary lifting to get d-th node from u
int getKth(int u, int k) {
    for (int i = LOG - 1; i >= 0; i--) {
        if (k & (1LL << i)) u = dp[u][i];
    }
    return u;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    t.resize(n + 1);
    dist.resize(n + 1);
    vis.resize(n + 1);
    indeg.resize(n + 1);
    cycleDist.resize(n + 1);
    dp.assign(n + 1, vector<int>(LOG));
    adj.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        dp[i][0] = t[i];
        indeg[t[i]]++;
        adj[t[i]].push_back(i);
    }

    // Binary lifting table
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    // Topo sort to remove non-cycle parts
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) que.push(i);
    }
    while (!que.empty()) {
        int u = que.front(); que.pop();
        indeg[t[u]]--;
        if (indeg[t[u]] == 0) que.push(t[u]);
    }

    // Cycle detection
    for (int i = 1; i <= n; i++) {
        if (indeg[i] && !vis[i]) {
            vector<int> cycle;
            int u = i;
            while (!vis[u]) {
                vis[u] = 1;
                cycleDist[u] = cycle.size();
                nodeToCycleId[u] = cycles.size();
                cycle.push_back(u);
                u = t[u];
            }
            cycles.push_back(cycle);
            cycleSize[cycles.size() - 1] = cycle.size();
        }
    }

    // Distance for non-cycle nodes
    fill(vis.begin(), vis.end(), 0);
    for (auto& cyc : cycles) {
        queue<int> q;
        for (int u : cyc) q.push(u), vis[u] = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    dist[v] = dist[u] + 1;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    // Answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;

        bool inCycleA = nodeToCycleId.count(a);
        bool inCycleB = nodeToCycleId.count(b);

        if (inCycleA && inCycleB) {
            if (nodeToCycleId[a] != nodeToCycleId[b]) {
                cout << "-1\n";
            } else {
                int d = (cycleDist[b] - cycleDist[a] + cycleSize[nodeToCycleId[a]]) % cycleSize[nodeToCycleId[a]];
                cout << d << '\n';
            }
        } else if (!inCycleA && inCycleB) {
            int d = dist[a];
            int dest = getKth(a, d);
            if (nodeToCycleId.count(dest) && nodeToCycleId[dest] == nodeToCycleId[b]) {
                int d2 = (cycleDist[b] - cycleDist[dest] + cycleSize[nodeToCycleId[dest]]) % cycleSize[nodeToCycleId[dest]];
                cout << d + d2 << '\n';
            } else {
                cout << "-1\n";
            }
        } else if (!inCycleA && !inCycleB) {
            if (dist[a] < dist[b]) {
                cout << "-1\n";
            } else {
                int d = dist[a] - dist[b];
                if (getKth(a, d) == b)
                    cout << d << '\n';
                else
                    cout << "-1\n";
            }
        } else {
            // a is in cycle, b is in tree: invalid
            cout << "-1\n";
        }
    }

    return 0;
}
