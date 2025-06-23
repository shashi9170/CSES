🔍 Key Observations
-------------------------------
1. Since the graph is a tree, there is only one simple path between any two nodes.
2. The maximum distance from any node is equal to the longest path (depth) from it in the tree.
3. Naively computing distances from each node would take O(n²) — too slow for large trees.
4. Instead, we can solve this in two depth-first searches (DFS) with smart reuse of data.


🧠 Core Concepts Used
--------------------------------
1. Depth of Subtree (Downward Distance)
   1.1. First, compute the longest path from each node downwards into its subtree.
   1.2. For each node, record the depth of the deepest child.
     (This gives us one possible direction of the max distance.)

2. Rerooting Technique (Upward + Sibling Paths)
  2.1. A node’s max distance might go upward toward its parent and then down into a different subtree.
  2.2. To account for this, we perform a second DFS, passing information about the maximum path from the parent and sibling subtrees.
  2.3. We use a multiset or tracking of top two maximum depths among children to efficiently compute what distance to pass down when we "move the root" to each child.


⚙️ Approach Summary
--------------------------------
✅ Step 1: First DFS – Compute Downward Distances
        1.1. For each node, calculate the maximum depth into its subtree.
        1.2. This means: the longest path to a leaf starting from that node and moving only downward.

🔄 Step 2: Second DFS – Rerooting and Propagating Upward Distances
        2.1. Reuse the previously computed depths.
        2.2. For each node, determine the maximum distance not just within its subtree, but also including paths through its parent.
        2.3. This accounts for cases where the farthest node lies outside its own subtree.

📤 Final Step: Print Answers
      After both DFS runs, for each node, we now know the maximum distance to any other node in the tree.


💻 Code
------------------------

#include <bits/stdc++.h>
#define int long long
 
#define vi vector<int> 
using namespace std;
 
int dfs(int node, vi a[], vi &vis, vi &dp){
    vis[node] = 1;
 
    for(auto nbr : a[node]){
        if(vis[nbr])
            continue;
 
        dp[node] = max(dp[node], dfs(nbr, a, vis, dp) + 1);
    }
 
    return dp[node];
}
 
int dfs(int node, int parent, int maxi, vi a[], vi &dp, vi &dp1){
    
    multiset<int, greater<int>> s;
    s.insert(maxi);
 
    for(auto nbr : a[node]){
        if(nbr == parent)
            continue;
 
        s.insert(dp[nbr] + 1);
    }
 
    int leaf = 0, ans = 0;
    for(auto nbr : a[node]){
        if(nbr == parent)
            continue;
 
        leaf++;
 
        s.erase(s.find(dp[nbr]+1));
        ans = max(ans, dfs(nbr, node, *s.begin() + 1, a, dp, dp1) + 1);
        s.insert(dp[nbr]+1);
    }
 
    dp1[node] = max(ans, maxi);
 
    return dp[node];    
}
 
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, q, x, y;
    cin >> n;
 
    vi a[n+1], vis(n+1);
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
 
        a[x].push_back(y);
        a[y].push_back(x);
    }
 
    vi dp(n+1), ans(n+1);
    dfs(1, a, vis, dp);
    dfs(1, 1, 0, a, dp, ans);
 
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}
