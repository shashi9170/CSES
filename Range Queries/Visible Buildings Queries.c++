#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, a, b;
    cin >> n >> q;

    vector<int> h(n+1), dp(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];

    stack<int> st;
    h[n] = 1e18, st.push(n);

    for(int i = n - 1; i >= 0; i--){
        while(h[st.top()] <= h[i])
            st.pop();

        dp[i] = st.top();
        st.push(i);
    }

    vector<vector<int>> table(n+1, vector<int>(22));
    for(int i = 0; i < n; i++)
        table[i][0] = dp[i];

    for(int j = 1; j <= 20; j++){
        for(int i = 0; i < n; i++){
            if(table[i][j-1] <= n-1)
                table[i][j] = table[table[i][j-1]][j-1];
            else
                table[i][j] = n;
        }
    }


    for(int i = 0; i < q; i++){
        int ans = 1;
        cin >> a >> b;

        a--, b--;

        for(int j = 20; j >= 0; j--){
            if(table[a][j] <= b)
                ans += (1 << j), a = table[a][j]; 
        }

        cout << ans << "\n";
    }
}
