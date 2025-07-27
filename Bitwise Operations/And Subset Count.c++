#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int BITS = 18;
const int MAX = (1 << BITS);

int a[MAX], pow2[MAX], dp[MAX];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        dp[a[i]]++;

    pow2[0] = 1;

    for(int i = 1; i < MAX; i++)
        pow2[i] = (pow2[i-1] * 2) % MOD;
    
    for(int i = 0; (1 << i) <= n; i++){
        for(int j = 0; j <= n; j++){
            if((j & (1 << i)) == 0 && (j | (1 << i)) <= n)
                dp[j] += dp[j | (1 << i)];
        }
    }

    for(int i = 0; i < MAX; i++)
        dp[i] = (pow2[dp[i]] - 1 + MOD) % MOD;
    
    for(int i = 0; (1 << i) <= n; i++){
        for(int j = 0; j <= n; j++){
            if((j & (1 << i)) == 0 && (j | (1 << i)) <= n)
                dp[j] = (dp[j] - dp[j | (1 << i)] + MOD) % MOD;
        }
    }

    for(int i = 0; i <= n; i++)
        cout << dp[i] << " ";
    cout << "\n";
}
