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
 
void Question()
{
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
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Question();
}