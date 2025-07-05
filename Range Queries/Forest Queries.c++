#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, x1, y1, x2, y2;
    cin >> n >> q;

    vector<string> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            dp[i][j] = (a[i-1][j-1] == '*');

        for(int j = 1; j <= n; j++)
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    }

    function<int(int, int, int, int)> query = [&](int x1, int y1, int x2, int y2){
        return (dp[y2][x2] + dp[y1-1][x1-1] - dp[y2][x1-1] - dp[y1-1][x2]);
    };

    for(int i = 0; i < q; i++){
        cin >> y1 >> x1 >> y2 >> x2;

        cout << query(x1, y1, x2, y2) << "\n";
    }
}
