#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> x(n), p(n), dp(n+1);
    for(int i = 0; i < n; i++)
        cin >> x[i], p[i] = x[i];
    
    for(int i = 1; i < n; i++)
        p[i] += p[i-1];

    vector<int> next(n, n-1);
    stack<int> st;
    st.push(n-1);

    for(int i = n - 2; i >= 0; i--){
        while(!st.empty() && x[st.top()] <= x[i])
            st.pop();

        if(!st.empty())
            next[i] = st.top(),
            dp[i] = ((st.top() - i) * x[i] - (p[st.top()-1] - (i ? p[i-1] : 0))) + dp[st.top()];
        else
            dp[i] = ((n - i) * x[i] - (p[n-1] - (i ? p[i-1] : 0)));

        st.push(i);
    }

    vector<vector<int>> table(n, vector<int>(25));
    for(int i = 0; i < n; i++)
        table[i][0] = next[i];

    for(int j = 1; j < 25; j++){
        for(int i = 0; i < n; i++)
            table[i][j] = table[table[i][j-1]][j-1];
    }

    int a, b;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        a--, b--;

        int res = a;
        
        for(int i = 24; i >= 0; i--){
            if(table[res][i] <= b)
                res = table[res][i];
        }

        int ans = 0;
        if(a < res)
            ans = dp[a] - dp[res];

        ans += (b - res) * x[res] - (p[b] - p[res]);
        cout << ans << "\n";
    }
}
