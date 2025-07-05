#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5 + 1;
int dp[MAXN];

void update(int index, int x){
    for(; index < MAXN; index += (index & -index))
        dp[index] += x;
}

int query(int index){
    int ans = 0;

    for(; index; index -= (index & -index))
        ans += dp[index];

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, a, b;
    cin >> n >> q;

    vector<int> ar(n+1);
    for(int i = 1; i <= n; i++)
        cin >> ar[i];

    vector<vector<pair<int, int>>> qr(n+1);
    for(int i = 1; i <= q; i++){
        cin >> a >> b;

        qr[a].push_back({b, i});
    }

    map<int, int> index;
    vector<int> ans(q+1);

    for(int i = n; i; i--){
        if(index[ar[i]])
            update(index[ar[i]], -1);
        
        index[ar[i]] = i;
        update(i, 1);

        for(auto &[b, idx]: qr[i])
            ans[idx] = query(b);
    }

    for(int i = 1; i <= q; i++)
        cout << ans[i] << " \n";
}
