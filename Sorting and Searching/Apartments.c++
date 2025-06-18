




💻 Code
------------------------

#include <bits/stdc++.h>
#define int long long
using namespace std;

#define vi vector<int>

const int MOD = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vi d(n), a(m);
    for(int i = 0; i < n; i++)
        cin >> d[i], d[i] -= k;
    for(int i = 0; i < m; i++)
        cin >> a[i];

    multiset<int> st(a.begin(), a.end());
    sort(d.begin(), d.end());

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(st.empty())
            break;
        
        auto it = st.lower_bound(d[i]);

        if(it == st.end())
            continue;
        
        if(*it <= d[i] + 2*k){
            st.erase(it);
            ans++;
        }
    }

    cout << ans << "\n";
}
