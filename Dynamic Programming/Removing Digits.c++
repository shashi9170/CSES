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

    vector<int> dp(n+1, LLONG_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        string s = to_string(i);

        for(int j = 0; j < s.length(); j++)
            dp[i] = min(dp[i], dp[i - s[j] + '0'] + 1);
    }

    cout << dp[n] << "\n";
}
