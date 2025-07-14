#include<bits/stdc++.h>
#define int long long
using namespace std;

const int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int isPossible(int n, int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> dp(n, vector<int>(n, LLONG_MAX));

    queue<tuple<int, int, int>> q;
    q.push({ 0, 0, 0 });
    dp[0][0] = 0;

    while(!q.empty()){

        queue<tuple<int, int, int>> new_q;
        while(!q.empty()){
            auto [i, j, step] = q.front();
            q.pop();

            for(int k = 0; k < 8; k++){
                int nx = i + x[k];
                int ny = j + y[k];

                if(isPossible(n, nx, ny) && dp[nx][ny] > step + 1){
                    dp[nx][ny] = step + 1;
                    new_q.push({ nx, ny, dp[nx][ny] });
                }
            }
        }

        q = new_q;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
}
