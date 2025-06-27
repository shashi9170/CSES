#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> dp;

void preprocess(int N){

    for(int i = 1, s = 0; s <= 2 * N; i++){
        s += i;

        if(s > 2 * N)
            break;
        dp.push_back(s);
    }
}

 
int min_triangle_sum_count(int n){
    if(binary_search(dp.begin(), dp.end(), n))
        return 1;

    int left = 0, right = dp.size() - 1;
    while(left <= right){
        int s = dp[left] + dp[right];

        if(s == n)
            return 2;
        
        if(s > n)
            right--;
        else
            left++;
    }

    return 3;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    vector<int> a(t);
    for(int i = 0; i < t; i++){
        cin >> a[i];
    }
 
    preprocess(*max_element(a.begin(), a.end()));
 
    for(int i = 0; i < t; i++)
        cout << min_triangle_sum_count(a[i]) << "\n";
}
