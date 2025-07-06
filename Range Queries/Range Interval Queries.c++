#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

const int MAXN = 4e5 + 5;

struct Query{
    int a, b, c, d, i;
};

struct fen{
    vector<int> dp;

    fen(int n) : dp(n){}

    void update(int index){
        for(; index < dp.size(); index += (index & -index))
            dp[index] += 1;
    }

    int query(int index){
        int ans = 0;
        for(; index; index -= (index & -index))
            ans += dp[index];

        return ans;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, a, b, c, d;
    cin >> n >> q;

    vector<vector<int>> x(n, vector<int>(2));
    for(int i = 0; i < n; i++)
        cin >> x[i][0], x[i][1] = i;

    vector<int> ans(q);
    vector<Query> Q(q);
    for(int i = 0; i < q; i++){
        cin >> a >> b >> c >> d;

        Q[i] = { a, b, c, d, i };
    }

    sort(x.begin(), x.end());
    sort(Q.begin(), Q.end(), [](const Query a, const Query b){
        return a.d < b.d;
    });


    fen t1(n+1);
    for(int i = 0, index = 0; i < q; i++){
        auto [l, r, _, xr, idx] = Q[i];

        for(; (index < n) && (x[index][0] <= xr); index++)
            t1.update(x[index][1] + 1);
        
        ans[idx] = t1.rangeQuery(l, r);
    }

    sort(Q.begin(), Q.end(), [](const Query a, const Query b){
        return a.c < b.c;
    });

    fen t2(n+1);
    for(int i = 0, index = 0; i < q; i++){
        auto [l, r, xl, _, idx] = Q[i];

        for(; (index < n) && (x[index][0] <= xl-1); index++)
            t2.update(x[index][1] + 1);
        
        ans[idx] -= t2.rangeQuery(l, r);
    }

    for(int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}
