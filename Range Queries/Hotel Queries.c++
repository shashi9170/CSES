#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5 + 2;
vector<int> dp(4 * MAXN), a(MAXN);

void build(int ss, int se, int si){
    if(ss == se){
        dp[si] = a[ss];
        return;
    }

    int mid = (ss + se) / 2;

    build(ss, mid, 2 * si + 1);
    build(mid + 1, se, 2 * si + 2);

    dp[si] = max(dp[2*si+1], dp[2*si+2]);
}


void queryUpdate(int ss, int se, int si, int x){
    if(ss == se){
        dp[si] -= x;
        cout << ss + 1 << " ";
    }
    else{
        int mid = (ss + se) / 2;

        if(dp[2*si+1] >= x)
            queryUpdate(ss, mid, 2 * si + 1, x);
        else
            queryUpdate(mid + 1, se, 2 * si + 2, x);

        dp[si] = max(dp[2*si+1], dp[2*si+2]);
    }
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(0, n-1, 0);

    for(int i = 0; i < m; i++){
        cin >> x;

        if(dp[0] < x)
            cout << 0 << " ";
        else
            queryUpdate(0, n-1, 0, x);
    }

    cout << "\n";
}
