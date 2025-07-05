#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define int long long

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++)
        cin >> x[i];

    ordered_set s;
    for(int i = 0; i < n; i++)
        s.insert(i);
    

    for(int i = 0; i < n; i++){
        cin >> p;
        p--;

        auto it = *s.find_by_order(p);
        cout << x[it] << " ";
        s.erase(it);
    }
}
