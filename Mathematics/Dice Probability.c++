#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    const int MAX_SUM = 600;
    vector<vector<long double>> dp(n+1, vector<long double>(MAX_SUM+1, 0));
    
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int sum = 0; sum <= 6 * (i - 1); sum++) {
            for(int face = 1; face <= 6; face++) {
                dp[i][sum + face] += dp[i-1][sum];
            }
        }
    }

    long double total_ways = pow(6.0, n);
    long double favorable = 0.0;

    for(int sum = a; sum <= b; sum++) {
        favorable += dp[n][sum];
    }

    cout << fixed << setprecision(6) << favorable / total_ways << "\n";
}
