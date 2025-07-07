#include <bits/stdc++.h>
#define int long long
using namespace std;

struct seg {
    vector<int> dp;
    vector<pair<int, int>> p; // {type (0:add, 1:set), value}

    seg(int n): dp(4 * n), p(4 * n) {}

    void propagate(int ss, int se, int si) {
        auto [t, x] = p[si];
        if (t) {
            dp[si] = (se - ss + 1) * x;
            if (ss != se)
                p[2 * si + 1] = p[2 * si + 2] = {t, x};
        } else if (x != 0) {
            dp[si] += (se - ss + 1) * x;
            if (ss != se) {
                p[2 * si + 1].second += x;
                if (p[2 * si + 1].first != 1) p[2 * si + 1].first = 0;
                p[2 * si + 2].second += x;
                if (p[2 * si + 2].first != 1) p[2 * si + 2].first = 0;
            }
        }
        p[si] = {0, 0};
    }

    void build(int ss, int se, int si, vector<int> &a) {
        if (ss == se) {
            dp[si] = a[ss];
            return;
        }

        int mid = (ss + se) / 2;
        build(ss, mid, 2 * si + 1, a);
        build(mid + 1, se, 2 * si + 2, a);
        dp[si] = dp[2 * si + 1] + dp[2 * si + 2];
    }

    void update(int ss, int se, int si, int tp, int qs, int qe, int x) {
        propagate(ss, se, si);

        if (qe < ss || se < qs)
            return;

        if (qs <= ss && se <= qe) {
            p[si] = {tp, x};
            propagate(ss, se, si);
            return;
        }

        int mid = (ss + se) / 2;
        update(ss, mid, 2 * si + 1, tp, qs, qe, x);
        update(mid + 1, se, 2 * si + 2, tp, qs, qe, x);
        dp[si] = dp[2 * si + 1] + dp[2 * si + 2];
    }

    int query(int ss, int se, int si, int qs, int qe) {
        propagate(ss, se, si);

        if (qe < ss || se < qs)
            return 0;

        if (qs <= ss && se <= qe)
            return dp[si];

        int mid = (ss + se) / 2;
        return query(ss, mid, 2 * si + 1, qs, qe) +
               query(mid + 1, se, 2 * si + 2, qs, qe);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    seg t(n);
    t.build(0, n - 1, 0, arr);

    while (q--) {
        int tp, a, b, x;
        cin >> tp >> a >> b;
        a--, b--; // make 0-based

        if (tp == 1) {
            cin >> x;
            t.update(0, n - 1, 0, 0, a, b, x); // add
        } else if (tp == 2) {
            cin >> x;
            t.update(0, n - 1, 0, 1, a, b, x); // set
        } else {
            cout << t.query(0, n - 1, 0, a, b) << "\n";
        }
    }
}
