#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q, a, b, c;
    cin >> n >> m >> q;

    vector<vector<int>> mat(n+1, vector<int>(n+1, LLONG_MAX));
    for(int i = 1; i <= n; i++)
        mat[i][i] = 0;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;

        mat[a][b] = min(c, mat[a][b]);
        mat[b][a] = mat[a][b];
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){            
            for(int j = 1; j <= n; j++){
                if(mat[i][k] != LLONG_MAX && mat[k][j] != LLONG_MAX)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    for(int i = 0; i < q; i++){
        cin >> a >> b;

        cout << ( mat[a][b] == LLONG_MAX ? -1 : mat[a][b] ) << "\n";
    }
}
