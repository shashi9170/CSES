#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Points {
    int x, y;
};

bool OnSegment(Points p1, Points p2, Points p) {
    return (min(p1.x, p2.x) <= p.x && p.x <= max(p1.x, p2.x) &&
            min(p1.y, p2.y) <= p.y && p.y <= max(p1.y, p2.y));
}

int Orientation(Points a, Points b, Points c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Points> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    for (int q = 0; q < m; q++) {
        Points p;
        cin >> p.x >> p.y;

        bool boundary = false;
        bool inside = false;

        int n_poly = a.size();
        bool odd = false;
        for (int i = 0, j = n_poly - 1; i < n_poly; j = i++) {
            if (Orientation(a[i], a[j], p) == 0 && OnSegment(a[i], a[j], p)) {
                boundary = true;
                break;
            }
            bool intersect = ((a[i].y > p.y) != (a[j].y > p.y)) &&
                             (p.x < (a[j].x - a[i].x) * (p.y - a[i].y) /
                                        double(a[j].y - a[i].y) + a[i].x);
            if (intersect)
                odd = !odd;
        }

        if (boundary)
            cout << "BOUNDARY\n";
        else if (odd)
            cout << "INSIDE\n";
        else
            cout << "OUTSIDE\n";
    }
}
