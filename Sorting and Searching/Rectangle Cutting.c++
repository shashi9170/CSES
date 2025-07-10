#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, LLONG_MAX));

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j)
                dp[i][j] = 0;
            else{
                for(int h = 1; h < i; h++)
                    dp[i][j] = min(dp[i][j], dp[i-h][j] + dp[h][j] + 1);

                for(int v = 1; v < j; v++)
                    dp[i][j] = min(dp[i][j], dp[i][j-v] + dp[i][v] + 1);
            }
        }
    }

    cout << dp[a][b] << "\n";
}
