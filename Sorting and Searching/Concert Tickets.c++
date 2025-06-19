🔍 Key Observations
-------------------------------
1. Each ticket can only be sold once.
2. For each customer, we need to find a ticket with the highest possible price ≤ their budget.
3. After assigning a ticket, it must be removed from the available options.
4. A brute-force check for each customer would be too slow for large inputs, so we need an efficient matching mechanism.

🧠 Core Concepts Used
------------------------------
1. Efficient Search for Closest Ticket
    1.1. To serve customers quickly, we need a way to search for the best ticket that fits within a customer’s budget.
    1.2. This requires:
        1.2.1. A structure that keeps ticket prices sorted.
        1.2.2. The ability to find the closest price ≤ budget.
        1.2.3. The ability to remove that ticket once assigned.

2. Strategy for Search
    2.1. Standard sorted structures usually give access to values ≥ a given number, but here we need to find the largest value ≤ budget (also known as the floor of the budget).
    2.2. To overcome this limitation, we reverse the way we store the ticket prices. By storing prices in a certain order and using search operations cleverly, we can simulate a floor search efficiently.


⚙️ Matching Logic
--------------------------------------
Step 1: Ticket Preparation
    1.1. We start by reading all ticket prices and adding them to our sorted structure.

Step 2: Process Each Customer
    2.1. For each customer’s budget:
    2.2. We search for the ticket with the highest price ≤ budget.
    2.3. If such a ticket exists, we assign it and remove it from the pool.
    2.4 If no valid ticket is available, the customer is out of luck and receives no ticket.



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
