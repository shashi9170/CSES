#include <bits/stdc++.h>
#include <cfenv>
#define int long long
#define ld long double

#pragma STDC FENV_ACCESS ON

using namespace std;

ld power(ld x, int n) {
    ld res = 1.0;
    while(n) {
        if(n & 1)
            res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fesetround(FE_TONEAREST);

    int n, k;
    cin >> n >> k;

    ld ans = 0;
    for(int i = 1; i <= k; i++) {
        ld term = (power((ld)i / k, n) - power((ld)(i - 1) / k, n));
        ans += i * term;
    }

    ans = nearbyint(ans * 1e6) / 1e6;

    cout << fixed << setprecision(6) << ans << "\n";
}
