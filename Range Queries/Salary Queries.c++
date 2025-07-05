#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define int long long

using namespace __gnu_pbds;
using namespace std;

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, k,  x, a, b;
    cin >> n >> q;

    vector<int> ar(n);
    for(int i = 0; i < n; i++)
        cin >> ar[i];

    Tree<pair<int, int>> s;
    for(int i = 0; i < n; i++)
        s.insert({ ar[i], i });

    for(int i = 0; i < q; i++){
        char ch;

        cin >> ch;

        if(ch == '!'){
            cin >> k >> x;

            s.erase({ ar[k-1], k-1 });
            ar[k-1] = x;
            s.insert({x, k-1});
        }
        else{
            cin >> a >> b;

            cout << ( s.order_of_key({ b, LLONG_MAX }) - s.order_of_key({ a - 1, LLONG_MAX }) ) << "\n";
        }
    }
}
