#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    unordered_map<int, int> freq;
    set<int> missing; 

    for (int i = 0; i <= n; ++i)
        missing.insert(i);

    vector<int> ans;

    for (int i = 0; i < k; ++i) {
        freq[a[i]]++;
        missing.erase(a[i]);
    }

    ans.push_back(*missing.begin());

    for (int i = k; i < n; ++i) {

        int out = a[i - k];
        freq[out]--;
        if (freq[out] == 0)
            missing.insert(out);


        int in = a[i];
        freq[in]++;
        if (freq[in] == 1)
            missing.erase(in);

        ans.push_back(*missing.begin());
    }

    for (int x : ans)
        cout << x << ' ';
    cout << '\n';
}
