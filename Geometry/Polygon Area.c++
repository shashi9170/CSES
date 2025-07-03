#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Point {
    int x, y;
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Point> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    int area = 0; 
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        
        area += (a[i].x * a[j].y) - (a[i].y * a[j].x);
    }

    cout << abs(area) << "\n"; 
}
