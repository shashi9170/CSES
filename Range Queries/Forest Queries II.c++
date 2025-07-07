#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1003;
int dp[MAXN][MAXN];
int n, q;
 
void update(int i, int j, int x){
    for(; i <= n; i += (i & -i)){
        for(int k = j; k <= n; k += (k & -k))
            dp[i][k] += x;
    }
}
 
int query(int i, int j){
    int ans = 0;
 
    for(; i; i -= (i & -i)){
        for(int k = j; k; k -= (k & -k))
            ans += dp[i][k];
    }
 
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
 
    vector<string> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == '*')
                update(i+1, j+1, 1);
        }
    }
 
    for(int i = 0, t, x1, y1, x2, y2; i < q; i++){
        cin >> t;
        t--;
        if(t){
            cin >> x1 >> y1 >> x2 >> y2;
 
            cout << (query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1)) << "\n";
        }
        else{
            cin >> x1 >> y1;
 
            if(a[x1-1][y1-1] == '*')
                update(x1, y1, -1), a[x1-1][y1-1] = '.';
            else
                update(x1, y1, 1), a[x1-1][y1-1] = '*';
        }
    }
}
