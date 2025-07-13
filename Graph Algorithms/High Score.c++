#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b, x;
    cin >> n >> m;

    vector<tuple<int, int, int>> adj;
    vector<int> revadj[n+1];
    for(int i = 0; i < m; i++){
        cin >> a >> b >> x;

        adj.push_back({ a, b, x });
        revadj[b].push_back(a);
    }

    vector<int> dp(n+1, LLONG_MIN), vis(n+1);
    dp[1] = 0;

    for(int i = 1; i < n; i++){
        for(auto &[u, v, c]: adj){
            if(dp[u] == LLONG_MIN)
                continue;

            if(dp[v] < dp[u] + c)
                dp[v] = dp[u] + c;
        }
    }

    function<void(int)> dfs = [&](int node){
        vis[node] = 1;

        for(auto nbr: revadj[node]){
            if(vis[nbr])
                continue;

            dfs(nbr);
        }
    };

    dfs(n);

    int isCycle = 0;
    for(auto &[u, v, c] : adj){
        if(dp[u] == LLONG_MIN)
            continue;

        if(dp[v] < (dp[u] + c) && vis[v])
            isCycle = -1;
    }

    if(isCycle == -1)
        cout << "-1\n";
    else
        cout << dp[n] << "\n";
}
