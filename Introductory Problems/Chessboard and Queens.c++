#include<bits/stdc++.h>
using namespace std;

const int N = 8;

int isPossible(int i, int j, vector<string> &a){

    for(int k = i - 1; k >= 0; k--){
        if(a[k][j] >= '0' && a[k][j] <= '7')
            return 0;
    }

    for(int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--){
        if(a[x][y] >= '0' && a[x][y] <= '7')
            return 0;
    }

    for(int x = i - 1, y = j + 1; x >= 0 && y < N; x--, y++){
        if(a[x][y] >= '0' && a[x][y] <= '7')
            return 0;
    }

    return 1;
}


int solve(int row, int k, vector<string> &a){
    if(k >= N)
        return 1;
    
    if(row >= N)
        return 0;

    int ans = 0;

    for(int col = 0; col < N; col++){
        if(a[row][col] == '*')
            continue;

        if(isPossible(row, col, a)){
            a[row][col] = char(k + '0');
            ans += solve(row + 1, k + 1, a);
            a[row][col] = '.';
        }
    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> a(N);
    for(int i = 0; i < N; i++)
        cin >> a[i];

    cout << solve(0, 0, a) << "\n";
}
