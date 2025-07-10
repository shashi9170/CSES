#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int s = accumulate(a.begin(), a.end(), 0LL);
    vector<vector<int>> dp(n+1, vector<int>(s+1));

    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= s; j++){
            dp[i][j] = dp[i-1][j];

            if(j - a[i] >= 0)
                dp[i][j] |= dp[i-1][j - a[i]];
        }
    }    

    vector<int> ans;
    for(int i = 1; i <= s; i++){
        if(dp[n][i])
            ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}
