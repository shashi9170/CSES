#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXY = 2e5 + 5;

struct FenwickTree {
    vector<int> dp;

    FenwickTree(int n) : dp(n+1){}

    void update(int index, int val){
        for(; index < dp.size(); index += (index & -index))
            dp[index] += val;
    }

    int query(int index){
        int ans = 0;

        for(; index; index -= (index & -index))
            ans += dp[index];

        return ans;
    }

    int query(int l, int r){
        return query(r) - query(l-1);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x1, y1, x2, y2;
    cin >> n;

    vector<tuple<int, int, int>> h, v;
    set<int> y_coords;

    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1 == x2)
            v.emplace_back(x1, y1, y2), y_coords.insert(y1), y_coords.insert(y2);
        else    
            h.emplace_back(y1, x1, x2), y_coords.insert(y1);
    }


    map<int, int> coor_comp;
    int x = 1;

    for(auto y : y_coords)
        coor_comp[y] = x++;

    vector<tuple<int, int, int, int>> events;
    for(auto &[y, x1, x2]: h){
        events.emplace_back(x1, 0, coor_comp[y], -1);
        events.emplace_back(x2 + 1, 1, coor_comp[y], -1);
    }

    for(auto &[x, y1, y2]: v){
        events.emplace_back(x, 2, coor_comp[y1], coor_comp[y2]);
    }

    FenwickTree tree(MAXY);
    sort(events.begin(), events.end());

    int ans = 0;
    for(auto &[x, type, y1, y2]: events){
        if(type == 0)
            tree.update(y1, 1);
        else if(type == 1)
            tree.update(y1, -1);
        else
            ans += tree.query(y1, y2);
    }

    cout << ans << "\n";
}
