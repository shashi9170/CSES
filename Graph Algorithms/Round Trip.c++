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

    vector<int> ans;
    vector<int> vis(n+1);

    function<int(int, int)> dfs = [&](int node, int parent){
        vis[node] = 1;

        for(auto nbr: adj[node]){
            if(parent == nbr)
                continue;

            if(vis[nbr]){
                ans.push_back(nbr);
                ans.push_back(node);

                return nbr;
            }

            int ret = dfs(nbr, node);

            if(ret == LLONG_MAX)
                continue;
            
            if(ret != node){
                ans.push_back(node);
                return ret;
            }
            else
                return parent;
        }

        return LLONG_MAX;
    };

    for(int i = 1; i <= n; i++){
        if(!vis[i])
            dfs(i, 0);
        
        if(!ans.empty())
            break;
    }

    if(ans.empty())
        cout << "IMPOSSIBLE\n";
    else{
        ans.push_back(ans[0]);

        cout << ans.size() << "\n";
        for(auto i: ans)
            cout << i << " ";
        cout << "\n";
    }
}
