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

    vector<int> xor_w;

    int xor_k = 0;
    for(int i = 1; i <= k; i++)
        xor_k ^= dp[i];

    xor_w.push_back(xor_k);

    for (int i = k+1; i <= n; i++) {
        xor_k = xor_k ^ dp[i-k] ^ dp[i];

        xor_w.push_back(xor_k);
    }

    int ans = 0;
    for (int val : xor_w)
        ans ^= val;

    cout << ans << "\n";
}
