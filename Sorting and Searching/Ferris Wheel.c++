







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
