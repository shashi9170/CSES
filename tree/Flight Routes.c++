#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k, u, v, w;
    cin >> n >> m >> k;
 
    vector<pair<int, int>> adj[n+1];
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
 
        adj[u].push_back({v, w});
    }
 
    priority_queue<int> dp[n+1];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
    q.push({0, 1});
    dp[1].push(0);

    while(!q.empty()){
        auto [cost, node] = q.top();
        q.pop();

        if(cost > dp[node].top())
            continue;

        for(auto &[nbr, wt]: adj[node]){
            int new_cost = cost + wt;

            if(dp[nbr].size() < k)
                dp[nbr].push(new_cost), q.push({new_cost, nbr});
            else if(dp[nbr].top() > new_cost){
                dp[nbr].pop();
                dp[nbr].push(new_cost);
                q.push({new_cost, nbr});
            }
        }
    }
    

    vector<int> ans;
    while(!dp[n].empty()){
        ans.push_back(dp[n].top());
        dp[n].pop();
    }

    sort(ans.begin(), ans.end());

    for(auto it: ans)
        cout << it << " ";
}
