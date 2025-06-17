



#include <bits/stdc++.h>
#define int long long
#define vi vector<int>

using namespace std;

const int INF = LLONG_MAX;
const int MAXN = 4 * 2 * 1e5 + 1;
vector<int> tree(MAXN);

void update(int ss, int se, int si, int index, int x){
    if(index < ss || index > se)
        return;
    
    if(ss == se){
        tree[si] = x;
        return;
    }

    int mid = (ss + se) / 2;

    if(index <= mid)
        update(ss, mid, 2 * si + 1, index, x);
    else
        update(mid + 1, se, 2 * si + 2, index, x);

    tree[si] = min(tree[2*si+1], tree[2*si+2]);
}


int query(int ss, int se, int si, int qs, int qe){
    if(qe < ss || se < qs)
        return INF;
    
    if(qs <= ss && se <= qe)
        return tree[si];
    
    int mid = (ss + se) / 2;

    int left = query(ss, mid, 2 * si + 1, qs, qe);
    int right = query(mid + 1, se, 2 * si + 2, qs, qe);

    return min(left, right);
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vi x(n);
    for(int i = 0; i < n; i++)
        cin >> x[i];

    map<int, set<int>> next_val;

    for(int i = n - 1; i >= 0; i--){
        if(next_val[x[i]].empty())
            update(0, n - 1, 0, i, INF);
        else
            update(0, n - 1, 0, i, *next_val[x[i]].begin());

        next_val[x[i]].insert(i);
    }

    while(q--) {
        int t;
        cin >> t;
        t--;

        if(t) {
            int a, b;
            cin >> a >> b;
            a--, b--;

            if(query(0, n - 1, 0, a, b) <= b)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        else {
            int k, u;
            cin >> k >> u;
            k--;

            auto it = next_val[x[k]].find(k);
            if(it != next_val[x[k]].begin()) {
                auto prv = prev(it);
                auto nxt = next(it);

                if(nxt == next_val[x[k]].end())
                    update(0, n - 1, 0, *prv, INF);
                else
                    update(0, n - 1, 0, *prv, *nxt);
            }

            next_val[x[k]].erase(it);

            x[k] = u;
            it = next_val[u].upper_bound(k);

            if(it == next_val[u].begin()) {
                if(it != next_val[u].end())
                    update(0, n - 1, 0, k, *it);
                else
                    update(0, n - 1, 0, k, INF);
            }
            else {
                update(0, n - 1, 0, k, it == next_val[u].end() ? INF : *it);
                update(0, n - 1, 0, *prev(it), k);
            }

            next_val[u].insert(k);
        }
    }
}
