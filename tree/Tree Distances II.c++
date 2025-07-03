#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    function<void(int, int)> dfs = [&](int current, int parent) {
        dp[current][1] = 1; 
        for (int neighbor : tree[current]) {
            if (neighbor == parent) continue;
            dfs(neighbor, current);
            dp[current][0] += dp[neighbor][0] + dp[neighbor][1]; 
            dp[current][1] += dp[neighbor][1]; 
        }
    };

    dfs(1, 0);

    vector<int> result(n + 1);

    function<void(int, int, int, int)> dfsReroot = [&](int node, int parent, int upSubtreeSize, int upDistanceSum) {
        int totalSize = upSubtreeSize;
        int totalDist = upDistanceSum;

        for (int child : tree[node]) {
            if (child == parent) continue;
            totalSize += dp[child][1];
            totalDist += dp[child][0] + dp[child][1];
        }

        result[node] = totalDist;

        for (int child : tree[node]) {
            if (child == parent) continue;

            int newSize = totalSize - dp[child][1];
            int newDist = totalDist - (dp[child][0] + dp[child][1]);

            dfsReroot(child, node, newSize + 1, newDist + newSize + 1);
        }
    };

    dfsReroot(1, 0, 0, 0);

    for (int i = 1; i <= n; i++)
        cout << result[i] << " ";
    cout << "\n";
}
