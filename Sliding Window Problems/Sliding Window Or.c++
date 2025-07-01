#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    vector<int> dp(n + 1);
    dp[1] = x;

    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] * a + b) % c;

    vector<int> dpk(31);
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= 30; j++)
            dpk[j] += (dp[i] & (1 << j));
    }

    int ans = 0;
    for(int i = 0; i <= 30; i++){
        if(dpk[i])
            ans ^= (1 << i);
    }

    for (int i = k+1; i <= n; i++) {
        for(int j = 0; j <= 30; j++){
            dpk[j] -= (dp[i-k] & (1 << j)),
            dpk[j] += (dp[i] & (1 << j));
        
            if(dpk[j])
                ans ^= (1 << j);
        }
    }


    cout << ans << "\n";
}
