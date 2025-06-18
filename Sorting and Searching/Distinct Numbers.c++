



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
