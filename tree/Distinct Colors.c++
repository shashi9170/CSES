#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, u, v;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> adj[n];
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans(n);
    set<int> dp[n];

    function<void(int, int)> dfs = [&](int node, int parent){
        dp[node].insert(a[node]);

        for(auto nbr: adj[node]){
            if(nbr == parent)
                continue;
            
            dfs(nbr, node);

            if(dp[nbr].size() > dp[node].size())
                swap(dp[nbr], dp[node]);

            dp[node].insert(dp[nbr].begin(), dp[nbr].end());
        }

        ans[node] = dp[node].size();
    };

    dfs(0, -1);

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}
