#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
int dp[51];

void preprocess(){
    for(int i = 1; i <= 50; i++)
        dp[i] = (1LL << (i - 1)) + 2 * dp[i-1];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    preprocess();

    int n;
    cin >> n;

    int ans = 0;
    for(; n;){
        int i = 50;
        for(; i >= 0; i--){
            if(n & (1LL << i))
                break;
        }

        if(n == (1LL << (i + 1)) - 1){
            ans += dp[i+1];
            break;
        }

        ans += dp[i];
        ans += (n - (1LL << i) + 1);

        n ^= (1LL << i);
    }

    cout << ans << "\n";
}
