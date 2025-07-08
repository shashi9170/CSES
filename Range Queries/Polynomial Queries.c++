#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6;
int tree[MAXN], lazy[MAXN], diff[MAXN];


void propagate(int ss, int se, int si){
    if(lazy[si]){
        tree[si] += (se - ss + 1) * (2 * lazy[si] + (se - ss) * diff[si]) / 2;

        int m = ss + (se - ss) / 2;
        if(ss != se){
            lazy[2*si+1] += lazy[si], 
            lazy[2*si+2] += lazy[si] + diff[si] * (m - ss + 1),
            diff[2*si+1] += diff[si],
            diff[2*si+2] += diff[si];
        }

        lazy[si] = 0, diff[si] = 0;
    }
}

void build(int ss, int se, int si, vector<int> &a){
    if(ss == se){
        tree[si] = a[ss];
        return;
    }

    int mid = (ss + se) /2;

    build(ss, mid, 2 * si + 1, a);
    build(mid + 1, se, 2 * si + 2, a);

    tree[si] = (tree[2 * si + 1] + tree[2 * si + 2]);
}


void update(int ss, int se, int si, int qs, int qe){
    propagate(ss, se, si);

    if(qe < ss || se < qs)
        return;

    if(qs <= ss && se <= qe){
        lazy[si] = (ss - qs + 1), diff[si] = 1;
        propagate(ss, se, si);
        return;
    }

    int mid = (ss + se) / 2;

    update(ss, mid, 2 * si + 1, qs, qe);
    update(mid + 1, se, 2 * si + 2, qs, qe);

    tree[si] = (tree[2 * si + 1] + tree[2 * si + 2]);
}


int query(int ss, int se, int si, int qs, int qe){
    propagate(ss, se, si);

    if(qe < ss || se < qs)
        return 0;
    
    if(qs <= ss && se <= qe)
        return tree[si];

    int mid = (ss + se) / 2;

    return query(ss, mid, 2 * si + 1, qs, qe) +
           query(mid + 1, se, 2 * si + 2, qs, qe);
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, tp, a, b;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, n-1, 0, arr);

    for(int i = 0; i < q; i++){
        cin >> tp >> a >> b;
        tp--, a--, b--;

        if(tp){
            cout << query(0, n-1, 0, a, b) << "\n";
        }
        else{
            update(0, n-1, 0, a, b);
        }
    }
}
