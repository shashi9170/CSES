#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int power(int x, int n){
    int res = 1;

    while(n){
        if(n & 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }

    return res;
}

int MulInv(int x){
    return power(x, MOD - 2) % MOD;
}

int gauss(int n, int m, vector<vector<int>> &mat, vector<int> &ans){

    vector<int> where(m, -1);
    for(int row = 0, col = 0; row < n && col < m; ++col){
        int pivot = row;

        for(int i = row; i < n; i++){
            if(mat[i][col])
                pivot = i;
        }

        if(mat[pivot][col] == 0)
            continue;
        
        swap(mat[pivot], mat[row]);
        where[col] = row;

        int inv = MulInv(mat[row][col]);
        for(int j = col; j <= m; j++)
            mat[row][j] = (mat[row][j] * inv) % MOD;

        for(int i = 0; i < n; i++){
            if(i == row || mat[i][col] == 0)
                continue;
            
            int factor = mat[i][col];
            for(int j = col; j <= m; j++)
                mat[i][j] = (mat[i][j] - factor * mat[row][j] % MOD + MOD) % MOD;
        }
        ++row;
    }

    for(int j = 0; j < m; j++){
        if(where[j] == -1)
            continue;
        
        ans[j] = mat[where[j]][m];
    }

    
    for(int i = 0; i < n; i++){
        int sum = 0;

        for(int j = 0; j < m; j++)
            sum = (sum + ans[j] * mat[i][j]) % MOD;

        if(sum != mat[i][m])
            return 0;
    }

    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m+1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++)
            cin >> mat[i][j];
    }

    vector<int> ans(m);
    if(!gauss(n, m, mat, ans))
        cout << "-1\n";
    else{
        for(int i = 0; i < m; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
