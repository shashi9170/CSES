#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, u, v, w;
    cin >> n >> m;

    vector<pair<int, int>> adj[n+1];
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    vector<int> cost(n+1, LLONG_MAX);
    set<pair<int, int>> st;

    cost[1] = 0;
    st.insert({0, 1});

    while(!st.empty()){
        auto [_, node] = *st.begin();
        st.erase(st.begin());

        for(auto &[nbr, w]: adj[node]){
            int new_wt = cost[node] + w;
            auto it = st.find({ cost[nbr], nbr });

            if(cost[nbr] > new_wt){
                if(it != st.end())
                    st.erase(it);

                cost[nbr] = new_wt;
                st.insert({new_wt, nbr});
            }
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(3));
    for(int i = 0; i <= n; i++)
        dp[i][0] = LLONG_MAX, dp[i][1] = LLONG_MIN;

    dp[1][0] = dp[1][1] = 0, dp[1][2] = 1;
    st.insert({0, 1});

    while(!st.empty()){
        auto [_, node] = *st.begin();
        st.erase(st.begin());

        for(auto &[nbr, w]: adj[node]){
            int new_wt = cost[node] + w;

            if(cost[nbr] == new_wt){
                dp[nbr][0] = min(dp[nbr][0], dp[node][0] + 1);
                dp[nbr][1] = max(dp[nbr][1], dp[node][1] + 1);
                dp[nbr][2] = (dp[nbr][2] + dp[node][2]) % MOD;

                auto it = st.find({cost[nbr], nbr});

                if(it != st.end())
                    continue;
                    
                st.insert({cost[nbr], nbr});
            }
        }
    }

    cout << cost[n] << " " << dp[n][2] << " " << dp[n][0] << " " << dp[n][1] << "\n";
}
