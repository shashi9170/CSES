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

    vector<int> vis(n+1), parent(n+1, -1), dist(n+1);
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

    if(!vis[n]){
        cout << "IMPOSSIBLE\n";
        exit(0);
    }

    dist[1] = 1;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto nbr: adj[node]){
            int new_d = dist[node] + 1;

            if(dist[nbr] < new_d)
                dist[nbr] = new_d, parent[nbr] = node;
        }
    }

    vector<int> path{n};
    int node = parent[n];

    while(node != -1){
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(auto it : path)
        cout << it << " ";
}
