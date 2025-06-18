🔍 Key Observations
-----------------------------------
1. We only care about unique elements, not their frequency.
2. The most efficient way to track uniqueness is by using a Set.
3. Sets automatically ignore duplicates, so inserting all elements into a set will leave only distinct values.

    
🧠 Core Concepts Used
---------------------------------
1. Set Data Structure
    1.1. In C++, std::set stores only unique elements in sorted order.
    1.2. When you insert an element:
        1.2.1. If it’s already in the set → it’s ignored.
        1.2.2. If not → it’s added.

2. Size of Set
    2.1 After inserting all elements into the set, simply use s.size() to get the total number of distinct integers.



💻 Code
------------------------

#include <bits/stdc++.h>
#define int long long
using namespace std;

#define vi vector<int>

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n;
    cin >> n;
 
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    set<int> s;
    for(int i = 0; i < n; i++)
        s.insert(a[i]);
 
    cout << s.size() << '\n';

}
