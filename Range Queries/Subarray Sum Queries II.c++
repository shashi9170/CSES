#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node{
    int p, s, t, m;
};

const int MAXN = 8e5 + 5;
Node dp[MAXN];

Node Merge(Node &a, Node &b){
    Node root;

    root.t = a.t + b.t;
    root.p = max({ a.p, a.t + b.p});
    root.s = max({ b.s, b.t + a.s });
    root.m = max({ a.s + b.p, a.m, b.m });

    return root;
}

void build(int ss, int se, int si, vector<int> &a){
    if(ss == se){
        dp[si] = { a[ss], a[ss], a[ss], max(a[ss], 0LL) };
        return;
    }

    int mid = (ss + se) / 2;
    build(ss, mid, 2 * si + 1, a);
    build(mid + 1, se, 2 * si + 2, a);

    dp[si] = Merge(dp[2*si+1], dp[2*si+2]);
}

Node query(int ss, int se, int si, int qs, int qe){
    if(qe < ss || se < qs)
        return {0, 0, 0, 0};
    
    if(qs <= ss && se <= qe)
        return dp[si];

    int mid = (ss + se) / 2;

    Node left = query(ss, mid, 2 * si + 1, qs, qe);
    Node right = query(mid + 1, se, 2 * si + 2, qs, qe);

    return Merge(left, right);
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for(int i = 0; i < n; i++)
        cin >> x[i];
    
    build(0, n-1, 0, x);

    int a, b;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        a--, b--;

        cout << query(0, n-1, 0, a, b).m << "\n";
    }
}
