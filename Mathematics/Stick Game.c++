#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> p(k);
    for (int i = 0; i < k; i++)
        cin >> p[i];

    sort(p.begin(), p.end());

    vector<int> dp(n + 1, 0);
    string ans = "";

    for (int i = 1; i <= n; i++) {

        vector<bool> seen(k + 1, false);

        for (int j = 0; j < k && p[j] <= i; j++) {
            seen[dp[i - p[j]]] = true;
        }

        int g = 0;
        while (g <= k && seen[g]) g++;
        dp[i] = g;

        ans += (dp[i] ? 'W' : 'L');
    }

    cout << ans << "\n";
}
