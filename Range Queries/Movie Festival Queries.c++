#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6 + 1;
int dp[MAXN][20];
vector<int> a[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;

        a[x].push_back(y);
    }

    priority_queue<int, vector<int>, greater<int>> ends;

    for(int i = MAXN - 1; i; i--){
        for(auto y: a[i])
            ends.push(y);

        dp[i][0] = (ends.empty() ? MAXN : ends.top());
    }

    for(int j = 1; j < 20; j++){
        for(int i = 1; i < MAXN; i++){
            if(dp[i][j-1] < MAXN)
                dp[i][j] = dp[dp[i][j-1]][j-1];
            else
                dp[i][j] = MAXN;
        }
    }

    for(int l, r; q; q--){
        cin >> l >> r;

        int ans = 0;
        for(int i = 19; i >= 0; i--){
            if(dp[l][i] <= r)
                ans += (1 << i), l = dp[l][i];
        }

        cout << ans << "\n";
    }
}
