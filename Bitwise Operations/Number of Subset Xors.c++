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

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> dp(31);
    for(int i = 0; i < n; i++){
        int x = a[i];

        for(; x; ){
            if(dp[__builtin_ctz(x)])
                x ^= dp[__builtin_ctz(x)];
            else{
                dp[__builtin_ctz(x)] = x;
                break;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i <= 30; i++)
        cnt += (dp[i] ? 1 : 0);

    int ans = (1 << cnt);

    cout << ans << "\n";
}
