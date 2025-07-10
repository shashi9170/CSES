#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }


    string ans = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            ans += " ";
            string s = to_string(a[i-1]);
            reverse(s.begin(), s.end());

            ans += s;
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(ans.begin(), ans.end());

    cout << dp[n][m] << "\n" << ans << "\n";
}
