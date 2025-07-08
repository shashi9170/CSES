#include <bits/stdc++.h>
#define int long long
using namespace std;


int Mex(set<int> &st){
    int s = 0;

    while(st.find(s) != st.end())
        s++;

    return s;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<int> row[n], col[n];
    vector<vector<int>> dp(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        dp[i][0] = i, 
        col[0].insert(i), row[i].insert(i);

    for(int j = 0; j < n; j++)
        dp[0][j] = j, 
        row[0].insert(j), col[j].insert(j);

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(i == j)
                row[i].insert(0), col[i].insert(0);
            else{
                set<int> new_s;
                new_s.insert(row[i].begin(), row[i].end()),
                new_s.insert(col[j].begin(), col[j].end());

                dp[i][j] = Mex(new_s);

                row[i].insert(dp[i][j]);
                col[j].insert(dp[i][j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
}
