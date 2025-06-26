#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, u, v;
    cin >> n >> m;

    vector<int> adj[n+1], tran[n+1]; 
    for(int i = 0; i < m; i++){
        cin >> u >> v;

        adj[u].push_back(v);
        tran[v].push_back(u);
    }

    stack<int> st;
    vector<int> vis(n+1);

    function<void(int)> topologicalSort = [&](int node){
        vis[node] = 1;

        for(auto nbr: adj[node]){
            if(vis[nbr])
                continue;
            
            topologicalSort(nbr);
        }

        st.push(node);
    };

    for(int i = 1; i <= n; i++){
        if(vis[i])
            continue;

        topologicalSort(i);
    }

    fill(vis.begin(), vis.end(), 0);

    function<void(int, int)> dfs = [&](int node, int kingdom){
        vis[node] = kingdom;

        for(auto nbr: tran[node]){
            if(vis[nbr])
                continue;
            
            dfs(nbr, kingdom);
        }
    };

    int kingdom = 0;
    while(!st.empty()){
        auto node = st.top();
        st.pop();

        if(vis[node])
            continue;
        
        dfs(node, ++kingdom);
    }

    cout << kingdom << "\n";

    for(int i = 1; i <= n; i++)
        cout << vis[i] << " ";
    cout << "\n";
}
