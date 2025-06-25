#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

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

    vector<int> vis(n+1), dp(n+1);
    stack<int> st;

    function<void(int)> dfs = [&](int node){
        vis[node] = 1;

        for(auto nbr: adj[node]){
            if(vis[nbr])
                continue;

            dfs(nbr);
        }

        st.push(node);
    };

    dfs(1);

    dp[1] = 1;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto nbr: adj[node])
            dp[nbr] = (dp[nbr] + dp[node]) % MOD;
    }

    cout << dp[n] << "\n";
}
