#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, u, v, w;
    cin >> n >> m;
 
    vector<pair<int, int>> adj[n+1], trans[n+1];
    vector<tuple<int, int, int>> e;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
 
        adj[u].push_back({v, w});
        trans[v].push_back({u, w});
        e.push_back({u, v, w});
    }
 
    vector<int> dp1(n+1, LLONG_MAX), dp2(n+1, LLONG_MAX);
    set<pair<int, int>> st;
 
    dp1[1] = 0;
    st.insert({0, 1});
 
    while(!st.empty()){
        auto [cost, node] = *st.begin();
        st.erase(st.begin());
 
        for(auto &[nbr, wt]: adj[node]){
            auto it = st.find({dp1[nbr], nbr});
 
            if(dp1[nbr] > wt + dp1[node]){
                if(it != st.end())
                    st.erase(it);
 
                dp1[nbr] = wt + dp1[node];
                st.insert({ dp1[nbr], nbr });
            }
        }
    }
 
    dp2[n] = 0;
    st.insert({0, n});
    while(!st.empty()){
        auto [cost, node] = *st.begin();
        st.erase(st.begin());
 
        for(auto &[nbr, wt]: trans[node]){
            auto it = st.find({dp2[nbr], nbr});
 
            if(dp2[nbr] > wt + dp2[node]){
                if(it != st.end())
                    st.erase(it);
 
                dp2[nbr] = wt + dp2[node];
                st.insert({ dp2[nbr], nbr });
            }
        }
    }
 
    int ans = LLONG_MAX;
 
    for(auto &[u, v, wt]: e){
        if(dp1[u] == LLONG_MAX || dp2[v] == LLONG_MAX)
            continue;
        
        ans = min(ans, dp1[u] + dp2[v] + wt / 2);
    }
 
    cout << ans << "\n";
}
