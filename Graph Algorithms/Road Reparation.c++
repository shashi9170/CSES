#include <bits/stdc++.h>
#define int long long
using namespace std;

struct dsu{
    int n;
    vector<int> parent, rank;

    dsu(int n){
        this->n = n;
        parent.resize(n+2);
        rank.resize(n+2);

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

    void _union(int u, int v){
        int up = find(u), vp = find(v);

        if(rank[up] < rank[vp])
            swap(up, vp);
        
        parent[vp] = up;
        rank[up] += rank[vp];
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v, w;
    cin >> n >> m;

    vector<vector<int>> e;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;

        e.push_back({u, v, w});
    }

    sort(e.begin(), e.end(), [&](vector<int> i, vector<int> j){
        return i[2] < j[2];
    });

    dsu t(n+1);

    int ans = 0;
    for(auto it: e){
        u = it[0], v = it[1], w = it[2];

        if(t.isCycle(u, v))
            continue;

        ans += w;
        t._union(u, v);
    }

    int components = 0;
    for(int i = 1; i <= n; i++){
        if(t.find(i) == i)
            components++;
    }

    if(components >= 2){
        cout << "IMPOSSIBLE\n";
        exit(0);
    }

    cout << ans << "\n";
}
