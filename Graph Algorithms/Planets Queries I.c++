#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int LOG = 30;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, x, k;
    cin >> n >> q;

    vector<int> t(n+1);
    for(int i = 1; i <= n; i++)
        cin >> t[i];

    int dp[n+1][LOG];
    for(int i = 1; i <= n; i++)
        dp[i][0] = t[i];

    for(int j = 1; j < LOG; j++){
        for(int i = 1; i <= n; i++)
            dp[i][j] = dp[dp[i][j-1]][j-1];
    }

    for(; q; q--){
        cin >> x >> k;

        int i = LOG-1;
        for(; i >= 0; i--){
            if(k >= (1 << i))
                x = dp[x][i], k -= (1 << i);
        }

        cout << x << "\n";
    }
}
