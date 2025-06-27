#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> dp;

void preprocess(int N){
    for(int i = 0; i * i <= N; i++){
        for(int j = 0; j <= i && (i * i + j * j) <= N; j++)
            dp.emplace_back(i * i + j * j, i, j);
    }

    sort(dp.begin(), dp.end());
}

vector<int> FourSquareSum(int n){
    int l = 0, r = dp.size()-1;

    while(l <= r){
        auto [ab_s, a, b] = dp[l];
        auto [cd_s, c, d] = dp[r];

        if(ab_s + cd_s == n)
            return {a, b, c, d};

        if(ab_s + cd_s < n)
            l++;
        else
            r--;
    }

    return {0, 0, 0, 0};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> a;
    for(int i = 0, n; i < t; i++){
        cin >> n;

        a.push_back(n);
    }

    preprocess(*max_element(a.begin(), a.end()));

    for(int i = 0; i < a.size(); i++){
        vector<int> res = FourSquareSum(a[i]);

        cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << "\n";
    }
}
