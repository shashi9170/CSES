#include <bits/stdc++.h>
#define int long long
using namespace std;

struct dsu{
    vector<int> parent, rank;

    dsu(int n){
        parent.resize(n+2);
        rank.resize(n+2, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node){
        if(node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    int isCycle(int u, int v){
        return find(u) == find(v);
    }

    int Size(int u){
        return rank[find(u)];
    }

    void _union(int u, int v){
        int up = find(u), vp = find(v);

        if(rank[up] < rank[vp])
            swap(up, vp);
        
        parent[vp] = up;
        rank[up] += rank[vp];
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, u, v;
    cin >> n >> m;

    vector<pair<int, int>> e; 
    for(int i = 0; i < m; i++){
        cin >> u >> v;

        e.push_back({u, v});
    }

    dsu t(n+1);
    int components = n, maxi_size = 1;

    for(auto &[u, v]: e){
        if(t.isCycle(u, v)){
            cout << components << " " << maxi_size << "\n";
            continue;
        }
        
        t._union(u, v);
        components--;

        maxi_size = max({ maxi_size, t.Size(u), t.Size(v) });

        cout << components << " " << maxi_size << "\n";
    }
}
