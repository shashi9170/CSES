#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
int timer = 0;

void dfs(int node, int parent, vector<int> adj[], vector<int> &st, vector<int> &et){
    st[node] = timer++;

    for(auto nbr: adj[node]){
        if(nbr == parent)
            continue;
        
        dfs(nbr, node, adj, st, et);
    }

    et[node] = timer;
}

struct seg{
    int n;
    vector<int> a;

    seg(int sz){
        n = sz;
        a.resize(4*n);
    }


    void build(int ss, int se, int si, vector<int> &b){
        if(ss == se){
            a[si] = b[ss];
            return;
        }

        int mid = (ss + se) / 2;

        build(ss, mid, 2 * si + 1, b);
        build(mid + 1, se, 2 * si + 2, b);

        a[si] = a[2*si+1] + a[2*si+2];
    }

    void update(int ss, int se, int si, int index, int x){
        if(index < ss || se < index)
            return;

        if(index == ss && se == ss){
            a[si] = x;
            return;
        }

        int mid = (ss + se) / 2;

        update(ss, mid, 2 * si + 1, index, x);
        update(mid + 1, se, 2 * si + 2, index, x);

        a[si] = a[2*si+1] + a[2*si+2];
    }

    int query(int ss, int se, int si, int qs, int qe){
        if(qe < ss || se < qs)
            return 0;
        
        if(qs <= ss && se <= qe)
            return a[si];

        int mid = (ss + se) / 2;

        return (
            query(ss, mid, 2 * si + 1, qs, qe) +
            query(mid + 1, se, 2 * si + 2, qs, qe)
        );
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int u, v, s, x, tp;
    vector<int> adj[n];
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> st(n), et(n), b(n);

    dfs(0, -1, adj, st, et);

    for(int i = 0; i < n; i++)
        b[st[i]] = a[i];

    seg t(n);
    t.build(0, n - 1, 0, b);

    for(int i = 0; i < q; i++){
        cin >> tp >> s;
        s--;

        if(tp == 1){
            cin >> x;
            t.update(0, n - 1, 0, st[s], x);
        }
        else{
            int ans = t.query(0, n - 1, 0, st[s], et[s]-1);

            cout << ans << "\n";
        }
    }
}
