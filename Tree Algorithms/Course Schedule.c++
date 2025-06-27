#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n+1);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;

        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    vector<int> ans;

    for(int i = 1; i <= n; i++)
        if(indeg[i] == 0)
            q.push(i);

    while(!q.empty()){
        auto node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto nbr: adj[node]){
            indeg[nbr]--;

            if(indeg[nbr] == 0)
                q.push(nbr);
        }
    }

    if(ans.size() != n)
        cout << "IMPOSSIBLE\n";
    else{
        for(auto it: ans)   
            cout << it << " ";
        cout << "\n";
    }
}
