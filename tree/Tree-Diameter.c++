🔍 Key Observations:
--------------------------
1. A tree is an acyclic connected graph, so there is exactly one path between any two nodes.
2. The diameter of the tree is the longest such path.
3. This longest path passes through the two deepest subtrees of some node.

🧭 Core Idea:
---------------------------
1. Use Depth-First Search (DFS) to compute:
2. The height of each subtree.
3. The two longest paths going down from each node to its descendants.
4. At every node, calculate a candidate diameter as the sum of these two longest paths.
5. Keep track of the maximum diameter found during the traversal.

 

💻 Code
------------------------
 
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
using namespace std;

const int MOD = 1000000007;
 
int dfs(int node, vi adj[], int parent, int &ans){
    
    priority_queue<int, vi, greater<int>> q;
    int height = 0;
    for(auto nbr : adj[node]){
        if(nbr == parent)
            continue;
 
        int h = dfs(nbr, adj, node, ans) + 1;
        height = max(height, h);
 
        if(q.size() < 2)
            q.push(h);
        else{
            if(q.top() < h)
                q.pop(), q.push(h);
        }
    }
    
    int tot = 0;
    while(!q.empty())
        tot += q.top(), q.pop();
      
    ans = max(ans, tot);
    return height;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, a, b;
    cin >> n;
 
    vi adj[n+1];
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    int ans = 0;
    dfs(1, adj, -1, ans);
 
    cout << ans << '\n';
}
