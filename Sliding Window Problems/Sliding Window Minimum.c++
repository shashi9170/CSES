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

    deque<int> dq;
    vector<int> mins;

    for (int i = 1; i <= n; i++) {
        
        while (!dq.empty() && dp[dq.back()] >= dp[i])
            dq.pop_back();

        dq.push_back(i);

        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        if (i >= k)
            mins.push_back(dp[dq.front()]);
    }

    int ans = 0;
    for (int val : mins)
        ans ^= val;

    cout << ans << "\n";
}
