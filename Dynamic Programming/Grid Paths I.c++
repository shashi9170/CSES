#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(n));

    dp[0][0] = (a[0][0] == '.');
    for(int i = 1; i < n; i++)
        dp[i][0] = ( a[i][0] == '*' ? 0 : dp[i-1][0]);

    for(int j = 1; j < n; j++)
        dp[0][j] = ( a[0][j] == '*' ? 0 : dp[0][j-1]);

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(a[i][j] == '*')
                continue;
            
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[n-1][n-1] << "\n";
}
