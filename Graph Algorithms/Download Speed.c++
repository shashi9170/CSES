#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v, w;
    cin >> n >> m;

    vector<int> adj[n+1];
    vector<vector<int>> capacity(n+1, vector<int>(n+1));

    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;

        adj[u].push_back(v);
        adj[v].push_back(u);

        capacity[u][v] += w;
    }     

    vector<int> parent(n+1);

    auto reachable = [&](){

        queue<int> q;
        fill(parent.begin(), parent.end(), -1);

        q.push(1);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto nbr: adj[node]){
                if(parent[nbr] != -1 || capacity[node][nbr] <= 0)
                    continue;

                q.push(nbr);
                parent[nbr] = node;
            }
        }

        return (parent[n] != -1);
    };


    int ans = 0;
    while(reachable()){
        int node = n, flow = LLONG_MAX;

        while(node != 1){
            flow = min(flow, capacity[parent[node]][node]);

            node = parent[node];
        }

        node = n;
        while(node != 1){
            capacity[parent[node]][node] -= flow;
            capacity[node][parent[node]] += flow;

            node = parent[node];
        }

        ans += flow;
    }

    cout << ans << "\n";
}
