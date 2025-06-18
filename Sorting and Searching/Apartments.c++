🔍 Key Observations
-------------------------------
1. Each applicant defines a range [desired - k, desired + k] they find acceptable.
2. An apartment is assigned to only one applicant and vice versa.
3. To maximize assignments, we should match each applicant to the smallest valid apartment available.
4. This suggests a greedy strategy, where we process applicants in order and give them the best fit.


🧠 Core Concepts Used
-----------------------------
1. Sorting
    1.1. We sort both:
        1.1.1. Applicants by their lower acceptable bound (desired - k)
        1.1.2. Apartment sizes

2. Multiset
    2.1. Apartments are stored in a multiset (self-sorting container) for efficient lower_bound() lookup.
    2.2. Allows:
        2.2.1. Fast insertion/removal
        2.2.2. Quickly finding the smallest apartment ≥ lower bound


⚙️ Matching Logic
-------------------------------
✅ Step 1: Preprocess
    1.1. For each applicant, calculate the minimum acceptable size (desired - k).
    1.2. Sort the applicant list.
    1.3. Use a multiset to store all apartments.

🔄 Step 2: Match Applicants
    2.1. For each applicant:
    2.2. Use lower_bound to find the first apartment ≥ desired - k.
    2.3. If such an apartment exists and its size ≤ desired + k → it's a valid match!
    2.4. Assign it and remove it from the set.
    2.5. Otherwise, move to the next applicant.




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
