#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6 + 5;
int dp[MAXN];

void update(int index, int val) {
    for (++index; index < MAXN; index += index & -index)
        dp[index] += val;
}

int query(int index) {
    int ans = 0;
    for (++index; index > 0; index -= index & -index)
        ans += dp[index];
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i;
    }

    // Coordinate compression
    sort(x.begin(), x.end());
    map<int, int> compress;
    vector<int> new_x(n);

    int compressed_val = 0;
    for (int i = 0; i < n; i++) {
        if (!compress.count(x[i].first))
            compress[x[i].first] = compressed_val++;
        new_x[x[i].second] = compress[x[i].first];
    }

    int inversionk = 0;
    vector<int> ans;

    for (int i = 0; i < k; i++) {
        inversionk += query(MAXN - 2) - query(new_x[i]);
        update(new_x[i], 1);
    }
    ans.push_back(inversionk);

    for (int i = k; i < n; i++) {

        update(new_x[i - k], -1);
        inversionk -= query(new_x[i - k] - 1);


        inversionk += query(MAXN - 2) - query(new_x[i]);
        update(new_x[i], 1);

        ans.push_back(inversionk);
    }

    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
}
