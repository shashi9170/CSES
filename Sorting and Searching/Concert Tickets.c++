




#include <bits/stdc++.h>
#define int long long
using namespace std;

#define vi vector<int>

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi h(n), t(m);
    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int i = 0; i < m; i++)
        cin >> t[i];

    multiset<int> st;
    for(int i = 0; i < n; i++)
        st.insert(-h[i]);

    for(int i = 0; i < m; i++){
        auto it = st.lower_bound(-t[i]);

        if(it == st.end())
            cout << "-1\n";        
        else{
            cout << -*it << "\n";
            st.erase(it);
        }
    }
}
