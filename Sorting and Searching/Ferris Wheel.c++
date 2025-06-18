🔍 Key Observations
-------------------------------------
1. A gondola can either carry one child or two children.
2. To minimize gondolas, we should pair the lightest child with the heaviest one as long as their combined weight ≤ x.
3. If two children can’t be paired, the heavier one must ride alone.
4. Once a child is placed in a gondola (alone or paired), they are no longer considered.


🧠 Core Concepts Used
---------------------------------------
1. Two-Pointer Technique
    1.1. After sorting the array of weights, use two pointers:
        1.1.1. One at the start (lightest)
        1.1.2. One at the end (heaviest)

2. Greedy Strategy
    2.1. Try to fit the lightest and heaviest child together.
    2.2. If they fit → place them in one gondola, move both pointers.
    2.3. If not → the heavier child rides alone, move the right pointer.



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
   
    int n, x;
    cin >> n >> x;

    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int i = 0, j = n-1, ans = 0;

    while(i < j){
        if(a[i] + a[j] <= x)
            ans++, i++, j--;
        else
            ans++, j--;
    }

    if(i == j)
        ans++;
    
    cout << ans << "\n";
}
