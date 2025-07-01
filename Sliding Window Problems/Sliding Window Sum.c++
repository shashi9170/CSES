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

    vector<int> sum_w;

    int s = 0;
    for(int i = 1; i <= k; i++)
        s += dp[i];

    sum_w.push_back(s);

    for (int i = k+1; i <= n; i++) {
        s = s - dp[i-k] + dp[i];

        sum_w.push_back(s);
    }

    int ans = 0;
    for (int val : sum_w)
        ans ^= val;

    cout << ans << "\n";
}
