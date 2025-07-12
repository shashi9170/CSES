#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b, c;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    vector<int> dp(n + 1, LLONG_MAX), cnt(n + 1), inQueue(n + 1), parent(n + 1, -1);;
    queue<int> q;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c}); 
    }

    int cycleStart = -1;

    for (int i = 1; i <= n; i++) {
        if (dp[i] != LLONG_MAX) continue;

        dp[i] = 0;
        q.push(i);
        inQueue[i] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            inQueue[node] = 0;

            for (auto [nbr, len] : adj[node]) {
                int new_len = dp[node] + len;

                if (dp[nbr] > new_len) {
                    dp[nbr] = new_len;
                    parent[nbr] = node;
                    cnt[nbr] = cnt[node] + 1;

                    if (!inQueue[nbr]) {
                        q.push(nbr);
                        inQueue[nbr] = 1;
                    }

                    if (cnt[nbr] >= n) {
                        cycleStart = nbr;
                        break;
                    }
                }
            }

            if (cycleStart != -1)
                break;
        }

        if (cycleStart != -1)
            break;
    }

    if (cycleStart == -1) {
        cout << "NO\n";
    } else {
        for (int i = 0; i < n; i++) {
            cycleStart = parent[cycleStart];
        }

        vector<int> ans;
        int curr = cycleStart;

        do {
            ans.push_back(curr);
            curr = parent[curr];
        } while (curr != cycleStart);
        ans.push_back(cycleStart);

        reverse(ans.begin(), ans.end());

        cout << "YES\n";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
