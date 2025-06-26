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

    function<void(int)> dfs = [&](int node){
        vis[node] = 1;

        for(auto nbr: tran[node]){
            if(vis[nbr])
                continue;
            
            dfs(nbr);
        }
    };

    int last = st.top();

    dfs(st.top());
    vis[st.top()] = 1;
    st.pop();

    while(!st.empty()){
        auto node = st.top();
        st.pop();

        if(vis[node])
            continue;
        
        cout << "NO\n" << node << " " << last << "\n";
        exit(0);
    }

    cout << "YES\n";
}
