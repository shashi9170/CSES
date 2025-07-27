#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int BITS = 20;
const int MAX = (1 << BITS);

static int a[MAX], freq[MAX], or_dp[MAX], and_dp[MAX], nonzero_dp[MAX];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        freq[a[i]]++;

    for(int i = 0; i < MAX; i++) {
        or_dp[i] = freq[i];
        and_dp[i] = freq[i];
        nonzero_dp[i] = freq[i];
    }

    // (x | y) == x
    for(int j = 0; j < BITS; j++) {
        for(int i = 0; i < MAX; i++) {
            if ( (i & (1 << j)) == 0 ) {
                or_dp[i | (1 << j)] += or_dp[i];
            }
        }
    }

    // (x & y) == x
    for(int j = 0; j < BITS; j++) {
        for(int i = 0; i < MAX; i++) {
            if ( (i & (1 << j)) != 0 ) {
                and_dp[i ^ (1 << j)] += and_dp[i];
            }
        }
    }

    // (x & y) == 0
    for(int j = 0; j < BITS; j++) {
        for(int i = 0; i < MAX; i++) {
            if ( (i & (1 << j)) == 0 ) {
                nonzero_dp[i | (1 << j)] += nonzero_dp[i];
            }
        }
    }

    for(int i = 0; i < n; i++){
        int x = a[i];
        int res_or = or_dp[x];
        int res_and = and_dp[x];
        int res_nonzero = n - nonzero_dp[(~x) & (MAX - 1)];

        cout << res_or << " " << res_and << " " << res_nonzero << "\n";
    }
}
