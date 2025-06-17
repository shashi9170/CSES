🔗 Problem Intuition
--------------------------
You're given an array x and multiple queries of two types:
    1. Type 2 (t=2): Check if there exists any duplicate element in the subarray [a, b].
    2. Type 1 (t=1): Modify a specific index k to a new value u.


🔍 Key Observations
----------------------------------
1. The question revolves around tracking duplicate values in a given range.
2. To detect duplicates efficiently in a subarray, we can maintain for each element its next occurrence index.
3. If there is a next occurrence of the same value within the range, it means a duplicate exists.
4. So the idea is to:
    4.1. Store the next index of occurrence for each element.
    4.2. Build a segment tree to quickly query the minimum next occurrence in a range.


🧠 Core Concepts Used
---------------------------------
1. Segment Tree
    1.1. Maintains the minimum of the next occurrence of any element for each range.
    1.2. If the minimum next occurrence ≤ b, there’s a duplicate in [a, b].
2. Map of Sets
    2.1. map<int, set<int>> next_val: For each unique value in the array, store all its occurrence indices in a sorted set.
    2.2. Enables O(log n) access to next and previous positions using upper_bound / lower_bound.


⚙️ Query Logic
-----------------------
1. ✅ Type 2 (Check range [a, b]):
    1.1. Query the segment tree for the minimum next occurrence in [a, b].
    1.2. If min ≤ b, then that next occurrence lies inside the range → duplicate exists → "NO".
    1.3. Else, all elements in the range are distinct → "YES".

2. 🔄 Type 1 (Update x[k] = u):
    2.1. Remove index k from the set of old value x[k]:
        2.1.1. If it had a previous index, update that previous one’s next to next(k) or INF if none.
    2.2. Insert index k into the set of new value u:
        2.2.1. Find its next greater index >k (if exists) and update k's next accordingly.
        2.2.2 Also, update the prev (if exists) of it to point to k.
    


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
