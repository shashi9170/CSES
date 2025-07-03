#include <bits/stdc++.h>
#define int long long
using namespace std;

#define vi vector<int>
#define v2i vector<vi>

void dfs(int node, int parent, int l, int log, vi a[], vi &lvl, vi &vis, v2i &dp){
    dp[node][0] = parent, vis[node] = 1, lvl[node] = l;
 
    for(int i = 1; i <= log; i++)
        dp[node][i] = dp[dp[node][i-1]][i-1];
 
    for(auto nbr : a[node]){
        if(vis[nbr])
            continue;
 
        dfs(nbr, node, l + 1, log, a, lvl, vis, dp);
    }
}
 
int distance(int u, int v, int log, vi &lvl, v2i &dp){
    if(lvl[u] < lvl[v])
        swap(u, v);
    
    int ans = 0;
    for(int i = log; i >= 0; i--){
        if(lvl[u] - (1 << i) >= lvl[v])
            ans += (1 << i), u = dp[u][i];
    }
 
    if(u == v)
        return ans;
 
    for(int i = log; i >= 0; i--){
        if(dp[u][i] != dp[v][i])
            ans += 2 * (1 << i), u = dp[u][i], v = dp[v][i];
    }
 
    return ans + 2;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, x, y;
    cin >> n >> q;
 
    vi a[n+1], vis(n+1), lvl(n+1);
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
 
        a[x].push_back(y);
        a[y].push_back(x);
    }
 
    int log = log2(n) + 1;
    v2i dp(n + 1, vi(log + 1));
 
    dfs(1, 1, 1, log, a, lvl, vis, dp);
 
    for(int i = 0; i < q; i++){
        cin >> x >> y;
 
        cout << distance(x, y, log, lvl, dp) << '\n';
    }
}
