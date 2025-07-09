#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int power(int x, int n = MOD - 2){
    int res = 1;

    while(n){
        if(n & 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }

    return res;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    map<int, int> dp;
    int ans = 0, prod = 1;
    for(int i = 1; i <= n; i++){
        
        if(!dp[a[i]])
            dp[a[i]] = 1;
        else
            prod = (prod * power(dp[a[i]])) % MOD;

        ans = (ans + prod) % MOD;
        dp[a[i]]++;

        prod = (prod * dp[a[i]]) % MOD;
    }

    cout << ans << "\n";
}
