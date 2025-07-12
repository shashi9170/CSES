#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5 + 1;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    cin >> n >> m;

    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans(n+1);

    function<int(int, int)> dfs = [&](int node, int parent){
        
        for(auto nbr: adj[node]){
            if(nbr == parent)
                continue;
            
            int team = (ans[node] % 2) + 1;
            if(ans[nbr] && ans[nbr] != team)
                return 1LL;

            if(ans[nbr] == team)
                continue;
            
            ans[nbr] = team;

            if(dfs(nbr, node))
                return 1LL;
        }

        return 0LL;
    };

    int f = 0;
    for(int i = 1; i <= n; i++){
        if(!ans[i])
            ans[i] = 1, f |= dfs(i, 0);
    }

    if(f)
        cout << "IMPOSSIBLE\n";
    else{
        for(int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
