#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(31, 0);

    for(int x : a) {
        for (int i = 30; i >= 0; i--) {
            if (!(x & (1LL << i))) 
                continue;

            if (!dp[i]) {
                dp[i] = x;
                break;
            }

            x ^= dp[i];
        }
    }

    int ans = 0;
    for(int i = 30; i >= 0; i--) {
        ans = max(ans, ans ^ dp[i]);
    }

    cout << ans << "\n";
}
