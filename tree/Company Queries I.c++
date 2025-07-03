#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, x, k;
    cin >> n >> q;

    vector<vector<int>> dp(n+1, vector<int>(21));

    for(int i = 2; i <= n; i++)
        cin >> dp[i][0];

    for(int j = 1; j <= 20; j++){
        for(int i = 1; i <= n; i++)
            dp[i][j] = dp[dp[i][j-1]][j-1];
    }

    for(; q; q--){
        cin >> x >> k;

        for(int i = 20; i >= 0; i--){
            if(k >= (1 << i))
                x = dp[x][i], k -= (1 << i);
        }

        if(x)
            cout << x << "\n";
        else
            cout << "-1\n";
    }
}
